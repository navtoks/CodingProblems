#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& elt : arr) cin >> elt;
    sort(begin(arr), end(arr));

    auto iter = unique(begin(arr), end(arr));
    for (auto i = begin(arr); i != iter; ++i) {
        cout << *i << ' ';
    }

    return 0;
}