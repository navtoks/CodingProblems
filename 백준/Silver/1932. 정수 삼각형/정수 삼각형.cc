#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vi> arr(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) cin >> arr[i][j];
    }

    for (int i = 1; i < n; ++i) {
        auto& now = arr[i];
        const auto& prev = arr[i - 1];
        now[0] += prev[0];
        for (int j = 1; j <= i; ++j) {
            now[j] += max(prev[j], prev[j - 1]);
        }
    }

    const auto& result = arr.back();
    cout << *max_element(begin(result), end(result));
    
    return 0;
}