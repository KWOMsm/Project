#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define moneyTRUE 1
#define moneyFALSE 0

#define KWON_COLOR 1

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
        perror("fopen");
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
        perror("fopen");
        exit(1);
    }

    while(fgets(str, 100, rfp) != NULL) {
        printf("%s", str);
    }

    fclose(rfp);
}

void advice() {
    FILE *fp;
    int total;
    int send=0;
    char buf[BUFSIZ];
    int res;
    int plan;
    
    if((fp=fopen("total_send.txt","a+"))==NULL) {
	    perror("fopen");
	    exit(1);
    }
    
    fputs(money,fp);
    fputs("\n",fp);
    fseek(fp,0,0);
    while(fgets(buf,100,fp)!=NULL) {
	    send=atoi(buf);
	    total+=send;
    }
	    readPlan();
	    printf("Total send : %d\n",total);
	    plan=atoi(a[1]);
	    res=plan-total;
	    printf("목표까지 남은 금액 : %d\n",res);
	    total=0;
	    fclose(fp);

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
    // ncurses
    int x = 0, y = 0, i = 0;
	int max_x = 0, max_y = 0;
	int next_x = 0;
	int direction = 1;
	int ch = 0; // init
	int msg = 0; // init
	char buffer[8]={0,};
	WINDOW *mywin = NULL;

    initscr(); // start curses mode
	cbreak(); // line buffering disabled; pass on everything to me

	if( has_colors() == FALSE ) { // color is not supported
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color(); // start the color mode
	/*
	 * define a new color-pair to use it later
	 * : init_pair(index, foreground, background)
	 */
	init_pair(KWON_COLOR, COLOR_GREEN, COLOR_BLACK);
	noecho();
	keypad(stdscr, TRUE); // call after initscr, to understand KEY strokes
	curs_set(FALSE);

	getmaxyx(stdscr, max_y, max_x);
	x = max_x / 2;
	y = max_y / 2;

    int nItem = 5;
	char menus[5][30]={{"  write"}, {"  read"}, {"  plan"}, {"  category setting"}, {"  QUIT"}};
	char selMenus[5][30]={{"> write"}, {"> read"}, {"> plan"}, {"> category setting"}, {"> QUIT"}};
	char description[5][64]={{"Info: Write your expenditure"},{"Info: Check your expenditure"},{"Info: Write your plan!"}, {"Info: Set category"}, {"Info: QUIT PROGRAM"}};
	int currItem = 0;
	int cont = moneyTRUE;
	int nRemainingItems = nItem;
	// int deleted[5]={0,0,0,0,0};
	// char *deletedMenu="  (deleted)";
	// char *deletedMenuSel="> (deleted)";
	
	int boxWidth = 20;
	int boxHeight = 20;
	int boxY = 20;
	int boxX = 0;

    while( cont ) { 
		clear(); // clearn the screen, and place the cursor in upper-left corner
		// write characters on the buffer, and print out when refresh is called
		for( i = 0 ; i < nItem ; i++ ) {
			if( currItem == i ) {
				attron(COLOR_PAIR(KWON_COLOR));
				mvprintw(i,0,selMenus[i]);
				attroff(COLOR_PAIR(KWON_COLOR));
			} else {
                mvprintw(i,0,menus[i]);
            }
		}
		mvhline(i, 0, '_', max_x/2); // draw a horizontal line
		mvprintw(++i,0,description[currItem]); // prints out a message
		
		refresh();

		ch = (int) getch();	

		switch( ch ) {
			case KEY_UP:
				if( currItem > 0 ) currItem -= 1;
				break;
        	case KEY_DOWN:
				if( currItem + 1 < nItem ) currItem += 1;
				break;
            case 10:  
                switch(currItem) {
                    case 1:
                        moneyWrite();
                        break;
                    case 2:
                        moneyRead();
                        break;
                    case 3:
                        moneyPlan();
                        break;
                    case 4:
                        categorySetting();
                        break;
                    case 5:
                        cont = moneyFALSE;
                }
                break;
			case 'q':
				cont = moneyFALSE;
				break;
			default:
				break;
		}
	}
	endwin();




    // normal

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

