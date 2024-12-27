#include <iostream>
using namespace std;

int main() {
	freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
	string crossings;
	cin >> crossings;

	int crossing_pairs = 0;
	for (int a = 0; a < crossings.size(); a++) {
		for (int b = a + 1; b < crossings.size(); b++) {
			for (int c = b + 1; c < crossings.size(); c++) {
				for (int d = c + 1; d < crossings.size(); d++) {
					crossing_pairs +=
					    (crossings[a] == crossings[c] && crossings[b] == crossings[d]);
				}
			}
		}
	}

	cout << crossing_pairs << endl;
}