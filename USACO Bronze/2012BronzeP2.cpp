#include <iostream>
using namespace std;

int main(){
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);

    string input;
    cin >> input;
    int f_count = 0;
    int b_count = 0;
    int result = 0;
    int balance = 0;
    bool start = false;
    for(char c: input){
        if (c == '('){
            f_count++;
        }
        else
        {
            b_count++;
        }
    }
    if(abs(f_count-b_count) == 1){
        cout << 0;
    }
    else if(f_count>b_count){
        for(int i=0; i<input.size(); i++){
            if (input[i] == '(' && !start)
            {
                start = true;
            }
            else if(input[i] == '(' && start){
                result++;
            }
        }
    }
    else if(f_count<b_count){
        for(int i=input.size(); i>0; i--){
            if (input[i] == ')' && !start)
            {
                start = true;
            }
            else if(input[i] == ')' && start){
                result++;
            }
        }
    }
    cout << result;
}