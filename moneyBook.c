/* 
moneyBook Program
moneyWrite()
moneyRead()
moneyPlan()
download()

struct write {
    char *category[] //traffic, food, etc
    char date
    int money
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int sum = 0;

typedef struct
{
    /* data */
    char * category[10];
    char date[6];
    int money;
    int category_count[10]; // count
}moneybook;

int option() {
    int opt;

    printf("===== input option =====\n");
    printf("1. write\n");
    printf("2. read\n");
    printf("3. plan\n");
    printf("4. category setting\n");
    printf("5. QUIT\n");
    printf("OPTION : ");

    scanf("%d", &opt);
    return opt;
}

void makePlan() {
    FILE *wplan;
    char buf[100];

    if((wplan = fopen("moneyPlan.txt", "w")) == NULL) {
        perror("fopen");
        exit(1);
    }

    printf("===== MAKE YOUR PLAN =====\n");

    scanf(" %[^\n]s", buf);
    fputs(buf, wplan);

    printf("===== SUCCESSS WRITE PLAN =====\n");

    fclose(wplan);
}

void readPlan() {
    FILE *rplan;
    char buf[100];

    if((rplan = fopen("moneyPlan.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    printf("===== YOUR PLAN =====\n");

    while(fgets(buf, 100, rplan) != NULL) {
        printf("%s", buf);
    }

    printf("\n===== READ END =====\n");

    fclose(rplan);
}

void print_total_spend() {
    FILE *rfp;
    char str[100];

    if((rfp = fopen("moneyWrite.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while(fgets(str, 100, rfp) != NULL) {
        printf("%s", str);
    }

    fclose(rfp);
}

void advice() {
    printf("save your money\n");
}

void moneyWrite() {
    // 11/19 entertain 1000
    // 11/20 tax 5000
    // moneyBook
    FILE *wfp, *rCategory;
    int c;

    char str[100];
    char *a[3];

    int i = 0;

    char date[10];
    char category[20];
    char money[10];

    char categoryRead[100];

    if((rCategory = fopen("moneyCategory.txt", "r")) == NULL) {
        printf("Please add category at least 1\n");
        return;
    }

    printf("===== CATEGORY =====\n");

    while(fgets(categoryRead, 100, rCategory) != NULL) {
        printf("%s", categoryRead);
    }
    printf("\n===== ======== =====\n");

    printf("input your money spend\n");

    printf("date: ");
    scanf("%s", date);

    printf("\ncategory: ");
    scanf("%s", category);

    printf("\nmoney: ");
    scanf("%s", money);

    //scanf(" %[^\n]s", str);

    //printf("%s\n", str);
    
    //FILE* write

    if((wfp = fopen("moneyWrite.txt", "a")) == NULL) {
        perror("fopen");
        exit(1);
    }

    fputs(date, wfp);
    fputs(" ", wfp);
    fputs(category, wfp);
    fputs(" ", wfp);
    fputs(money, wfp);
    fputs(" ", wfp);

    /*
    a[0] = strtok(str, " ");
    a[1] = strtok(NULL, " ");
    a[2] = strtok(NULL, " ");
    sum = atoi(a[2]);
    */

    printf("===== SUCCESS WRITE =====\n");

    fclose(wfp);
    fclose(rCategory);
}

void moneyRead() {
    int opt;

    printf("===== READ OPTION =====\n");
    printf("1. TOTAL SPEND\n");
    printf("2. ADVICE\n");

    scanf("%d", &opt);
    switch(opt) {
        case 1:
            print_total_spend();
            break;
        case 2:
            advice();
            break;
    }
}

void moneyPlan() {
    // write my plan
    int opt;

    printf("===== PLAN OPTION =====\n");
    printf("1. make plan\n");
    printf("2. read plan\n");
    printf("OPTION : ");

    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        makePlan();
        break;
    
    case 2:
        readPlan();
        break;
    }
}

void addCategory() {
    FILE *wCategory;

    char buf[100];

    if((wCategory = fopen("moneyCategory.txt", "a")) == NULL) {
        perror("fopen");
        exit(1);
    }

    printf("===== WRITE NEW CATEGORY =====\n");
    printf("===== 'quit' is quit writing =====\n");
    while(1)
    {
        scanf("%s", buf);
        if(strcmp(buf, "quit") == 0) {
            break;
        }
        fputs(" ", wCategory);
        fputs(buf, wCategory);
    }

    printf("===== SUCCESSS WRITE CATEGORY =====\n");

    fclose(wCategory);
}

void subCategory() {
    FILE *rCategory, *wCategory;

    char categoryRead[100], categoryWrite[100];
    char c[100] = "";
    char temp[100] = "";
    char *p_pos;

    if((rCategory = fopen("moneyCategory.txt", "r")) == NULL) {
        printf("No Category\n");
        return;
    }

    printf("===== CATEGORY LIST =====\n");

    while(fgets(categoryRead, 100, rCategory) != NULL) {
        strcat(temp, categoryRead);
        printf("%s", categoryRead);
    }

    printf("\n===== WRITE DOWN WHICH CATEGORY TO DROP =====\n");
    printf("===== 'quit' is quit writing =====\n");


    printf("input : ");
    scanf("%s", categoryWrite);
        
    p_pos = strstr(categoryRead, categoryWrite);
    if(p_pos == NULL) {
        printf("wrong category\n");
        return;
    }
    strncpy(c, temp, strlen(temp)-strlen(p_pos)-1);

    p_pos = p_pos + strlen(categoryWrite);
    strcat(c, p_pos);

    if((wCategory = fopen("moneyCategory.txt", "w")) == NULL) {
        perror("fopen");
        exit(1);
    }
    
    fputs(c, wCategory);

    printf("===== DELETE SUCCESS =====\n");
    
    fclose(rCategory);
    fclose(wCategory);
}

void categorySetting() {
    int opt;

    printf("===== CATEGORY OPTION =====\n");
    printf("1. ADD CATEGORY\n");
    printf("2. SUB CATEGORY\n");

    scanf("%d", &opt);
    switch(opt) {
        case 1:
            addCategory();
            break;
        case 2:
            subCategory();
            break;
    }
}

int main(void) {
    int opt;

    while(1) {

        opt = option();

        switch(opt) {
            case 1:
                moneyWrite();
                sleep(1);
                break;
            case 2:
                moneyRead();
                sleep(1);
                break;
            case 3:
                moneyPlan();
                sleep(1);
                break;
            case 4:
                categorySetting();
                sleep(1);
                break;
            case 5:
                printf("===== QUIT PROGRAM =====\n");
                exit(0);
        }
    }
    return 0;
}
