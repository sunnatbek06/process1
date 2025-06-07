#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 6
#define MAX_STRING 100
#define CURRENT_YEAR 2025
#define CURRENT_MONTH 5
#define CURRENT_DAY 17

typedef struct {
    char name[MAX_STRING];
    int birthYear;
    int birthMonth;
    int birthDay;
    char gender;
    char email[MAX_STRING];
    char nationality[MAX_STRING];
    float bmi;
    char primarySkill[MAX_STRING];
    char secondarySkill[MAX_STRING];
    int topik;
    char mbti[MAX_STRING];
    char introduction[MAX_STRING];
} Member;

Member candidate01, candidate02, candidate03, candidate04, candidate05, candidate06;
Member* member_info[MAX_CANDIDATES] = {
    &candidate01, &candidate02, &candidate03, &candidate04, &candidate05, &candidate06
};

// Remove trailing newline manually
void remove_newline(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

int calculateAge(int year, int month, int day) {
    int age = CURRENT_YEAR - year;
    if (CURRENT_MONTH < month || (CURRENT_MONTH == month && CURRENT_DAY < day)) {
        age--;
    }
    return age;
}

int main() {
    char groupName[MAX_STRING];
    char c;
    int i = 0;

    // Get group name with getchar()
    printf("Enter audition group name: ");
    int index = 0;
    while ((c = getchar()) != '\n' && index < MAX_STRING - 1) {
        groupName[index++] = c;
    }
    groupName[index] = '\0';

    // Clear remaining input
    if (c != '\n') while (getchar() != '\n');

    // Input section
    printf("\n####################################\n");
    printf("[%s] Audition Candidate Data Entry\n", groupName);
    printf("####################################\n");

    while (i < MAX_CANDIDATES) {
        Member* m = member_info[i];
        printf("Entering information for candidate %d.\n", i + 1);
        printf("---------------------------------\n");

        printf("1. Name: ");
        fgets(m->name, MAX_STRING, stdin);
        remove_newline(m->name);

        printf("2. Date of Birth (YYYY/MM/DD format): ");
        scanf("%d/%d/%d", &m->birthYear, &m->birthMonth, &m->birthDay);
        getchar(); // clear newline

        printf("3. Gender (F for Female, M for Male): ");
        scanf("%c", &m->gender);
        getchar(); // clear newline

        printf("4. Email: ");
        fgets(m->email, MAX_STRING, stdin);
        remove_newline(m->email);

        printf("5. Nationality: ");
        fgets(m->nationality, MAX_STRING, stdin);
        remove_newline(m->nationality);

        printf("6. BMI: ");
        scanf("%f", &m->bmi);
        getchar(); // clear newline

        printf("7. Primary Skill: ");
        fgets(m->primarySkill, MAX_STRING, stdin);
        remove_newline(m->primarySkill);

        printf("8. Secondary Skill: ");
        fgets(m->secondarySkill, MAX_STRING, stdin);
        remove_newline(m->secondarySkill);

        printf("9. Korean Proficiency Level (TOPIK): ");
        scanf("%d", &m->topik);
        getchar(); // clear newline

        printf("10. MBTI: ");
        fgets(m->mbti, MAX_STRING, stdin);
        remove_newline(m->mbti);

        printf("11. Introduction: ");
        fgets(m->introduction, MAX_STRING, stdin);
        remove_newline(m->introduction);

        printf("=================================\n");
        i++;
    }

    // Review section
    printf("\n####################################\n");
    printf("[%s] Audition Candidate Data Review \n", groupName);
    printf("####################################\n");
    printf("===========================================================================================================================\n");
    printf("Name (Age)         | DOB       | Gender | Email                 | Nationality   | BMI  | Primary Skill | Secondary Skill       | TOPIK    | MBTI |\n");
    printf("===========================================================================================================================\n");

    for (i = 0; i < MAX_CANDIDATES; i++) {
        Member* m = member_info[i];
        int age = calculateAge(m->birthYear, m->birthMonth, m->birthDay);
        printf("%-17s (%2d)| %04d%02d%02d |   %c    | %-22s| %-14s| %.1f | %-13s| %-21s| ",
               m->name, age, m->birthYear, m->birthMonth, m->birthDay,
               m->gender, m->email, m->nationality, m->bmi, m->primarySkill, m->secondarySkill);

        if (m->topik == 0)
            printf("Native   ");
        else
            printf("%-8d", m->topik);

        printf("| %-4s |\n", m->mbti);
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
        printf("%s\n", m->introduction);
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
    }

    return 0;
}
