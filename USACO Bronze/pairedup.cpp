#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i][1] >> v[i][0];
    }
    sort(v.begin(), v.end());
    int ans = 0, f = 0, b = v.size() - 1;
    while(f <= b)
    {
        ans = max(ans, v[f][0] + v[b][0]);
        int pairs = min(v[f][1], v[b][1]);
        v[f][1] -= pairs;
        v[b][1] -= pairs;
        if(v[f][1] <= 0)
        {
            f++;
        }
        if(v[b][1] <= 0)
        {
            b--;
        }
    }
    cout << ans << "\n";
    return 0;
}