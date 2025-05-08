#include <stdio.h>
#include <stdlib.h>

int main() {
    char date[15];
    char name[25];
    char border[] = ("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    printf("[Please enter the current date in the \"yyyy-mm-dd\" format]: ");
    fgets(date, sizeof(date), stdin);
    
    printf("[Please enter your name]: ");
    fgets(name, sizeof(name), stdin);
    printf("**The input has been processed successfully.**\n");

    //system("sleep 3");
    printf("\n%s\n", border);
    printf("\n                                              [Magrathea ver 0.1]");
    printf("\n                   Magrathea, where a shining planet is created in a wasteland with no grass,");
    printf("\n           a place where unseen potential is discovered and gems are polished by the hands of experts,");
    printf("\n                                             Welcome to Magrathea.\n");
    printf("\n%s", border);
    printf("\n[User]: %-65s [Execution Time]: %s", name, date);
    printf("\n=============================================================================================================");

    return 0;
}
