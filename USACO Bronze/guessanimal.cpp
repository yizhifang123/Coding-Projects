#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {

  freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

  map<string, set<string>> data;

  int t; cin >> t;
  while(t--) {
    string a; cin >> a;
    int n; cin >> n; cin.ignore();

    set<string> tmp;
    for(int i = 0; i < n; ++i) {
      string tt; cin >> tt;
      tmp.insert(tt);
    }

    data[a] = tmp;
  }

  int best = 0;
  for(const auto k: data) {
    string name = k.first;

    int totalB = 0;
    for(const auto h: data) {
      int total = 0;
      if(h.first == name) continue;

      for(auto l: k.second) {
        if(h.second.count(l)) total++;
      }
      totalB = max(total, totalB);
    }
    best = max(best, totalB);
  }
  cout << best + 1 << "\n";

  return 0;
}