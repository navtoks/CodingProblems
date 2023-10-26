#include <iostream>
using namespace std;
using ll = long long;

ll FindN(ll sum) {
    ll n = 1;
    while (n * n < sum) ++n;
    if (n * n == sum) return n;
    return -1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll x, y;
    cin >> x >> y;

    if (x + y == 0) {
        cout << 0;
        return 0;
    }

    ll n = FindN(x + y);
    ll cnt = 0;
    if (n == -1 || x == 2 || y == 2) cnt = -1;
    else {
        while (x < 2 * n - 1) --n;
        while (x > 0 || x & 1) {
            x -= (2 * n - 1);
            --n;
            ++cnt;
        }
    }
    cout << cnt;
    
    return 0;
}