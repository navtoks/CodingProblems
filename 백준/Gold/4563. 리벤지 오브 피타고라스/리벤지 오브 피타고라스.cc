#include <iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        ll a;
        cin >> a;
        if (a == 0) break;


        int cnt = 0;
        ll n = a * a;
        for (ll i = 1; i <= a; ++i) {
            if (n % i) continue;
            ll j = n / i;
            ll c2 = i + j, b2 = j - i;
            if (b2 <= 2 * a) break;
            if ((c2 & 1) && (b2 & 1)) continue;
            ++cnt;
        }

        cout << cnt << '\n';
    }

    return 0;
}