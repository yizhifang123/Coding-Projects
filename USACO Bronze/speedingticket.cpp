#include <iostream>
#include <vector>

using namespace std;

int main() {
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  vector<int> speed_limits;
  vector<int> bessie_speeds;
  int n, m, over_limit=0;
  cin >> n >> m;
  for (int i=0; i<n; i++){
    int length, limit;
    cin >> length >> limit;
    for(int i=0; i<length; i++){
        speed_limits.push_back(limit);
    }
  } 
  for (int i=0; i<m; i++){
    int length, limit;
    cin >> length >> limit;
    for(int i=0; i<length; i++){
        bessie_speeds.push_back(limit);
    }
  }
  for(int i=0; i<100; i++){
    if(bessie_speeds[i] - speed_limits[i]>0){
        over_limit = max(over_limit, bessie_speeds[i] - speed_limits[i]);
    }
  }
  cout << over_limit;
}