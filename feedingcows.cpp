#include <iostream>

using namespace std;
int main() {

	int T;
	cin >> T;

	while (T--) {
		int n;
		int k;
		cin >> n >> k;
		string s;
		cin >> s;

		int patchG = -k - 1;
		int patchH = -k - 1; 

		int cnt = 0;
		string ans(n, '.');

		for (int i = 0; i < n; i++) {
			if (s[i] == 'G' && i - patchG > k) {
				cnt++;
				if (i + k >= n) {
					patchG = i;
					if (ans[patchG] == 'H') { patchG--; }
				} else {
					patchG = i + k;
				}
				ans[patchG] = 'G';
			}
			if (s[i] == 'H' && i - patchH > k) {
				cnt++;
				if (i + k >= n) {
					patchH = i;
					if (ans[patchH] == 'G') { patchH--; }
				} else {
					patchH = i + k;
				}
				ans[patchH] = 'H';
			}
		}
		cout << cnt << endl << ans << endl;
	}
}
