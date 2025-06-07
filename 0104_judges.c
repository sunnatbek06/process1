#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 100
#define MAX_INFO_LENGTH 512
#define EXPECTED_FIELDS 7

char judges_array[MAX_JUDGES][MAX_INFO_LENGTH];

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int count_fields(const char *str) {
    int count = 1; // Start with 1 because first item doesn't have comma before
    const char *p = str;
    while (*p) {
        if (*p == ',') {
            count++;
        }
        p++;
    }
    return count;
}

void parse_and_display_judge_info(const char *info_str, int judge_index) {
    char temp[MAX_INFO_LENGTH];
    strncpy(temp, info_str, MAX_INFO_LENGTH - 1);
    temp[MAX_INFO_LENGTH - 1] = '\0';

    char *token;
    int field = 0;

    const char *labels[] = {
        "Name", "Gender", "Affiliation", "Title",
        "Expertise", "Email", "Phone"
    };

    printf("[Judge %d]\n", judge_index + 1);
    token = strtok(temp, ",");

    while (token != NULL && field < EXPECTED_FIELDS) {
        while (*token == ' ') token++; // Trim leading space
        printf("%s: %s\n", labels[field], token);
        token = strtok(NULL, ",");
        field++;
    }
    printf("-----------------------------------\n");
}

int main() {
    char project_name[100];
    int total_judges;
    int selected_members = 4;

    printf("####################################\n");
    printf("#      Judge List Data Entry      #\n");
    printf("####################################\n");

    printf("Participating Project: ");
    fgets(project_name, sizeof(project_name), stdin);
    trim_newline(project_name);

    printf("Total Number of Judges: ");
    scanf("%d", &total_judges);
    getchar(); // Remove leftover newline

    printf("Number of Selected Members: %d\n", selected_members);
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Starting to input information for %d judges.\n", total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    int count = 0;
    while (count < total_judges) {
        printf("Judge %d: ", count + 1);
        fgets(judges_array[count], MAX_INFO_LENGTH, stdin);
        trim_newline(judges_array[count]);

        if (count_fields(judges_array[count]) != EXPECTED_FIELDS) {
            printf("The input items are incorrect. Please enter them again.\n");
            continue;
        }

        count++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Judge information entry is complete.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;
    printf("\"Should we check the judge information?\" ");
    scanf(" %c", &confirm);

    if (confirm == 'Y') {
        printf("%s Should we check the judge information? %c\n", project_name, confirm);
        printf("####################################\n");
        printf("#        Display Judge Data        #\n");
        printf("####################################\n");

        for (int i = 0; i < total_judges; i++) {
            parse_and_display_judge_info(judges_array[i], i);
        }
    } else {
        printf("Program terminated.\n");
    }

    return 0;
}
