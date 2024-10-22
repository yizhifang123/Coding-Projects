#include <iostream>
#include <vector>

using namespace std;

const int n = 10;
int square[n][n];

void part1(){
    int newSquare[n][n];
    int temp = 0;
    for(int i=0; i<n; i++){
        for(int l=n-1; l>=0; l--){
            newSquare[0][temp] = square[i][l];
            temp++;
        }
        temp=0;
    }
    //square = newSquare;
    //copy all values of new square on square
}
void part2(){
    int newSquare[n][n];
    for(int i=0; i<n; i++){
        for(int l=0; l<n; l++){
            newSquare[i][l] = square[l][i];
        }
    }
    //square = newSquare;
    //copy all values of new square on square
}
void part3(){
    //use same strategy from part one and part 2
    //when flipping across y axis just reverse columns
    //when flipping across x axis reverse rows
}