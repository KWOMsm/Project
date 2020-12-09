#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /*
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
	 *
     * 
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
            case KEY_ENTER:
            case 10:  
                switch(currItem) {
                    case 0:
                        moneyWrite();
                        //wrefresh(mywin);
                        break;
                    case 1:
                        moneyRead();
                        break;
                    case 2:
                        moneyPlan();
                        break;
                    case 3:
                        categorySetting();
                        break;
                    case 4:
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
    */

    // original
    
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