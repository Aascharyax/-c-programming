#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define START_YEAR 2080
#define END_YEAR   2090
#define MONTHS     12

#define COLOR_HIGHLIGHT "\033[7m"     /* Highlight today */
#define COLOR_HOLIDAY   "\033[1;31m"  /* Red for Saturdays & Holidays */
#define COLOR_RESET     "\033[0m"

typedef struct {
    int year;
    int month;
    int day;
    const char *name;
} Holiday;

static const Holiday holiday_list[] = {
    {2083, 1, 1, "Naya Barsa (Nepali New Year)"},
    {2083, 1, 18, "Buddha Jayanti / Labour Day"},
    {2083, 2, 15, "Ganatantra Diwas (Republic Day)"},
    {2083, 5, 12, "Janai Purnima / Rakshya Bandhan"},
    {2083, 5, 19, "Krishna Janmashtami / Gaura Parva"},
    {2083, 5, 29, "Teej (Haritalika)"},
    {2083, 6, 3, "Sambidhan Diwas (Constitution Day)"},
    {2083, 6, 25, "Dashain (Ghatasthapana)"},
    {2083, 6, 31, "Dashain (Phulpati)"},
    {2083, 7, 1, "Dashain (Maha Ashtami)"},
    {2083, 7, 2, "Dashain (Maha Navami)"},
    {2083, 7, 3, "Dashain (Vijaya Dashami)"},
    {2083, 7, 22, "Laxmi Puja (Tihar)"},
    {2083, 7, 23, "Gobardhan Puja / Mha Puja"},
    {2083, 7, 24, "Bhai Tika"},
    {2083, 7, 29, "Chhath Parva"}
};

static const int TOTAL_HOLIDAYS = sizeof(holiday_list) / sizeof(holiday_list[0]);

static const char *months[MONTHS] = {
    "Baisakh", "Jestha", "Ashadh", "Shrawan",
    "Bhadra", "Ashwin", "Kartik", "Mangsir",
    "Poush", "Magh", "Falgun", "Chaitra"
};

static const char *weekdays_short[] = {
    "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"
};

