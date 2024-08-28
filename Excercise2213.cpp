#include <iostream>
#include <vector>
#include <map>
using namespace std;

int part1(vector<int> s){
    int count = 0;
    sort(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){
        if(s[i] == s[i+1]){
            count++;
        }
    }
    return count;
}
pair<int, int> part2and3(vector<int> s, int v){
    sort(s.begin(), s.end());
    int pointer1 = 0;
    int pointer2 = s.size()-1;
    while(pointer1 != pointer2){
        if(s[pointer1]+s[pointer2]>v){
            pointer2--;
        }
        else if(s[pointer1]+s[pointer2]<v){
            pointer1++;
        }
        else{
            return make_pair(s[pointer1], s[pointer2]);
        }
    }
}
void part4(vector<int> s, int a, int b){
    sort(s.begin(), s.end());
    for(int i=a; i<b+1; i++){
        cout << s[i];
    }
}
vector<int> part5(vector<int> s){
    int pointer1 = 0;
    int pointer2 = 0;
    vector<int> subArray;
    for(int i=0; i<s.size(); i++){
        subArray.push_back(s[pointer2]);
        pointer2++;
        if(s[pointer2]<s[pointer1]){
            pointer1 = pointer2;
            subArray = {};
        }
    }
    return subArray;
}
int part6(vector<int> s){
    sort(s.begin(), s.end());
    return s[(s.size()-1)/2];
}
int part7(vector<int> s){
    map<int, int> numCount;
    for(int i:s){
        numCount[i]++;
        if(numCount[i]>s.size()/2){
            return i;
        }
    }
}