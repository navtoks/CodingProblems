#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string& s1, const string& s2) {
    if (s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> arr(n);
    for (auto& elt : arr) cin >> elt;
    sort(begin(arr), end(arr), compare);

    auto iter = unique(begin(arr), end(arr));
    arr.erase(iter, end(arr));

    for (const auto& elt : arr) cout << elt << '\n';
    
    return 0;
}