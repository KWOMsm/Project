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

struct moneyBook
{
    /* data */
    char * category[10];
    char date;
    int money;
};

int option() {
    int opt;

    printf("===== input option =====\n");
    printf("1. write\n");
    printf("2. read\n");
    printf("3. plan\n");
    printf("4. download\n");
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
    FILE *wfp;
    int c;

    char str[100];
    char *a[3];

    int i = 0;

    printf("===== CATEGORY =====\n");
    printf("entertain     tax\n");

    printf("input your money spend : ");
    scanf(" %[^\n]s", str);

    //printf("%s\n", str);
    

    if(strcmp(str, "quit") == 0) {
        exit(0);
    }
    else {
       //FILE* write

        if((wfp = fopen("moneyWrite.txt", "a")) == NULL) {
            perror("fopen");
            exit(1);
        }

        fputs(str, wfp);
        fputs("\n", wfp);

        a[0] = strtok(str, " ");
        a[1] = strtok(NULL, " ");
        a[2] = strtok(NULL, " ");
        sum = atoi(a[2]);

        printf("===== SUCCESS WRITE =====\n");

        fclose(wfp);
    }
}

void moneyRead() {
    // FILE *
    // print_total_spend()
    // advice()
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

void download() {
    // download moneyRead
    // download moneyPlan
    
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
                download();
                sleep(1);
                break;
            case 5:
                printf("===== QUIT PROGRAM =====\n");
                exit(0);
        }
    }
    return 0;
}