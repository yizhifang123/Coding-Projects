#include <iostream>
#include <cmath>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m;
    cin >> x >> y >> m;
    int ans = 0;
    int most = max(m/x, m/y)+1;
    for(int i=0; i<most; i++){
        for(int j=0; j<most; j++){
            int result = 0;
            result += i*x;
            result += j*y;
            if(result<m+1){
                ans = max(result, ans);
            }
        }
    }
    cout << ans;
}