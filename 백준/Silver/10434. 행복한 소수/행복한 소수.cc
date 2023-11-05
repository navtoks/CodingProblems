#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<bool> primes(10001, true);

void EratosthenesSieve() {
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= 10000; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                primes[j] = false;
            }
        }
    }
}

int DigitSquareSum(int n) {
    int sum = 0;
    while (n != 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

void Solve(int m) {
    if (!primes[m]) {
        cout << "NO\n";
        return;
    }

    set<int> checked;
    while (true) {
        m = DigitSquareSum(m);
        if (m == 1) {
            cout << "YES\n";
            return;
        }
        if (checked.find(m) != end(checked)) {
            cout << "NO\n";
            return;
        }
        checked.insert(m);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    EratosthenesSieve();

    int p;
    cin >> p;
    while (p--) {
        int t, m;
        cin >> t >> m;

        cout << t << ' ' << m << ' ';
        Solve(m);
    }

    return 0;
}