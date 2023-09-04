#include <iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        ll x, y, n, dist;
        cin >> x >> y;
        dist = y - x;

        // [n**2 + 1, n**2 + n] -> 2 * n
        // [n**2 + n + 1, (n + 1)**2] -> 2 * n + 1
        n = 1;  
        while (n * n < dist) ++n;
        --n;
        if (dist <= n * n + n) cout << 2 * n << '\n';
        else cout << 2 * n + 1 << '\n';
    }
    
    return 0;
}