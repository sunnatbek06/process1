#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_CANDIDATES 6
#define NUM_FINALISTS 4
#define MAX_LEN 100

// 합격자 구조체 정의
typedef struct {
    char name[MAX_LEN];
    int id;
    char passed[MAX_LEN];
} Candidate;

typedef struct {
    char name[MAX_LEN];
    int id;
    char nickname[MAX_LEN];
    char education[MAX_LEN];
    float height; // in meters
    float weight; // calculated from BMI
    char blood[MAX_LEN];
    char allergy[MAX_LEN];
    char hobby[MAX_LEN];
    char sns[MAX_LEN];
    float bmi;
} MilliwaysMember;

// BMI 상태 출력용 함수
void print_bmi_category(float bmi) {
    int category;
    if (bmi < 18.5)
        category = 1;
    else if (bmi < 23.0)
        category = 2;
    else if (bmi < 25.0)
        category = 3;
    else
        category = 4;

    switch (category) {
        case 1:
            printf("BMI 상태: 저체중\n");
            break;
        case 2:
            printf("BMI 상태: 정상\n");
            break;
        case 3:
            printf("BMI 상태: 과체중\n");
            break;
        case 4:
            printf("BMI 상태: 비만\n");
            break;
        default:
            printf("BMI 상태: 알 수 없음\n");
    }
}

int main() {
    // 6명 후보자
    Candidate candidate_arr[NUM_CANDIDATES] = {
        {"Jiyeon Park", 123456, "pass"},
        {"Ethan Smith", 234567, "pass"},
        {"Helena Silva", 345678, "pass"},
        {"Liam Wilson", 456789, "pass"},
        {"Noah Lee", 567890, "fail"},
        {"Sophia Zhang", 678901, "fail"}
    };

    MilliwaysMember milliways_arr[NUM_FINALISTS];

    int idx = 0;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        if (strcmp(candidate_arr[i].passed, "pass") == 0) {
            printf("\n==== [%s] 인터뷰 정보 입력 ====\n", candidate_arr[i].name);
            strcpy(milliways_arr[idx].name, candidate_arr[i].name);
            milliways_arr[idx].id = candidate_arr[i].id;

            printf("닉네임: ");
            fgets(milliways_arr[idx].nickname, MAX_LEN, stdin);
            milliways_arr[idx].nickname[strcspn(milliways_arr[idx].nickname, "\n")] = 0;

            printf("학력: ");
            fgets(milliways_arr[idx].education, MAX_LEN, stdin);
            milliways_arr[idx].education[strcspn(milliways_arr[idx].education, "\n")] = 0;

            printf("키 (m 단위): ");
            scanf("%f", &milliways_arr[idx].height);
            getchar(); // 버퍼 클리어

            printf("BMI 값 입력: ");
            scanf("%f", &milliways_arr[idx].bmi);
            getchar(); // 버퍼 클리어

            // 몸무게 계산: weight = BMI * (height^2)
            milliways_arr[idx].weight = milliways_arr[idx].bmi * milliways_arr[idx].height * milliways_arr[idx].height;

            printf("혈액형: ");
            fgets(milliways_arr[idx].blood, MAX_LEN, stdin);
            milliways_arr[idx].blood[strcspn(milliways_arr[idx].blood, "\n")] = 0;

            printf("알러지: ");
            fgets(milliways_arr[idx].allergy, MAX_LEN, stdin);
            milliways_arr[idx].allergy[strcspn(milliways_arr[idx].allergy, "\n")] = 0;

            printf("취미: ");
            fgets(milliways_arr[idx].hobby, MAX_LEN, stdin);
            milliways_arr[idx].hobby[strcspn(milliways_arr[idx].hobby, "\n")] = 0;

            printf("SNS 정보: ");
            fgets(milliways_arr[idx].sns, MAX_LEN, stdin);
            milliways_arr[idx].sns[strcspn(milliways_arr[idx].sns, "\n")] = 0;

            idx++;
        }
    }

    // 출력
    printf("\n=====================================\n");
    printf("     밀리웨이즈 정규 멤버 리스트     \n");
    printf("=====================================\n");

    for (int i = 0; i < NUM_FINALISTS; i++) {
        printf("\n[%d] %s (ID: %d)\n", i + 1, milliways_arr[i].name, milliways_arr[i].id);
        printf("닉네임: %s\n", milliways_arr[i].nickname);
        printf("학력: %s\n", milliways_arr[i].education);
        printf("키: %.2fm\n", milliways_arr[i].height);
        printf("BMI: %.1f\n", milliways_arr[i].bmi);
        printf("계산된 몸무게: %.1fkg\n", milliways_arr[i].weight);
        print_bmi_category(milliways_arr[i].bmi);
        printf("혈액형: %s\n", milliways_arr[i].blood);
        printf("알러지: %s\n", milliways_arr[i].allergy);
        printf("취미: %s\n", milliways_arr[i].hobby);
        printf("SNS: %s\n", milliways_arr[i].sns);
        printf("-------------------------------------\n");
    }

    return 0;
}
