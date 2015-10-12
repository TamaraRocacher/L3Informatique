#include <stdio.h>
#include <ncurses.h>

int main() {
  WINDOW *vin;
  vin = initscr();
  start_color();
  init_pair(1,COLOR_YELLOW,COLOR_BLUE);
  init_pair(2,COLOR_BLUE,COLOR_YELLOW);
  init_pair(3,COLOR_BLUE,COLOR_WHITE); 
  vin=newwin(20,30,10,50);
  wmove(vin,0,5);
  wprintw(vin,"Hello, World.");
  wbkgd(vin,COLOR_PAIR(3));
  refresh();
  wrefresh(vin);
  getch();
  delwin(vin);
  endwin();
}
