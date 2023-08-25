#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vl = vector<ll>;

vl ComputeCoefficients(const vl& x) {
    //  1  1  1  1  x1    1  1  1  1    1  1  1  1    1  1  1  1 
    //  8  4  2  1  x2    7  3  1  0    7  3  1  0    7  3  1  0 
    // 27  9  3  1  x3   26  8  2  0   12  2  0  0   12  2  0  0 
    // 64 16  4  1  x4   63 15  3  0   42  6  0  0    6  0  0  0
    vl coefs(5);
    for (int i = 1; i <= 4; ++i) coefs[i] = x[i];

    for (int i = 1; i <= 3; ++i) coefs[i + 1] -= coefs[1];
    for (int i = 1; i <= 2; ++i) coefs[i + 2] -= (i + 1) * coefs[2];
    coefs[4] -= 3 * coefs[3];

    // coefs[4] == 6a
    coefs[3] = (coefs[3] - 2 * coefs[4]) * 3;  // 6c
    coefs[2] = 6 * coefs[2] - 7 * coefs[4] - 3 * coefs[3];  // 6b
    coefs[1] = 6 * coefs[1] - coefs[4] - coefs[3] - coefs[2];  // 6a
    return coefs;
}

double Polynomial(const vl& coefs, int i) {
    ll mult = 1;
    ll result = 0;
    for (int j = 1; j <= 4; ++j) {
        result += coefs[j] * mult;
        mult *= i;
    }
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vl x(n + 1);
        for (int i = 1; i <= n; ++i) cin >> x[i];

        if (n < 5) cout << "YES\n";
        else {
            auto coefs = ComputeCoefficients(x);

            bool flag = false;
            for (int i = 5; i <= n; ++i) {
                ll now = Polynomial(coefs, i);
                if (now != 6 * x[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) cout << "NO\n";
            else cout << "YES\n";
        }
    }

    return 0;
}