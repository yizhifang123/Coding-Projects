#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customComparison(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first * b.second > b.first * a.second;
}

int main() {
    vector<pair<int, int>> fractions;
    int numerator, denominator;
    while (cin >> numerator >> denominator) {
        fractions.push_back(make_pair(numerator, denominator));
    }

    sort(fractions.begin(), fractions.end(), customComparison);

    for (const auto& frac : fractions) {
        cout << frac.first << '/' << frac.second << endl;
    }

    return 0;
}
