#include "tlib.h"
#include <stdarg.h>

char *getBGSeq(char *color) {
	char *s;
	sprintf(s, ESC"["BG"%sm", color);
	return s;
}

char *getFGSeq(char *color) {
	char *s;
	sprintf(s, ESC"["FG"%sm", color);
	return s;
}

char *getBoldSeq() {
	return ESC"[1m";
}

char *getMoveCurSeq(char move, int val) {
	char *s;
	sprintf(s, ESC"[%d%c", val, move);
	return s;
}

char *getSetCurSeq(int row, int col) {
	char *s;
	sprintf(s, ESC"[%d;%dH", row, col);
	return s;
}

char *getSaveCurSeq() {
	return ESC"[s";
}

char *getRestoreCur() {
	return ESC"[s";
}

char *getResetSeq() {
	return ESC"[0m";
}

void setBG(char* color) {
	printf(getBGSeq(color));
}

void setFG(char* color) {
	printf(getFGSeq(color));
}

void setBold() {
	printf(getBoldSeq());
}

void moveCur(char move, int val) {
	printf(getMoveCurSeq(move, val));
}

void setCur(int row, int col) {
	printf(getSetCurSeq(row, col));
}

void saveCur() {
	printf(getSaveCurSeq());
}

void restoreCur() {
	printf(getRestoreCur());
}

void reset() {
	printf(getResetSeq());
}

void clrs() {
	printf(ESC"[2J");
}

void color_printf(char* color, char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	setFG(color);
	vprintf(fmt, ap);
	reset();
	va_end(ap);
}

void style_printf(char* style, char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	printf(style);
	vprintf(fmt, ap);
	reset();
	va_end(ap);
}
