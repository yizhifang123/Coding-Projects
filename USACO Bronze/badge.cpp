#include <bits/stdc++.h>
using namespace std;

vector<int> res;
vector<int> arr;

void fill_up(int curr, int first_cycle) {
	while (curr != first_cycle) {
		res[curr] = res[first_cycle];
		curr = arr[curr];
	}
}

int floyd(int curr) {
	int a = arr[curr];
	int b = arr[arr[curr]];
	while (a != b) {
		if (res[a] != -1) {
			fill_up(curr, a);
			return 0;
		}
		a = arr[a];
		b = arr[arr[b]];
	}

	a = curr;
	while (a != b) {
		a = arr[a];
		b = arr[b];
	}

	int cycle_first = a;
	a = curr;
	while (a != cycle_first) {
		res[a] = cycle_first;
		a = arr[a];
	}

	a = cycle_first;
	do {
		res[a] = a;
		a = arr[a];
	} while (a != cycle_first);

	return 0;
}

int main() {
	int n;
	cin >> n;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) { cin >> arr[i]; }

	res.resize(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (res[i] == -1) { floyd(i); }
	}

	for (int i = 1; i <= n; i++) { cout << res[i] << " \n"[i == n]; }
}