#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> primes;
const int N = 200;

void EratosthenesSieve() {
    vector<bool> is_primes(N + 1, true);
    is_primes[0] = is_primes[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (is_primes[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (is_primes[i]) primes.insert(i);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    EratosthenesSieve();

    int n;
    cin >> n;

    auto iter = begin(primes);
    while (true) {
        int now = *iter;
        now *= *(++iter);
        if (now > n) {
            cout << now;
            break;
        }
    }
    
    return 0;
}