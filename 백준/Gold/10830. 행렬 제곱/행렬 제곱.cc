#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using mi = vector<vi>;

void SetMat(mi& mat) {
    for (auto& row : mat) {
        for (auto& elt : row) {
            cin >> elt;
            elt %= 1000;
        }
    }
}

void MultMat(const mi& a, const mi& b, mi& c) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
}

void PowerMat(const mi& a, ll b, mi& result) {
    if (b == 1) {
        result = a;
        return;
    }
    if (b % 2) {
        if (b == 1) result = a;
        else {
            mi temp(a.size(), vi(a.size(), 0));
            PowerMat(a, b - 1, temp);
            MultMat(temp, a, result);
        }
    }
    else {
        mi half(a.size(), vi(a.size(), 0));
        PowerMat(a, b / 2, half);
        MultMat(half, half, result);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n, b;
    cin >> n >> b;
    mi a(n, vi(n));
    SetMat(a);

    mi result(n, vi(n));
    PowerMat(a, b, result);

    for (const auto& row : result) {
        for (const auto& elt : row) cout << elt << ' ';
        cout << '\n';
    }
    
    return 0;
}