#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ncurses.h>

static int sum = 0;
static char money[BUFSIZ];
static char plan_date[BUFSIZ];
static char  plan_money[BUFSIZ];
static char *a[3];

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
 

    if((wplan = fopen("moneyPlan.txt", "w")) == NULL) {
        perror("fopen");
        exit(1);
    }

    printf("===== MAKE YOUR PLAN =====\n");
    printf("date : ");
    scanf("%s", plan_date);

    printf("\nmoney : ");
    scanf("%s", plan_money);
    fputs(plan_date, wplan);
    fputs(" ",wplan);
    fputs(plan_money,wplan);

    printf("===== SUCCESSS WRITE PLAN =====\n");

    fclose(wplan);
}

void readPlan() {
    FILE *rplan;
    char buf[100];
    

    if((rplan = fopen("moneyPlan.txt", "r")) == NULL) {
        printf("Set your plan! And restart!\n");
        exit(1);
    }

    printf("===== MY PLAN =====\n");
    fseek(rplan,0,0);
    while(fgets(buf, 100, rplan)!=NULL) {
    	a[0]=strtok(buf," ");
    	a[1]=strtok(NULL,"NULL");
    }
        
    
    printf("목표 : %s까지,%s 원 쓰기\n",a[0],a[1]);
    printf("\n===== READ END =====\n");

    fclose(rplan);
}

void print_total_spend() {
    FILE *rfp;
    char str[100];

    if((rfp = fopen("moneyWrite.txt", "r")) == NULL) {
        printf("===== ===== ===== ===== ===== =====\n");
        printf("There is no expenditure history.\n");
        printf("===== ===== ===== ===== ===== =====\n");
        return;
    }

    while(fgets(str, 100, rfp) != NULL) {
        printf("%s", str);
    }

    fclose(rfp);
}

void advice() {
    FILE *fp;
    int total = 0;
    int send = 0;
    char buf[BUFSIZ];
    int res;
    int plan;
    
    if((fp = fopen("total_spend.txt","a+")) == NULL) {
	    printf("Set your plan!\n");
	    return;
    }
    
    fputs(money, fp);
    fputs("\n", fp);
    fseek(fp, 0, 0);

    while(fgets(buf, 100, fp) != NULL) {
	    send = atoi(buf);
	    total += send;
    }

	readPlan();
	printf("Total spend : %d\n",total);

	plan = atoi(a[1]);
	res = plan - total;
	printf("목표까지 남은 금액 : %d\n",res);

	total=0;

	fclose(fp);
}

void moneyWrite() {
    // ex)
    // 11/19 entertain 1000
    // 11/20 tax 5000

    FILE *wfp, *rCategory;
    int c;

    char str[100];
    char *a[3];

    int i = 0;

    char date[10];
    char category[20];
    //char money[10];

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

    if((wfp = fopen("moneyWrite.txt", "a")) == NULL) {
        perror("fopen");
        exit(1);
    }

    fputs(date, wfp);
    fputs(" ", wfp);
    fputs(category, wfp);
    fputs(" ", wfp);
    fputs(money, wfp);
    fputs("\n", wfp);

    printf("===== SUCCESS WRITE =====\n");

    fclose(wfp);
    fclose(rCategory);
}

void moneyRead() {
    int opt;

    printf("===== READ OPTION =====\n");
    printf("1. TOTAL SPEND\n");
    printf("2. ADVICE\n");
    printf("OPTION : ");

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
