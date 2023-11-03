#include <iostream>
using namespace std;

int Gcd(int a, int b) {
    int r = a % b;
    if (r) return Gcd(b, r);
    return b;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int gcd, lcm;
    cin >> gcd >> lcm;

    int ab = lcm / gcd;

    int a;
    for (int i = 1; i * i <= ab; ++i) {
        if (ab % i) continue;
        if (Gcd(i, ab / i) == 1) a = i;
    }

    cout << a * gcd << ' ' << lcm / a;

    return 0;
}