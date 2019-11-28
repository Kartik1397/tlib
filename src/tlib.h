#include <stdio.h>

#define ESC "\x1b"

#define BLACK "0"
#define RED "1"
#define GREEN "2"
#define YELLOW "3"
#define BLUE "4"
#define MAGENTA "5"
#define CYAN "6"
#define WHITE "7"

#define FG "3"
#define BG "4"

#define UP 'A'
#define DOWN 'B'
#define RIGHT 'C'
#define LEFT 'D'

#define RESET ESC"[0m"

char *getBGSeq(char *color);
char *getFGSeq(char *color);
char *getBoldSeq();
char *getMoveCurSeq(char move, int val);
char *getSetCurSeq(int row, int col);
char *getSaveCurSeq();
char *getRestoreCur();
char *getResetSeq();

void setBG(char* color);
void setFG(char* color);
void setBold();
void moveCur(char move, int val);
void setCur(int row, int col);
void saveCur();
void restoreCur();
void reset();
void clrs();

void color_printf(char* color, char* fmt, ...);
void style_printf(char* style, char* fmt, ...);
