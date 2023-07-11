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

    int m = *min_element(begin(arr), end(arr));
    int M = *max_element(begin(arr), end(arr));
    cout << m * M;

    return 0;
}