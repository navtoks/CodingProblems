#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (auto& elt : arr) cin >> elt;

    int cnt = 0;
    if (arr[0] == m) ++cnt;
    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i - 1];
        if (arr[i] == m) ++cnt;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] - arr[i] == m) {
                ++cnt;
                break;
            }
        }
    }
    cout << cnt;
    
    return 0;
}