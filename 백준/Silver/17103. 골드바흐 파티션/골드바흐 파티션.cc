#include <iostream>
#include <vector>
using namespace std;

vector<bool> EratosthenesSieve(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    auto primes = EratosthenesSieve(1'000'000);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        int cnt = 0;
        for (int i = 2; i <= n / 2; ++i) {
            if (primes[i] && primes[n - i]) ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}