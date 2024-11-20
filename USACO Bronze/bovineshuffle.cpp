#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int cows;
    cin >> cows;
    vector<int> swaps;
    vector <string> order;
    vector <string> new_order(cows);
    for(int i=0; i<cows; i++){
        int x;
        cin >> x;
        swaps.push_back(x);
    }
    for(int i=0; i<cows; i++){
        string id;
        cin >> id;
        order.push_back(id);
    }
    for(int i = 0; i<cows; i++){
        new_order[swaps[i]-1] = order[i];
    }
    for(string s:new_order){
        cout << s << endl;
    }
}