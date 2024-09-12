#include <iostream>
#include <vector>
using namespace std;

int main(){
    int people;
    while(true){
        cin >> people;
        vector<string> names(people);
        if(people == 0) break;
       for (int i = 0; i < people; ++i) {
            cin >> names[i];
        }

        string result = "";
        sort(names.begin(), names.end());
        string mid1 = names[people/2-1];
        string mid2 = names[people/2];
        result = mid1;
        for (int i = result.size(); i >= 0; --i) {
            if (result[i] < 'Z') {
                result[i]++;
                if (result < mid2) {
                    break;
                }
                result[i]--;
            } else {
                result[i] = 'A';
            }
        }

        cout << result << endl;
    }
}
