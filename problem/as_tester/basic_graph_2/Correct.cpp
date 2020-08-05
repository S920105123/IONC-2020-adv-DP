#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXN = 200005;
//const LL INF = (LL) 1e9 + 5;
//const LL MOD = (LL) 1e9 + 7;
using namespace std;

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b;
	cin >> a >> b;
	assert(0 <= a && a <= 1000);
	assert(0 <= b && b <= 1000);
	assert(0 < a + b && a + b <= 1000);
	cout << (a != 0 && b != 0) << '\n';
	
	return 0;
} 
