#include <iostream>
#include <vector>
using namespace std;

int result = 0;
vector<vector<bool>> visited;

void continue_path(int f_count, int b_count, int x, int y, vector<vector<char>>& horseshoes, int n) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;

    if (visited[x][y]) return;

    if (horseshoes[x][y] == '(') {
        if(b_count>0){
            return;
        }
        f_count++;
    } else {
        b_count++;
    }

    if (b_count > f_count) return;

    if (f_count == b_count) {
        result = max(result, f_count+b_count);
    }

    visited[x][y] = true;

    continue_path(f_count, b_count, x + 1, y, horseshoes, n);
    continue_path(f_count, b_count, x - 1, y, horseshoes, n); 
    continue_path(f_count, b_count, x, y + 1, horseshoes, n);
    continue_path(f_count, b_count, x, y - 1, horseshoes, n); 
    visited[x][y] = false;
}

int main() {
    freopen("hshoe.in", "r", stdin);
    freopen("hshoe.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<char>> horseshoes(n, vector<char>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> horseshoes[i][j];
        }
    }

    if (horseshoes[0][0] == '(') {
        continue_path(0, 0, 0, 0, horseshoes, n);
    }

    cout << result << endl;

    return 0;
}
