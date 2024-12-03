#include <iostream>
#include <set>
using namespace std;

int main(){
    int nums;
    cin >> nums;
    set<int> numbers;
    for(int i=0; i<nums; i++){
        int t;
        cin >> t;
        numbers.insert(t);
    }
    cout << numbers.size();
}

