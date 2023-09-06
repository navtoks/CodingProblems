#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll Gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return Gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n, b;
    cin >> n >> b;
    b *= n;

    ll x = 0, y = 0, temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        x += temp;
        cin >> temp;
        y += temp;
    }
    y -= b;

    if (x == 0) cout << "EZPZ";
    else if (y == 0) cout << 0;
    else {
        if (x < 0 && y < 0) x *= -1, y *= -1;
        else if (x < 0) {
            x *= -1;
            cout << '-';
        }
        else if (y < 0) {
            y *= -1;
            cout << '-';
        }

        ll gcd = Gcd(y, x);
        x /= gcd;
        y /= gcd;
        if (x == 1) cout << y;
        else cout << y << '/' << x;
    }

    return 0;
}