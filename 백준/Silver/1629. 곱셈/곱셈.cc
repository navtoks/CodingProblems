#include <iostream>
using namespace std;
using ll = long long;

ll Mult(ll base, ll power, ll mod) {
    if (power == 1) return base % mod;
    if (power % 2) {
        ll temp = Mult(base, power - 1, mod) % mod;
        return (temp * base) % mod;
    }
    ll half = Mult(base, power / 2, mod) % mod;
    return (half * half) % mod;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << Mult(a, b, c);

    return 0;
}