#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(vector<int>& BIT, int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & (-index); 
    }
    return sum;
}

void updateBIT(vector<int>& BIT, int n, int index, int value) {
    while (index <= n) {
        BIT[index] += value;
        index += index & (-index);
    }
}

int countInversions(vector<int>& arr) {
    int n = arr.size();
    int inversionCount = 0;

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin() + 1;
    }

    vector<int> BIT(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        inversionCount += getSum(BIT, arr[i] - 1);
        updateBIT(BIT, n, arr[i], 1);
    }

    return inversionCount;
}

