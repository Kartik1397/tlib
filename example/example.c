#include "../src/tlib.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void _log(char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);


	time_t t;
	t = time(NULL);
	struct tm *tmp;
	tmp = localtime(&t);

	char style[1024] = "";
	strcat(style, getBoldSeq());
	strcat(style, getFGSeq(BLUE));

	style_printf(style, "%02d:%02d:%02d | ", tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
	vprintf(fmt, ap);
	puts("");
	va_end(ap);
}

int main() {
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		for (long long int j = 0; j < 100000000; j++)
			cnt++;
		for (long long int j = 0; j < 100000000; j++)
			cnt++;
		for (long long int j = 0; j < 100000000; j++)
			cnt++;
		for (long long int j = 0; j < 100000000; j++)
			cnt++;
		for (long long int j = 0; j < 100000000; j++)
			cnt++;
		for (long long int j = 0; j < 100000000; j++)
			cnt++;
		_log("Count - %d", cnt);
	}
}
