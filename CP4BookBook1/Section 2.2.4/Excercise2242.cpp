#include <iostream>

using namespace std;

int main(){
    long long result = 1;
    for(int i=1; i<25; i++){
        result*=i;
    }
    return result%9317==1;
}