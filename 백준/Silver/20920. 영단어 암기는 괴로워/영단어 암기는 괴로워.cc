#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

using Pair = pair<string, int>;

bool compare(const Pair& p1, const Pair& p2) {
    if (p1.second == p2.second) return p1.first.length() > p2.first.length();
    return p1.second > p2.second;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<string, int> arr;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.length() < m) continue;

        if (arr.find(s) != end(arr)) ++arr[s];
        else arr.insert({s, 1});
    }

    vector<Pair> lst(arr.size());
    int i = 0;
    for (const auto& elt : arr) {
        lst[i++] = elt;
    }
    stable_sort(begin(lst), end(lst), compare);

    for (const auto& elt : lst) {
        cout << elt.first << '\n';
    }

    return 0;
}