/* Official days per month for 2080-2090 */
static const int days[END_YEAR - START_YEAR + 1][MONTHS] = {
    {31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2080 */
    {31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2081 */
    {31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2082 */
    {31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2083 */
    {31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2084 */
    {31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2085 */
    {31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2086 */
    {31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2087 */
    {31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2088 */
    {31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 30}, /* 2089 */
    {31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 30}  /* 2090 */
};

/* Anchor: Aug 17, 2026 = Bhadra 1, 2083 (Monday = 1) */
#define REF_GY       2026
#define REF_GM       8
#define REF_GD       17
#define REF_BS_YEAR  2083
#define REF_BS_MONTH 5
#define REF_BS_DAY   1
#define REF_WDAY     1

static long gregorian_to_jdn(int y, int m, int d) {
    if (m <= 2) {
        y -= 1;
        m += 12;
    }
    long a = y / 100;
    long b = a / 4;
    long c = 2 - a + b;
    long e = (long)(365.25 * (y + 4716));
    long f = (long)(30.6001 * (m + 1));
    return c + d + e + f - 1524;
}

static int get_weekday_from_jdn(long jdn) {
    long ref_jdn = gregorian_to_jdn(REF_GY, REF_GM, REF_GD);
    long diff = jdn - ref_jdn;
    return (int)((REF_WDAY + (diff % 7) + 7) % 7);
}

static int date_to_bs(int gy, int gm, int gd, int *by, int *bm, int *bd) {
    long target_jdn = gregorian_to_jdn(gy, gm, gd);
    long ref_jdn = gregorian_to_jdn(REF_GY, REF_GM, REF_GD);
    long diff = target_jdn - ref_jdn;

    int cur_y = REF_BS_YEAR;
    int cur_m = REF_BS_MONTH - 1;
    int cur_d = REF_BS_DAY;

    if (diff >= 0) {
        while (diff > 0) {
            int days_in_month = days[cur_y - START_YEAR][cur_m];
            if (cur_d + diff <= days_in_month) {
                cur_d += diff;
                diff = 0;
            } else {
                diff -= (days_in_month - cur_d + 1);
                cur_d = 1;
                cur_m++;
                if (cur_m >= 12) {
                    cur_m = 0;
                    cur_y++;
                }
            }
        }
    } else {
        diff = -diff;
        while (diff > 0) {
            if (cur_d - diff >= 1) {
                cur_d -= diff;
                diff = 0;
            } else {
                diff -= cur_d;
                cur_m--;
                if (cur_m < 0) {
                    cur_m = 11;
                    cur_y--;
                }
                cur_d = days[cur_y - START_YEAR][cur_m];
            }
        }
    }

    *by = cur_y;
    *bm = cur_m + 1;
    *bd = cur_d;
    return 1;
}

static int get_bs_first_weekday(int year, int month) {
    long ref_jdn = gregorian_to_jdn(REF_GY, REF_GM, REF_GD);
    long days_offset = 0;

    int y = REF_BS_YEAR;
    int m = REF_BS_MONTH - 1;

    if (year > y || (year == y && month >= m + 1)) {
        while (y < year || m < month - 1) {
            days_offset += days[y - START_YEAR][m];
            m++;
            if (m >= 12) {
                m = 0;
                y++;
            }
        }
        return get_weekday_from_jdn(ref_jdn + days_offset);
    } else {
        while (y > year || m > month - 1) {
            m--;
            if (m < 0) {
                m = 11;
                y--;
            }
            days_offset += days[y - START_YEAR][m];
        }
        return get_weekday_from_jdn(ref_jdn - days_offset);
    }
}

static const char* get_holiday_name(int year, int month, int day) {
    for (int i = 0; i < TOTAL_HOLIDAYS; i++) {
        if (holiday_list[i].year == year && holiday_list[i].month == month && holiday_list[i].day == day) {
            return holiday_list[i].name;
        }
    }
    return NULL;
}

/* Horizontal matrix layout (ncal style) */
static void print_ncal_month(int year, int month, int highlight_day) {
    int first_wday = get_bs_first_weekday(year, month);
    int total_days = days[year - START_YEAR][month - 1];

    printf("    %s %d\n", months[month - 1], year);

    // Build day matrix [week_index 0..5][weekday 0..6]
    int grid[6][7] = {0};
    int week = 0;
    int wday = first_wday;

    for (int d = 1; d <= total_days; d++) {
        grid[week][wday] = d;
        wday++;
        if (wday > 6) {
            wday = 0;
            week++;
        }
    }

    int total_weeks = (wday == 0) ? week : week + 1;

    // Print rows (weekdays Su-Sa)
    for (int w = 0; w < 7; w++) {
        printf("%s ", weekdays_short[w]);
        for (int wk = 0; wk < total_weeks; wk++) {
            int d = grid[wk][w];
            if (d == 0) {
                printf("   ");
            } else {
                int is_hol = (get_holiday_name(year, month, d) != NULL);
                if (d == highlight_day) {
                    printf("%s%2d%s ", COLOR_HIGHLIGHT, d, COLOR_RESET);
                } else if (is_hol || w == 6) {
                    printf("%s%2d%s ", COLOR_HOLIDAY, d, COLOR_RESET);
                } else {
                    printf("%2d ", d);
                }
            }
        }
        printf("\n");
    }

    /* Print holidays */
    int found_holidays = 0;
    for (int d = 1; d <= total_days; d++) {
        const char *h_name = get_holiday_name(year, month, d);
        if (h_name) {
            if (!found_holidays) {
                printf("\nHolidays:\n");
                found_holidays = 1;
            }
            printf("  %s%2d%s: %s\n", COLOR_HOLIDAY, d, COLOR_RESET, h_name);
        }
    }
}

int main(int argc, char **argv) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    int cur_gy = local->tm_year + 1900;
    int cur_gm = local->tm_mon + 1;
    int cur_gd = local->tm_mday;

    int cur_by, cur_bm, cur_bd;
    date_to_bs(cur_gy, cur_gm, cur_gd, &cur_by, &cur_bm, &cur_bd);

    if (argc == 1) {
        print_ncal_month(cur_by, cur_bm, cur_bd);
        return 0;
    }

    int year = atoi(argv[1]);
    if (year < START_YEAR || year > END_YEAR) {
        fprintf(stderr, "Year must be between %d and %d.\n", START_YEAR, END_YEAR);
        return 1;
    }

    if (argc == 2) {
        for (int m = 1; m <= MONTHS; m++) {
            int hl = (cur_by == year && cur_bm == m) ? cur_bd : -1;
            print_ncal_month(year, m, hl);
            printf("\n");
        }
        return 0;
    }

    if (argc == 3) {
        int month = atoi(argv[2]);
        if (month < 1 || month > 12) {
            fprintf(stderr, "Month must be between 1 and 12.\n");
            return 1;
        }
        int hl = (cur_by == year && cur_bm == month) ? cur_bd : -1;
        print_ncal_month(year, month, hl);
        return 0;
    }

    return 0;
}