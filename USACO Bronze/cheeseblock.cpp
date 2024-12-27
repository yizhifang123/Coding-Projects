#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<vector<int>> surfacex(N, vector<int>(N, N));
    vector<vector<int>> surfacey(N, vector<int>(N, N));
    vector<vector<int>> surfacez(N, vector<int>(N, N));
    int count = 0;
    
    for (int i = 0; i < Q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        
        surfacex[y][z] -= 1;
        if (surfacex[y][z] == 0) {
            count += 1;
        }
        
        surfacey[x][z] -= 1;
        if (surfacey[x][z] == 0) {
            count += 1;
        }
        
        surfacez[x][y] -= 1;
        if (surfacez[x][y] == 0) {
            count += 1;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
