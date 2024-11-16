#include <iostream>
#include <stack>
using namespace std;

int main(){
    freopen("cowfind.in", "r", stdin);
	freopen("cowfind.out", "w", stdout);
    int front_legs_count = 0;
    int back_legs_count = 0;
    int result = 0;
    string input;
    cin >> input;
    //count number of (( and ))
    for(int i=0; i<input.size(); i++){
        if(input[i] == '(' && input[i+1] == '('){
            front_legs_count++;
        }
        if(input[i] == ')' && input[i+1] == ')'){
            back_legs_count++;
            result+=front_legs_count;
            //for each )) we can match any previous ((
        }
    }
    cout << result;
}