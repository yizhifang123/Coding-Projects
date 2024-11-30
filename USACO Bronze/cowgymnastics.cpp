#include <iostream>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    int a[n+1][k+1];
    for (int i=1; i<=k; i++)
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            a[x][i] = j;
        }
    int ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            bool yes = 1;
            for (int l=1; l<=k; l++)
                if (a[i][l]<=a[j][l])
                    yes = 0;
            if (yes) {
                ans++;
            }
        }
    cout << ans;
}