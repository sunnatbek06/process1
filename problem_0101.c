#include <stdio.h>

// Function to convert years of experience into a 4-byte binary string
void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Add space every 8 bits for readability
    }
}

// Function to print the introduction with proper line wrapping and formatting
void print_intro(char* intro) {
    printf("Introduction | ");
    int start_line = 1;
    for (int i = 0; intro[i] != '\0'; i++) {
        printf("%c", intro[i]);
        if (intro[i] == '.' && intro[i + 1] != '\0') {
            printf(" \n");
            if (start_line) {
                printf("              ");
                start_line = 0;
            } else {
                printf("              ");
            }
        }
    }
    printf("\n");
}

void print_separator() {
    printf("=====================================================================\n");
}

int main() {
    // Start output
    printf("[Magrathea] \u2665\u2665 Project Member Introduction ♥♥\n");
    print_separator();

    // Arthur Dent
    printf("Name         | %-25s Gender     | %-10s\n", "Arthur Dent", "Male");
    printf("Major        | %-25s Experience | %d years\n", "Mechanical Engineering", 15);
    printf("Role         | %-25s Skills | %s\n", "Architect", "C/C++, Java, Spring, Python, Machine Learning/Deep Learning");
    printf("---------------------------------------------------------------------\n");
    print_intro("I built my career working on various projects in SNS, fintech, HR, and media in Silicon Valley. Through successes and failures, I have gained insights I want to share with you.");
    print_separator();

    // Kim Young-jin
    printf("Name         | %-25s Gender     | %-10s\n", "Kim Youngjin", "Male");
    printf("Major        | %-25s Experience | %d years\n", "Computer Science", 2);
    printf("Role         | %-25s Skills | %s\n", "Developer", "C#, Python, JavaScript, React, Kotlin");
    printf("---------------------------------------------------------------------\n");
    print_intro("Recently, I developed a passion for software development while working on a personal asset management project using the MAUI framework. Solving real-world problems with my code is exciting! Successfully developing Magrathea is now one of my bucket list goals.");
    print_separator();

    // Lim Won-cheol
    printf("Name         | %-25s Gender     | %-10s\n", "Lim Woncheol", "Male");
    printf("Major        | %-25s Experience | %d year\n", "Electronics Engineering", 1);
    printf("Role         | %-25s Skills | %s\n", "DBA", "Java, PHP, MongoDB, MS SQL, MySQL");
    printf("---------------------------------------------------------------------\n");
    print_intro("I believe applications are ultimately about handling data. I developed a strong interest in data platforms while studying a Big Data course in university. The success of this project depends on data, and I’m already excited about working with the data in Magrathea.");
    print_separator();

    // Yoo Go-eun
    printf("Name         | %-25s Gender     | %-10s\n", "Yoo Goeun", "Female");
    printf("Major        | %-25s Experience | %d year\n", "Management Information Systems", 1);
    printf("Role         | %-25s Skills | %s\n", "Cloud Engineer", "Java, PowerShell, Azure, AWS, GCP");
    printf("---------------------------------------------------------------------\n");
    print_intro("Worked on a project with Kim Youngjin, handling cloud architecture implementation. My passion for cloud computing started in college with Microsoft Azure, and through in-depth learning, I found that understanding other public cloud platforms became easier. I am determined to complete Magrathea’s cloud architecture with my own hands.");
    print_separator();

    // Seo Hye-kyung
    printf("Name         | %-25s Gender     | %-10s\n", "Seo Hyekyung", "Female");
    printf("Major        | %-25s Experience | %d years\n", "Political Science", 0);
    printf("Role         | %-25s Skills | %s\n", "Developer", "Python, Swift, Kotlin, Node.js, Figma");
    printf("---------------------------------------------------------------------\n");
    print_intro("Although I have worked on many projects as assignments in university, this is my first real-world project where a company’s success is at stake. I’m excited but also a bit anxious about whether I can do well. When I first heard about the Magrathea project, I felt like this was something I wanted to dedicate my life to. I had already heard of Arthur’s reputation through LinkedIn, so I am honored to be part of this project.");
    print_separator();

    return 0;
}

