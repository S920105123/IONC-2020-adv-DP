#include <bits/stdc++.h>
#include "testlib.h"
#define LL long long
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXN = (int) 1e6 + 48763;
using namespace std;

PLL rand_interval(LL maxr) {
	LL id = rnd.next(0LL, maxr * maxr - 1), l = id % maxr + 1, r = id / maxr + 1;
	if (l > r) swap(l, r);
	return PLL(l, r);
}

PLL rand_interval2(LL maxr, LL maxlen) {
	LL l = rnd.next(1LL, maxr), r = min(l + rnd.next(0LL, maxlen - 1), maxr);
	return PLL(l, r);
}

const int subtask_info[5][3] = {
	{-1, -1},
	{10, 10, 10}, // maxn, maxq, maxv
	{(int) 1e2, (int) 1e2, (int) 1e2},
	{(int) 1e9, (int) 4e2, (int) 4e2}
};

int task, typev, typelr, maxn, maxq, maxv;
int n, qn, V[MAXN];
PLL LR[MAXN];

int main(int argc, char **argv) {
	// ./generator <subtask> <typev> <typelr>
	// typev = 1 for random v, 2 for small v.
	// typelr: 1 for pure random, 2 for medium length intervals, 3 for very small length intervals.
	registerGen(argc, argv, 1);
	
	int task = atoi(argv[1]), typev = atoi(argv[2]), typelr = atoi(argv[3]);
	maxn = subtask_info[task][0];
	maxq = subtask_info[task][1];
	maxv = subtask_info[task][2];
	
	// Set n
	n = rnd.next(1, maxn);
	qn = rnd.next(1, maxq);
	
	// Set W, typew = 1 for random w, typew = 2 for small w.
	for (int i = 0; i < qn; i++) {
		if (typev == 1) V[i] = rnd.next(1, maxv);
		else if (typev == 2) V[i] = rnd.next(1, min(maxv, 5));
		else assert(0);
	}
	
	// Set L, R
	// typer: 1 for pure random, 2 for medium length intervals, 3 for very small length intervals, 4 for small intervals in small range.
	// 5 for decreasing intervals, 6 for some high intervals with huge w, (not implemented yet)
	for (int i = 0; i < qn; i++) {
		if (typelr == 1) LR[i] = rand_interval(n);
		else if (typelr == 2) LR[i] = rand_interval2(n, max(1, n / 10));
		else if (typelr == 3) LR[i] = rand_interval2(n, min(n, 10));
		else assert(0);
	}
	
	// Output
	cout << n << ' ' << qn << '\n';
	for (int i = 0; i < qn; i++) {
		cout << LR[i].fi << ' ' << LR[i].se << ' ' << V[i] << " \n"[i == qn - 1];
	}
	
	return 0;
}
