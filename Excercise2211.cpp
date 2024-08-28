#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool custom_comparison(const tuple<int, string, string>& a, const tuple<int, string, string>& b) {
    if (get<0>(a) != get<0>(b)) {
        return get<0>(a) > get<0>(b);
    }
    if (get<1>(a) != get<1>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<2>(a) < get<2>(b);
}

int main() {
    vector<tuple<int, string, string>> people; 
    int id;
    string first_name, last_name;

    while (cin >> id >> first_name >> last_name) {
        people.emplace_back(id, first_name, last_name);
    }

    sort(people.begin(), people.end(), custom_comparison);

    for (const auto& person : people) {
        cout << get<0>(person) << ' ' << get<1>(person) << ' ' << get<2>(person) << endl;
    }
 
    return 0;
}
