#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CATEGORIES 9
#define MAX_EXAMS 9
#define ROOM_COUNT 10

// Training categories
const char categories_arr[NUM_CATEGORIES][20] = {
    "Physical Strength", "Knowledge", "Self-Management", "Teamwork",
    "Korean Language", "Vocal", "Dance", "Visual", "Acting"
};

// Store exam dates and selection status
int exam_dates_arr[NUM_CATEGORIES] = {0};
int selected_arr[NUM_CATEGORIES] = {0};

// Utility: Convert YYYYMMDD to days since epoch (simple approx.)
int date_to_days(int yyyymmdd) {
    int y = yyyymmdd / 10000;
    int m = (yyyymmdd % 10000) / 100;
    int d = yyyymmdd % 100;
    return y * 365 + m * 30 + d;
}

// Utility: Check if a category can be scheduled
int is_eligible(int idx) {
    // Required order
    if (idx == 2 || idx == 3) {
        // Self-Management, Teamwork — after Phys + Know
        return selected_arr[0] && selected_arr[1];
    }
    if (idx >= 4) {
        return selected_arr[0] && selected_arr[1] && selected_arr[2] && selected_arr[3];
    }
    return 1; // Phys and Know can be scheduled anytime after 30 days
}

// Show reminder
void check_reminders(int today) {
    int today_days = date_to_days(today);
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        if (exam_dates_arr[i] != 0) {
            int diff = date_to_days(exam_dates_arr[i]) - today_days;
            if (diff >= 0 && diff <= 10) {
                printf("🔔 Reminder: '%s' exam is in %d days (on %d)\n", categories_arr[i], diff, exam_dates_arr[i]);
            }
        }
    }
}

// Assign exam room if today is exam day
void assign_exam_room(int today) {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        if (exam_dates_arr[i] == today) {
            srand(time(NULL) + i); // Add index to vary per loop
            int room = rand() % ROOM_COUNT + 1;
            printf("🏫 '%s' exam is today! Assigned to Room #%d\n", categories_arr[i], room);
        }
    }
}

int main() {
    int start_date;
    int today;
    int choice, exam_date;

    printf("📅 Enter the training start date (YYYYMMDD): ");
    scanf("%d", &start_date);

    printf("📆 Enter today’s date (YYYYMMDD): ");
    scanf("%d", &today);

    // Bonus features
    check_reminders(today);
    assign_exam_room(today);

    while (1) {
        printf("\n🏁 Certification Categories:\n");
        for (int i = 0; i < NUM_CATEGORIES; i++) {
            printf("%d. %s%s\n", i + 1, categories_arr[i], selected_arr[i] ? " ✅" : "");
        }

        printf("Select a category to schedule an exam (0 to quit): ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice < 1 || choice > NUM_CATEGORIES) {
            printf("❌ Invalid choice.\n");
            continue;
        }

        int index = choice - 1;

        if (selected_arr[index]) {
            printf("⚠️ Exam already scheduled for '%s'.\n", categories_arr[index]);
            continue;
        }

        if (!is_eligible(index)) {
            printf("⛔ You must pass required certifications first.\n");
            continue;
        }

        printf("📅 Enter exam date for '%s' (YYYYMMDD): ", categories_arr[index]);
        scanf("%d", &exam_date);

        int start_days = date_to_days(start_date);
        int exam_days = date_to_days(exam_date);
        int gap = exam_days - start_days;

        if (gap < 30 || gap > 100) {
            printf("❗ Exam must be between 30 and 100 days after training start.\n");
            continue;
        }

        // Store valid exam
        exam_dates_arr[index] = exam_date;
        selected_arr[index] = 1;

        printf("✅ Exam for '%s' scheduled on %d.\n", categories_arr[index], exam_date);
    }

    printf("\n📘 Final Exam Schedule:\n");
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        if (selected_arr[i]) {
            printf("- %s: %d\n", categories_arr[i], exam_dates_arr[i]);
        }
    }

    return 0;
}
