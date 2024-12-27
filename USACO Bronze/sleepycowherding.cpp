#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main() {
	int n;
	cin>>n;
	vector <int> v;
	for(int i = 0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	int j = 1;
	int cows = 1;
	int maxcow = 0;
	int x,y;
	for(int i = 0;i<n-1;i++){
		while(v[j] - v[i] + 1 <= n && j < n){
			cows++;
			j++;
		}

		if(j == n){
			if(cows > maxcow){
				x = v[i];
				y = v[j-1];
			}
			maxcow = max(cows,maxcow);

			break;
		}
	}


	return 0;
}