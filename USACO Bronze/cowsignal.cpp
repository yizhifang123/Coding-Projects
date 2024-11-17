#include<iostream>

using namespace std;

int main() {
  freopen("cowsignal.in","r",stdin);
  freopen("cowsignal.out","w",stdout);
    int height, width, scale;
    cin >> height >> width >> scale;
    char signal[10][10];
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            cin >> signal[i][j];
        }
    }
    for(int i = 0; i < height; i++) {
        for(int l = 0; l < scale; l++) {
            for(int j = 0; j < width; j++) {
                for(int k = 0; k < scale; k++) {
                    cout << signal[i][j];
                }
            }
        }
    }
}