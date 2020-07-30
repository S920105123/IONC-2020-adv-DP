#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1000005;
int L[MAXN], R[MAXN], W[MAXN];

int main(int argc, char **argv) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 1e6, "n");
	inf.readEoln();
	
	for (int i = 1; i <= n; i++) {
		L[i] = inf.readInt(1, 1e9, "L[i]");
		if (i != n) inf.readSpace();
		else inf.readEoln();
	}
	
	for (int i = 1; i <= n; i++) {
		R[i] = inf.readInt(L[i], 1e9, "R[i]");
		if (i != n) inf.readSpace();
		else inf.readEoln();
	}
	
	for (int i = 1; i <= n; i++) {
		W[i] = inf.readInt(1, 1e9, "W[i]");
		if (i != n) inf.readSpace();
		else inf.readEoln();
	}
	
    inf.readEof();
	return 0;
}
