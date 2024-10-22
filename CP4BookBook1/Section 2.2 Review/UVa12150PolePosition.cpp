#include <iostream>
#include <vector>
using namespace std;
 int main(){
    int cars;
    cin >> cars;
    vector<pair<int , int>> positions(cars);
    vector<int> original_positions(cars, -1);
    for(int i=0; i<cars; i++){
        int place, record;
        cin >> place >> record;
        positions[i].first = place;
        positions[i].second = record;
    }
    bool good = true;
   for (int i = 0; i < cars; i++) {
        int original_pos = i + positions[i].second;
        if (original_pos < 0 || original_pos >= cars || original_positions[original_pos] != -1) {
            good = false;
            break;
        }
        original_positions[original_pos] = positions[i].first;
    }
    if(good){
        for(int i:original_positions){
            cout << i << " ";
        }
    }
    else cout << -1 << endl;
 }