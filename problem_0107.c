#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 3
#define MAX_MESSAGES 5
#define MSG_LEN 100

// Immutable candidate info (unsuccessful)
const char memorial01_arr[MAX_CANDIDATES][100] = {
    "Alice,22,F,milliways,alice@example.com",
    "Bob,24,M,milliways,bob@example.com",
    "Clara,21,F,milliways,clara@example.com"
};

// Rolling paper message storage
char rollingpp01_arr[MAX_MESSAGES][MSG_LEN] = {
    "{\"Youngjin\": \"Alice, you were amazing!\"}",
    "{\"Woncheol\": \"Bob, your moves were unforgettable.\"}",
    "{\"Youngjin\": \"Clara, your spirit was bright!\"}"
};

// Extract candidate name from memorial##_arr
void extract_name(const char* data, char* name_out) {
    int i = 0;
    while (data[i] != ',' && data[i] != '\0') {
        name_out[i] = data[i];
        i++;
    }
    name_out[i] = '\0';
}

// Show messages addressed to selected candidate
void show_messages(const char* candidate_name) {
    int found = 0;
    printf("\n📨 Rolling Paper Messages for %s:\n", candidate_name);
    for (int i = 0; i < MAX_MESSAGES; i++) {
        if (strstr(rollingpp01_arr[i], candidate_name) != NULL) {
            printf("- %s\n", rollingpp01_arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No messages found.\n");
    }
}

// Send a new rolling message
void send_message(const char* recipient_name) {
    char sender[30];
    char message[60];
    int slot = -1;

    // Find available message slot
    for (int i = 0; i < MAX_MESSAGES; i++) {
        if (strlen(rollingpp01_arr[i]) == 0) {
            slot = i;
            break;
        }
    }

    if (slot == -1) {
        printf("Message storage is full!\n");
        return;
    }

    printf("\nEnter your name: ");
    scanf("%s", sender);
    printf("Enter your message to %s: ", recipient_name);
    getchar(); // clear newline
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    snprintf(rollingpp01_arr[slot], MSG_LEN, "{\"%s\": \"%s, %s\"}", sender, recipient_name, message);
    printf("✅ Message recorded!\n");
}

// Simulate sending email
void simulate_email(const char* email, const char* recipient_name) {
    char option;
    printf("\nDo you want to send an email to %s? (y/n): ", recipient_name);
    scanf(" %c", &option);
    if (option == 'y' || option == 'Y') {
        printf("📧 Email has been sent to %s (%s)!\n", recipient_name, email);
    } else {
        printf("❌ Email not sent.\n");
    }
}

int main() {
    char input_name[20];
    char candidate_name[20];
    char email[40];
    int found = 0;

    printf("Enter name of an unsuccessful candidate: ");
    scanf("%s", input_name);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        extract_name(memorial01_arr[i], candidate_name);
        if (strcmp(candidate_name, input_name) == 0) {
            found = 1;
            // Extract email
            int comma_count = 0, j = 0;
            for (int k = 0; memorial01_arr[i][k] != '\0'; k++) {
                if (memorial01_arr[i][k] == ',') {
                    comma_count++;
                } else if (comma_count == 4) {
                    email[j++] = memorial01_arr[i][k];
                }
            }
            email[j] = '\0';

            show_messages(candidate_name);
            send_message(candidate_name);
            simulate_email(email, candidate_name);
            break;
        }
    }

    if (!found) {
        printf("❗ Candidate not found in memorial list.\n");
    }

    return 0;
}
