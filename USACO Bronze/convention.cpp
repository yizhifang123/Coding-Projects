#include <bits/stdc++.h>

using namespace std;

vector<int> times;
int M;
int C;

bool good(int K) {
    int first_cow_bus = times[0];
    
    int num_buses = 1;
    int num_cows_on_bus = 0;
    for (int time : times) {
        num_cows_on_bus++;
        if (time - first_cow_bus > K || num_cows_on_bus > C) {
            num_buses++;
            num_cows_on_bus = 1;
            if (num_buses > M) return false;
            first_cow_bus = time;
        }
    }
    
    return true;
}

int main() {
    
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    
    int N;
    cin >> N >> M >> C;
    
    for (int i = 0; i < N; ++i) {
        int cow; cin >> cow;
        times.push_back(cow);
    }
    
    sort(begin(times), end(times));
    
    int K = 0, low = 0, high = times[N - 1] - times[0];
    while (low < high) {
        K = (low + high) / 2;
        
        if (good(K)) {
            high = K;
        }
        else low = K + 1;
    }
    
    cout << low << "\n";
}