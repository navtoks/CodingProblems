#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 10'003'001;

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

bool IsPalindrome(int n) {
    const auto& s = to_string(n);

    int sz = s.size();
    for (int i = 0; i < sz / 2; ++i) {
        if (s[i] != s[sz - 1 - i]) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    EratosthenesSieve();

    int n;
    cin >> n;
    for (int i = n; i <= N; ++i) {
        if (primes[i] && IsPalindrome(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}