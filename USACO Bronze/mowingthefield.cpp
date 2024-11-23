#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout); 

    int N;
    cin >> N;

    int x = 0, y = 0, t = 0;
    map<pair<int, int>, int> cut_grass;
    int ans = 1e9; 
    cut_grass[{0, 0}] = 0;

    for (int i = 0; i < N; i++) {
        char dir;
        int steps;
        cin >> dir >> steps;

        for (int l = 0; l < steps; l++) {
            t++;
            if (dir == 'N') {
                y++;
            } else if (dir == 'E') {
                x++;
            } else if (dir == 'S') {
                y--;
            } else if (dir == 'W') {
                x--;
            }

            if (cut_grass.count({x, y}) == 1){
                ans = min(ans, t - cut_grass[{x, y}]);
            }
            cut_grass[{x, y}] = t;

        }
    }
    if(ans == 1e9){
        cout << -1;
    }
    else{
        cout << ans;
    }
    

    return 0;
}
