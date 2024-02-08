#include <iostream>
#include <vector>
using namespace std;

vector<bool> primes(1001, true);

int EratosthenesSieve(int n, int k) {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            if (k == ++cnt) return i;
            for (int j = i * i; j <= n; j += i) {
                if (!primes[j]) continue;
                if (k == ++cnt) return j;
                primes[j] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    cout << EratosthenesSieve(n, k);
    
    return 0;
}