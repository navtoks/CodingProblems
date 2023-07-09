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

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (primes[i]) ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}