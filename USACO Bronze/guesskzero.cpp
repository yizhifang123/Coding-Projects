#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t; 
    cin >> n >> t;
	int k;
    cin >> k;
	int low = 1;
	int hign = n;
	int onePresent = -1;
	while(low < hign){
		int mid = low + (hign - low)/2;
		cout << "? " << low << " " << mid <<"\n";
		cout.flush();
		cin >> onePresent;
		int zeroPresent = (mid - low + 1) - onePresent;
		if(zeroPresent < k){
			low = mid + 1;
			k -= zeroPresent;
		} else {
			hign = mid;
		}
		
	}
	cout << "! " << low <<"\n";
	cout.flush();
}