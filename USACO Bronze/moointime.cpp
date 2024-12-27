#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;


int main(){
    map<string, int> substr_count;
    int N, F;
    cin >> N >> F;
    string str;
    cin >> str;
    set<string> v;
    set<string> temp;
    for (int i = 0; i + 2 < str.size(); i++) {
        string substr = str.substr(i, 3);
        substr_count[substr]++;
        if(substr_count[substr] == F-1){
            temp.insert(substr);
        }
        if(substr_count[substr] == F){
            v.insert(substr);
            temp.erase(substr);
        }
    }
    for(string s: temp){
        char m = s[0];
        char o = s[1];
        char o2 = s[2];
        //search for instance of substring with 2 similarities to string s and if found push s to vector v
    }
    sort(v.begin(), v.end());
    for(string s:v){
        cout << s;
    }
}