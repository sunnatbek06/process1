#include <stdio.h>
#include <math.h>

#define NUM_CATEGORIES 9
#define MAX_MEMBERS 10

// Enum for categories
enum Category {
    PHYSICAL_STRENGTH, KNOWLEDGE, SELF_MANAGEMENT, TEAMWORK,
    KOREAN_LANGUAGE, VOCAL, DANCE, VISUAL, ACTING
};

// Category names
const char* get_category_name(enum Category c) {
    switch (c) {
        case PHYSICAL_STRENGTH: return "Physical Strength";
        case KNOWLEDGE: return "Knowledge";
        case SELF_MANAGEMENT: return "Self-Management";
        case TEAMWORK: return "Teamwork";
        case KOREAN_LANGUAGE: return "Korean Language";
        case VOCAL: return "Vocal";
        case DANCE: return "Dance";
        case VISUAL: return "Visual";
        case ACTING: return "Acting";
        default: return "Unknown";
    }
}

int main() {
    int member_count, min_score, auto_debut_score;
    int scores_arr[MAX_MEMBERS][NUM_CATEGORIES];
    int i, j;

    printf("👥 Enter number of members (max %d): ", MAX_MEMBERS);
    scanf("%d", &member_count);

    if (member_count < 1 || member_count > MAX_MEMBERS) {
        printf("❌ Invalid member count.\n");
        return 1;
    }

    printf("📉 Enter minimum individual score (0-11 scale): ");
    scanf("%d", &min_score);

    printf("🏆 Enter auto-debut score threshold (95-100): ");
    scanf("%d", &auto_debut_score);

    int total_category_scores[NUM_CATEGORIES] = {0}; // For averaging
    int failed = 0;

    // Input scores
    for (i = 0; i < member_count; i++) {
        printf("\n🎤 Enter scores for member %d:\n", i + 1);
        for (j = 0; j < NUM_CATEGORIES; j++) {
            printf("- %s (0-11): ", get_category_name(j));
            scanf("%d", &scores_arr[i][j]);

            if (scores_arr[i][j] < min_score) {
                printf("⚠️ Minimum required score is %d.\n", min_score);
                printf("🔁 All members must retake the '%s' category.\n", get_category_name(j));
                return 0;
            }

            total_category_scores[j] += scores_arr[i][j];
        }
    }

    // Calculate average team score for each category (truncate) and total score
    int total_score = 0;
    for (j = 0; j < NUM_CATEGORIES; j++) {
        int avg = total_category_scores[j] / member_count;
        total_score += avg;
    }

    printf("\n📊 Total team score (truncated): %d / 100\n", total_score);

    // Bonus logic
    if (total_score >= auto_debut_score) {
        printf("🎉 Congratulations! Your stage debut is confirmed!\n");
    } else if (total_score >= 90) {
        printf("📋 The Debut Certification Team will hold a final evaluation meeting to make a decision.\n");
    } else if (total_score >= 80) {
        // Find 3 lowest scoring categories
        int avg_arr[NUM_CATEGORIES];
        for (j = 0; j < NUM_CATEGORIES; j++) {
            avg_arr[j] = total_category_scores[j] / member_count;
        }

        // Find indexes of 3 lowest values
        int min1 = 0, min2 = 1, min3 = 2;
        if (avg_arr[min2] < avg_arr[min1]) { int t = min1; min1 = min2; min2 = t; }
        if (avg_arr[min3] < avg_arr[min1]) { int t = min1; min1 = min3; min3 = t; }
        if (avg_arr[min3] < avg_arr[min2]) { int t = min2; min2 = min3; min3 = t; }

        for (j = 3; j < NUM_CATEGORIES; j++) {
            if (avg_arr[j] < avg_arr[min1]) {
                min3 = min2; min2 = min1; min1 = j;
            } else if (avg_arr[j] < avg_arr[min2]) {
                min3 = min2; min2 = j;
            } else if (avg_arr[j] < avg_arr[min3]) {
                min3 = j;
            }
        }

        printf("🔁 Retake the three lowest-scoring categories (%s, %s, %s) after 30 days.\n",
               get_category_name(min1),
               get_category_name(min2),
               get_category_name(min3));
    } else {
        printf("❌ Score too low. Team must restart certification process.\n");
    }

    return 0;
}
