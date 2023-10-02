#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using V = vector<ll>;
using M = vector<V>;
#define FOR(i) for (int i = 0; i < 2; ++i)

const ll N = 1'000'000'007;
const M base{{1, 1}, {1, 0}};

M MultMat(const M& a, const M& b) {
    M result(2, V(2, 0));
    FOR(i) FOR(j) {
        FOR(k) result[i][j] += a[i][k] * b[k][j];
        result[i][j] %= N;
    }
    return result;
}

M ComputeFiboMat(ll n) {
    if (n == 1) return base;

    M half = ComputeFiboMat(n / 2);
    M result = MultMat(half, half);
    if (n % 2) return MultMat(result, base);
    return result;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    M result = ComputeFiboMat(n);
    cout << result[1][0];

    return 0;
}