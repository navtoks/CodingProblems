#include <iostream>
#include <vector>
using namespace std;

const int N = 1'000'000;
vector<bool> primes(N + 1, true);

void EratosthenesSieve() {
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= N; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    EratosthenesSieve();

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int i = 2;
        while (true) {
            if (primes[i] && primes[n - i]) break;
            ++i;
        }

        cout << n << " = " << i << " + " << n - i << '\n';
    }

    return 0;
}