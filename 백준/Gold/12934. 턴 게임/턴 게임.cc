#include <iostream>
using namespace std;
using ll = long long;

ll FindN(ll sum) {
    sum <<= 1;
    ll n = 1;
    while (n * (n + 1) < sum) ++n;
    if (n * (n + 1) == sum) return n;
    return -1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll x, y;
    cin >> x >> y;

    ll n = FindN(x + y);
    if (n == -1) cout << -1;
    else {
        ll cnt = 0;
        while (x > 0) {
            x -= n--;
            ++cnt;
        }
        cout << cnt;
        
    }
    
    return 0;
}