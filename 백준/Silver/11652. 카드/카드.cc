#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (auto& elt : arr) cin >> elt;
    sort(begin(arr), end(arr));

    ll cnt = 0, now = arr[0];
    ll max_cnt = 0, max_value = now;
    for (const auto& elt : arr) {
        if (elt != now) {
            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_value = now;
            }
            cnt = 1;
            now = elt;
        }
        else ++cnt;
    }

    if (now == arr[n - 1] && cnt > max_cnt) max_value = now;

    cout << max_value;

    return 0;
}