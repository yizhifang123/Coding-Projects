#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, L;
    cin >> N >> L;
    string stalls;
    cin >> stalls;
    vector<int> cow_positions;
    for (int i = 0; i < N; ++i){
        if (stalls[i] == '1'){
            cow_positions.push_back(i);
        }
    }
    int minSpread = N;
    for (int i = 0; i < cow_positions.size(); i++) {
        vector<int> remaining_cows = cow_positions;
        remaining_cows.erase(remaining_cows.begin() + i);
        vector<int> spreads;
        int start = remaining_cows[0];
        int end = remaining_cows[0];
        for (int i = 1; i < remaining_cows.size(); ++i) {
            if (remaining_cows[i] - remaining_cows[i - 1] <= L) {
                end = remaining_cows[i];
            } else {
                spreads.push_back(end - start);
                start = end = remaining_cows[i];
            }
        }
        spreads.push_back(end - start);
        int minSpreadThisRemoval = spreads[0];
        for (int j = 1; j < spreads.size(); ++j) {
            if (spreads[j] < minSpreadThisRemoval) {
                minSpreadThisRemoval = spreads[j];
            }
        }
        minSpread = min(minSpread, minSpreadThisRemoval);
    }
    cout << minSpread << endl;
    return 0;
}
