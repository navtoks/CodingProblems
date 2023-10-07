#include <iostream>
#include <vector>
using namespace std;

const int N = 10'000;
vector<bool> primes(N + 1, true);

void EratosthenesSieve() {
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (primes[i]) {
            for (int j = i * i; j < N; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    EratosthenesSieve();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        for (int i = n / 2; i > 1; --i) {
            if (primes[i] && primes[n - i]) {
                cout << i << ' ' << n - i << '\n';
                break;
            }
        }
    }


    return 0;
}