// scorecard.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 6
#define NUM_CATEGORIES 5
#define MAX_NAME_LENGTH 50

// Candidate data
char candidates[NUM_CANDIDATES][MAX_NAME_LENGTH] = {
    "Jiyeon Park", "Ethan Smith", "Helena Silva",
    "Liam Wilson", "Noah Lee", "Sophia Zhang"
};

int candidate_ids[NUM_CANDIDATES];

// Scoring sheet: [0]=ID, [1–5]=Scores, [6]=Total
int scores[NUM_CANDIDATES][7];

// Check if a 6-digit ID already exists
int is_duplicate_id(int id) {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (candidate_ids[i] == id) return 1;
    }
    return 0;
}

// Generate unique 6-digit IDs
void generate_unique_ids() {
    srand(time(NULL));
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int id;
        do {
            id = rand() % 900000 + 100000; // Ensure 6 digits
        } while (is_duplicate_id(id));
        candidate_ids[i] = id;
    }
}

// Display all candidate scores
void display_scores() {
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Submission completed.\n");
    printf("Please review your input!\n");
    printf("------------------------------------\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d\n", candidates[i], scores[i][6]);
    }
}

// Input judge scores
void input_scores(const char *judge_name, const char *expertise) {
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int total = 0;
        printf("Candidate: %s\n", candidates[i]);
        scores[i][0] = candidate_ids[i];
        for (int j = 1; j <= NUM_CATEGORIES; j++) {
            int input;
            do {
                printf("Score %d (10-100): ", j);
                scanf("%d", &input);
                if (input < 10 || input > 100) {
                    printf("Invalid score. Re-enter.\n");
                }
            } while (input < 10 || input > 100);
            scores[i][j] = input;
            total += input;
        }
        scores[i][6] = total;
        printf("------------------------------------\n");
    }
}

// Modify score by candidate name and ID
void modify_scores() {
    char name[MAX_NAME_LENGTH];
    int id;
    while (1) {
        printf("Enter candidate name to modify (or type DONE to exit): ");
        getchar(); // clear newline
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline

        if (strcmp(name, "DONE") == 0) break;

        printf("Enter 6-digit ID: ");
        scanf("%d", &id);

        int found = 0;
        for (int i = 0; i < NUM_CANDIDATES; i++) {
            if (strcmp(candidates[i], name) == 0 && candidate_ids[i] == id) {
                found = 1;
                int total = 0;
                for (int j = 1; j <= NUM_CATEGORIES; j++) {
                    int input;
                    do {
                        printf("New Score %d (10-100): ", j);
                        scanf("%d", &input);
                        if (input < 10 || input > 100) {
                            printf("Invalid score. Re-enter.\n");
                        }
                    } while (input < 10 || input > 100);
                    scores[i][j] = input;
                    total += input;
                }
                scores[i][6] = total;
                printf("Updated successfully.\n");
                break;
            }
        }
        if (!found) {
            printf("Candidate not found. Check name and ID.\n");
        }
    }
}

// Compare function for sorting candidates
int compare_scores(const void *a, const void *b) {
    int i1 = *(int *)a;
    int i2 = *(int *)b;
    return scores[i2][6] - scores[i1][6];
}

// Final results
void display_final_selection() {
    int indexes[NUM_CANDIDATES];
    for (int i = 0; i < NUM_CANDIDATES; i++) indexes[i] = i;

    qsort(indexes, NUM_CANDIDATES, sizeof(int), compare_scores);

    printf("=======================================\n");
    printf("Compiling final selection results...\n");
    printf("=======================================\n");
    printf("###########################################\n");
    printf("# Congratulations! Welcome to Milliways!  #\n");
    printf("###########################################\n");

    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidates[indexes[i]]);
    }
}

int main() {
    generate_unique_ids();

    while (1) {
        char judge_name[MAX_NAME_LENGTH], expertise[MAX_NAME_LENGTH], submit;
        printf("####################################\n");
        printf("#     Audition Evaluation Entry    #\n");
        printf("####################################\n");
        printf("> Judge Name: ");
        getchar(); // Clear newline from buffer
        fgets(judge_name, MAX_NAME_LENGTH, stdin);
        judge_name[strcspn(judge_name, "\n")] = 0;

        printf("> Expertise: ");
        fgets(expertise, MAX_NAME_LENGTH, stdin);
        expertise[strcspn(expertise, "\n")] = 0;

        printf("++++++++++++++++++++++++++++++++++++\n");

        input_scores(judge_name, expertise);
        display_scores();

        printf("Would you like to submit? (Y/N): ");
        scanf(" %c", &submit);
        if (submit == 'Y') {
            printf("***Final submission completed.***\n");
            break;
        } else {
            modify_scores();
        }
    }

    display_final_selection();
    return 0;
}
