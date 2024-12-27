#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int round_num(int num, int b) {
    int powerOf10 = pow(10, b);
    return round(static_cast<double>(num) / powerOf10) * powerOf10;
}
bool invalid_num(string s){
    int length = s.length();
    int num = stoi(s);
    int chain = num;
    for(int b = 1; b <= length; b++){
        chain = round_num(chain, b);
    }
    int normal = round_num(num, length);
    return normal != chain;
}
int first_digit(int n) {
    int k = static_cast<int>(log10(n));
    int divisor = static_cast<int>(pow(10, k));
    int first_digit = n / divisor;
    return first_digit;
}

int main(){
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> Ns(n);
    for(int i = 0; i < n; i++){
        cin >> Ns[i];
    }
    vector<int> copy = Ns;      
    sort(copy.begin(), copy.end());

    int count = 0;
    for(int num = 2; num <= copy[n-1]; num++){
        if(first_digit(num) == 4){
            if(invalid_num(to_string(num))){
                count++;
            }
        }
        m[num] = count;
    }
    for(int i:Ns){
        cout << m[i] << endl;
    }
    return 0;
}
