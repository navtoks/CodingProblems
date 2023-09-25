#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    const ll M = 1'000'000'000;

    int n;
    cin >> n;

    vector<ll> arr(10, 0);
    for (int i = 1; i < 10; ++i) arr[i] = 1;  // when n = 1

    for (int i = 2; i <= n; ++i) {
        vector<ll> now(10, 0);
        // 0 -> 1
        // 1 -> 0, 2 / 2 -> 1, 3 / ... / 7 -> 6, 8 / 8 -> 7, 9
        // 9 -> 8
        now[1] = arr[0];
        for (int j = 1; j < 9; ++j) {
            now[j - 1] += arr[j];
            now[j + 1] = arr[j];
        }
        now[8] += arr[9];
        for (auto& elt : now) elt %= M;
        arr = now;
    }

    ll sum = 0;
    for (const auto& elt : arr) sum += elt;
    cout << sum % M;

    return 0;
}