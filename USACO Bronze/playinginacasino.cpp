#include <bits/stdc++>

using namespace std;

int main(){
    int N;
    cin >> N; 

    map<int, int> m1; 
    map<int, int> m2; 
    vector<int> cows(N);
    vector<int> leader_positions;

    for(int i = 0; i < N; i++){
        cin >> cows[i];
        m1[cows[i]]++;
    }

    for(int i = 0; i < N; i++){
        int team = cows[i];
        m2[team]++;
        if(m2[team] == (m1[team] + 1) / 2){
            leader_positions.push_back(i);
        }
    }

    int min_distance = N; 
    int max_distance = 0;

    sort(leader_positions.begin(), leader_positions.end());

    for(int i = 0; i < leader_positions.size() - 1; i++){
        int distance = leader_positions[i + 1] - leader_positions[i];
        min_distance = min(distance, min_distance);
    }

    max_distance = leader_positions.back() - leader_positions.front();

    cout << min_distance << endl;
    cout << max_distance << endl;

    return 0;
}
