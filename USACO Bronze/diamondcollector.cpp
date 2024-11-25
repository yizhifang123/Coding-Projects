#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> diamonds(n);
	for (int d : diamonds) {
        cin >> d; 
    }

	int most = 0;
	for (int x : diamonds) {
		int fittable = 0;
		for (int y : diamonds) {
			if (x <= y && y <= x + k) {
                 fittable++; 
            }
		}
		most = max(most, fittable);
	}

	freopen("diamond.out", "w", stdout);
	cout << most << endl;
}