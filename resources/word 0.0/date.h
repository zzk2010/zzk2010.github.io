#ifndef _DATE_H_
#define _DATE_H_
#include <bits/stdc++.h>
struct tim { int y, m, d; };
int days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
tim gettime() {
    time_t rawtime;
    struct tm *ptminfo;
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    return (tim){ptminfo->tm_year+1900, ptminfo->tm_mon+1, ptminfo->tm_mday};
}
bool isrun(int yr) {
	return ((yr % 400 == 0) || ((yr % 4 == 0) && (yr % 100 != 0)));
}
tim nextday(tim today) {
	today.d++;
	if (today.d > days[today.m] + (today.m == 2 && isrun(today.y))) today.m++, today.d = 1;
	if (today.m > 12) today.y++, today.m = 1, today.d = 1;
	return today;
}
int gap(int y1, int m1, int d1, int y2, int m2, int d2) {
	tim lday = (tim){y1, m1, d1}, today = (tim){y2, m2, d2};
	int cnt = 0;
	while (1) {
		if (lday.y == today.y && lday.m == today.m && lday.d == today.d) break;
		lday = nextday(lday);
		cnt++;
	}
	return cnt;
}
#endif
