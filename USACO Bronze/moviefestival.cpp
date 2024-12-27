#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool compare(const pair<int,int> a, const pair<int,int> b){
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), cmp);
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++){
        if (movies[i].first >= curr){
            ans++;
            curr = movies[i].second;
        }
    }

    cout << ans;

    return 0;
}