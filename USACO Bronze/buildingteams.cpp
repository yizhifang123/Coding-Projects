#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[200005];
int color[100005];
bool impossible = false;

void color_em (int node, int cc) {
    //color nodes
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (color[0] == 0)
            color_em(i, 1);
    }

    if (impossible) {
        cout << "IMPOSSIBLE";
    }
    else
        for (int i = 1; i <= N; i++) {
            cout <<  color[i] << ' ';
        }
    cout << endl;
}