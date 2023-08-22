#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;

    // stack : pop the pushed (new) element  ->  ignore
    // queue : pop the prev element and push new element
    vector<int> ds(n);
    for (auto& elt : ds) cin >> elt;

    vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (ds[i]) continue;
        arr.push_back(x);
    }
    n = arr.size();

    cin >> m;
    vector<int> seq(m + n);
    // pre-defined queue elements are printed with backward order, and sequence elements are printed with forward order.
    for (int i = 0; i < n; ++i) seq[i] = arr[n - 1 - i];
    for (int i = 0; i < m; ++i) cin >> seq[i + n];

    for (int i = 0; i < m; ++i) cout << seq[i] << ' ';

    return 0;
}