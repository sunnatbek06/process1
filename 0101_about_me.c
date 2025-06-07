#include <stdio.h>

void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
}

void print_intro(char* intro) {
    printf("Introduction | ");
    int start_line = 1;
    for (int i = 0; intro[i] != '\0'; i++) {
        printf("%c", intro[i]);
        if (intro[i] == '.' && intro[i + 1] != '\0') {
            printf(" \n");
            printf("              ");
        }
    }
    printf("\n");
}

void print_separator() {
    printf("=====================================================================\n");
}

int main() {
    printf("[Magrathea] \u2665\u2665 Project Member Introduction \u2665\u2665\n");
    print_separator();

    // Arthur Dent
    printf("Name         | %-25s\tGender     | %-10s\n", "Arthur Dent", "Male");
    printf("Major        | %-25s\tExperience | ", "Mechanical Engineering");
    print_binary(15); printf("(2) years\n");
    printf("Role         | %-25s\tSkills     | %s\n", "Architect", "C/C++, Java, Spring, Python, Machine Learning/Deep Learning");
    printf("---------------------------------------------------------------------\n");
    print_intro("I built my career working on various projects in SNS, fintech, HR, and media in Silicon Valley. Through successes and failures, I have gained insights I want to share with you.");
    print_separator();

    // Kim Youngjin
    printf("Name         | %-25s\tGender     | %-10s\n", "Kim Youngjin", "Male");
    printf("Major        | %-25s\tExperience | ", "Computer Engineering");
    print_binary(2); printf("(2) years\n");
    printf("Role         | %-25s\tSkills     | %s\n", "Developer", "C#, Python, JavaScript, React, Kotlin");
    printf("---------------------------------------------------------------------\n");
    print_intro("Recently, I found immense passion for software development through a personal asset management project using the MAUI framework. Solving real-world problems with my code is incredible! Successfully developing Magrathea has now become one of my bucket list goals.");
    print_separator();

    // Im Woncheol
    printf("Name         | %-25s\tGender     | %-10s\n", "Im Woncheol", "Male");
    printf("Major        | %-25s\tExperience | ", "Electronic Engineering");
    print_binary(1); printf("(2) years\n");
    printf("Role         | %-25s\tSkills     | %s\n", "DBA", "Java, PHP, MongoDB, MS SQL, MySQL");
    printf("---------------------------------------------------------------------\n");
    print_intro("I believe that applications are ultimately about how they handle data. While studying Big Data courses in university, I developed a deep interest in data platforms. I think the success of this project depends on data. Just thinking about the data we’ll manage in Magrathea already excites me!");
    print_separator();

    // Yoo Goeun
    printf("Name         | %-25s\tGender     | %-10s\n", "Yoo Goeun", "Female");
    printf("Major        | %-25s\tExperience | ", "Management Information Systems");
    print_binary(1); printf("(2) years\n");
    printf("Role         | %-25s\tSkills     | %s\n", "Cloud Engineer", "Java, PowerShell, Azure, AWS, GCP");
    printf("---------------------------------------------------------------------\n");
    print_intro("I worked on a project with Kim Youngjin, where I was responsible for implementing cloud architecture. During my school years, I became fascinated with cloud computing, particularly Microsoft Azure. As I delved deeper, I found that understanding other public cloud platforms became much easier. I am determined to complete Magrathea's cloud architecture with my own hands!");
    print_separator();

    // Seo Hyekyung
    printf("Name         | %-25s\tGender     | %-10s\n", "Seo Hyekyung", "Female");
    printf("Major        | %-25s\tExperience | ", "Political Science & International Relations");
    print_binary(0); printf("(2) years\n");
    printf("Role         | %-25s\tSkills     | %s\n", "Developer", "Python, Swift, Kotlin, Node.js, Figma");
    printf("---------------------------------------------------------------------\n");
    print_intro("While I have worked on many projects as academic assignments, this is my first real-world project where a company's success is at stake. I am both excited and nervous about whether I can perform well. When I first heard about the Magrathea project, something inside me told me that this was a project worth dedicating myself to. Having already heard of Arthur’s reputation through LinkedIn, I feel honored to be part of this journey.");
    print_separator();

    return 0;
}
