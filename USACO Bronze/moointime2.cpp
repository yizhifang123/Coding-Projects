#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> substr_count;
    int N, F;
    cin >> N >> F;
    string str;
    cin >> str;
    set<string> v;
    set<string> temp;
    for (int i = 0; i + 2 < str.size(); i++) {
        string substr = str.substr(i, 3);
        if (substr[0] != substr[1] && substr[1] == substr[2]) { 
            substr_count[substr]++;
            if (substr_count[substr] == F - 1) {
                temp.insert(substr);
            }
            if (substr_count[substr] == F) {
                v.insert(substr);
                temp.erase(substr);
            }
        }
    }

    for (string s : temp) {
        bool found = false;
        for (int i = 0; i < str.size(); i++) {
            char original_char = str[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original_char) continue; 
                int change = 0;

                for (int k = i - 2; k <= i; k++) {
                    if (k < 0 || k + 2 >= str.size()) continue;

                    string s_old = str.substr(k, 3);
                    string s_new = s_old;
                    s_new[i - k] = c;

                    bool s_old_is_moo = (s_old[0] != s_old[1] && s_old[1] == s_old[2] && s_old == s);
                    bool s_new_is_moo = (s_new[0] != s_new[1] && s_new[1] == s_new[2] && s_new == s);

                    if (s_old_is_moo && !s_new_is_moo) {
                        change -= 1;
                    }
                    else if (!s_old_is_moo && s_new_is_moo) {
                        change += 1;
                    }
                }

                if (change >= 1) {
                    v.insert(s);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    vector<string> result(v.begin(), v.end());
    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}
