#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

#ifdef _WIN32
    #include <windows.h>
    void sleep_seconds(int seconds) {
        Sleep(seconds * 1000);
    }
#else
    #include <unistd.h>
    void sleep_seconds(int seconds) {
        sleep(seconds);
    }
#endif

#define TRIANGLE_HEIGHT 10

void print_triangles_left_right() {
    for (int i = 0; i < TRIANGLE_HEIGHT; i++) {
        // Left triangle
        for (int j = 0; j <= i; j++) {
            printf("*");
        }

        // Padding between left and right triangle
        int padding = 100 - (2 * (i + 1));
        if (padding < 0) padding = 0;
        for (int s = 0; s < padding; s++) {
            printf(" ");
        }

        // Right inverted triangle
        for (int j = 0; j < TRIANGLE_HEIGHT - i; j++) {
            printf("*");
        }

        printf("\n");
    }
}

int main() {
    char name[100];
    char date[20];

    printf("[Please enter the current date in the \"yyyy-mm-dd\" format]: ");
    fgets(date, sizeof(date), stdin);
    printf("[Please enter your name]: ");
    fgets(name, sizeof(name), stdin);

    // Remove newline characters
    for (int i = 0; date[i]; i++) {
        if (date[i] == '\n') date[i] = '\0';
    }
    for (int i = 0; name[i]; i++) {
        if (name[i] == '\n') name[i] = '\0';
    }

    printf("**The input has been processed successfully.**\n");

    // Wait and clear screen
    sleep_seconds(3);
    system(CLEAR_COMMAND);

    // Print triangle pattern
    print_triangles_left_right();

    // Splash screen text
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("                                        [Magrathea ver 0.1]                              \n");
    printf("       Magrathea, where a shining planet is created in a wasteland with no grass,       \n");
    printf("   a place where unseen potential is discovered and gems are polished by the hands of experts,\n");
    printf("                                        Welcome to Magrathea.                            \n\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[User]: %s                                   [Execution Time]: %s\n", name, date);
    printf("=============================================================================================================\n");

    return 0;
}
