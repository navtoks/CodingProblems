#include <iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll prev = 1, now = 1;
    for (ll i = 3; i <= n; ++i) {
        ll temp = (now + prev) % 1'000'000'007;
        prev = now;
        now = temp;
    }
    cout << now << ' ' << n - 2LL;

    return 0;
}