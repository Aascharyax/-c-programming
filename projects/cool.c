#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"
#define CLEAR   "\033[2J\033[H"

void loading(const char *text)
{
    printf("%s%s", CYAN, text);
    fflush(stdout);

    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        usleep(400000);
    }

    printf("%s\n", RESET);
}

int main(void)
{
    srand(time(NULL));

    printf(CLEAR);
    printf(BOLD GREEN);
    printf("╔══════════════════════════════════╗\n");
    printf("║        N E T R U N N E R         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf(RESET);

    loading("Initializing system");
    loading("Connecting to neural network");
    loading("Bypassing firewall");

    printf("\n%sACCESS GRANTED%s\n\n", GREEN, RESET);

    printf("System ID : ");
    for (int i = 0; i < 16; i++) {
        printf("%X", rand() % 16);
    }

    printf("\nStatus    : %sONLINE%s\n", GREEN, RESET);
    printf("Core      : %sC ACTIVE%s\n", CYAN, RESET);

    printf("\n%sPress Ctrl+C to exit.%s\n", RED, RESET);

    while (1) {
        printf("%s[%02d:%02d:%02d] >> %s", GREEN,
               rand() % 24,
               rand() % 60,
               rand() % 60,
               RESET);

        const char *messages[] = {
            "scanning network...",
            "decrypting packet...",
            "analyzing process...",
            "compiling reality...",
            "allocating memory...",
            "running neural core..."
        };

        printf("%s\n", messages[rand() % 6]);
        fflush(stdout);

        sleep(1);
    }

    return 0;
}