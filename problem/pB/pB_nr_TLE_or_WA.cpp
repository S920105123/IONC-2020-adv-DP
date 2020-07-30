#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
const int MAXN = 1000005;
const int MAXR = 10005;
const LL INF = (LL) 1e18 + 48763;
using namespace std;

int n, minv[MAXN], maxv[MAXN];
LL wei[MAXN], dp1[MAXR], dp2[MAXR];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> minv[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> maxv[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> wei[i];
	}
	
	int range = MAXR;
	for (int j = 0; j < range; j++) {
		dp1[j] = (minv[0] <= j && j <= maxv[0] ? wei[0] : -INF);
		dp2[j] = max(0LL, dp1[j]);
		if (j > 0) {
			dp2[j] = max(dp2[j], dp2[j - 1]);
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < range; j++) {
			if (minv[i] <= j && j <= maxv[i]) {
				dp1[j] = max(dp1[j], dp2[j] + wei[i]);
			}
		}
		for (int j = 0; j < range; j++) {
			dp2[j] = max(dp2[j], dp1[j]);
			if (j > 0) {
				dp2[j] = max(dp2[j], dp2[j - 1]);
			}
		}
	}
	
	cout << dp2[range - 1] << '\n';

	return 0;
}
