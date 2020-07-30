#include <bits/stdc++.h>
#include "testlib.h"
#define LL long long
#define PLL pair<LL, LL>
#define PII pair<int, int>
#define fi first
#define se second
const int MAXN = (int) 1e6 + 48763;
using namespace std;

PII rand_interval(LL maxr) {
	LL id = rnd.next(0LL, maxr * maxr - 1), l = id % maxr + 1, r = id / maxr + 1;
	if (l > r) swap(l, r);
	return PII(l, r);
}

PII rand_interval2(LL maxr, LL maxlen) {
	LL l = rnd.next(1LL, maxr), r = min(l + rnd.next(0LL, maxlen - 1), maxr);
	return PII(l, r);
}

const int subtask_info[5][3] = {
	{-1, -1},
	{5, 10, 10}, // maxn, maxw, maxr
	{(int) 1e3, (int) 1e4, (int) 1e4},
	{(int) 1e4, (int) 1e9, (int) 1e9},
	{(int) 1e6, (int) 1e9, (int) 1e9}
};

int task, typew, typer, maxn, maxw, maxr;
int n, W[MAXN];
PII LR[MAXN];

int main(int argc, char **argv) {
	// ./generator <subtask> <typew> <typer>
	// typew = 1 for random w, typew = 2 for small w.
	// typer: 1 for pure random, 2 for medium length intervals, 3 for very small length intervals, 4 for small intervals in small range.
	// 5 for decreasing intervals, 6 for some high intervals with huge w, (not implemented yet)
	registerGen(argc, argv, 1);
	
	int task = atoi(argv[1]), typew = atoi(argv[2]), typer = atoi(argv[3]);
	maxn = subtask_info[task][0];
	maxw = subtask_info[task][1];
	maxr = subtask_info[task][2];
	
	// Set n
	n = rnd.next(1, maxn);
	
	// Set W, typew = 1 for random w, typew = 2 for small w.
	for (int i = 0; i < n; i++) {
		if (typew == 1) W[i] = rnd.next(1, maxw);
		else if (typew == 2) W[i] = rnd.next(1, min(maxw, 5));
		else assert(0);
	}
	
	// Set L, R
	// typer: 1 for pure random, 2 for medium length intervals, 3 for very small length intervals, 4 for small intervals in small range.
	// 5 for decreasing intervals, 6 for some high intervals with huge w, (not implemented yet)
	if (typer == 4) maxr = max(10, n / 10);
	for (int i = 0; i < n; i++) {
		if (typer == 1) LR[i] = rand_interval(maxr);
		else if (typer == 2) LR[i] = rand_interval2(maxr, max(1, maxr / 10));
		else if (typer == 3 || typer == 4) LR[i] = rand_interval2(maxr, min(maxr, 10));
		else assert(0);
	}
	
	// Output
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << LR[i].fi << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; i++) {
		cout << LR[i].se << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; i++) {
		cout << W[i] << " \n"[i == n - 1];
	}
	
	return 0;
}
