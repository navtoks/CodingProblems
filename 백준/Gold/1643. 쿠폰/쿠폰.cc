#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll Gcd(ll a, ll b) {
    ll r = a % b;
    if (r) return Gcd(b, r);
    return b;
}

int CountDigits(ll n) {
    int cnt = 0;
    while (n) {
        ++cnt;
        n /= 10;
    }
    return cnt;
}

struct X {
    ll I, N, D;  // integer, numerator, denominator
    void Print(bool is_end) {
        if (N) {
            int d1 = CountDigits(I);
            for (int i = 0; i <= d1; ++i) cout << ' ';
            cout << N << '\n';

            cout << I << ' ';
            int d2 = CountDigits(D);
            for (int i = 0; i < d2; ++i) cout << '-';
            cout << '\n';

            for (int i = 0; i <= d1; ++i) cout << ' ';
            cout << D;
        }
        else cout << I;

        if (!is_end) cout << '\n';
    }
};

vector<X> arr(23);

void Compute() {
    arr[0] = X{0, 0, 1};
    for (ll i = 1; i < 23; ++i) {
        const auto& prev = arr[i - 1];
        auto& now = arr[i];

        now.N = prev.N * i + prev.D;
        now.D = prev.D * i;

        ll gcd = Gcd(now.N, now.D);
        now.N /= gcd;
        now.D /= gcd;

        now.I = prev.I + now.N / now.D;
        now.N %= now.D;
    }

    for (ll i = 1; i < 23; ++i) {
        auto& now = arr[i];
        now.N *= i;
        now.I = now.I * i + now.N / now.D;

        ll gcd = Gcd(now.N, now.D);
        now.D /= gcd;
        now.N = (now.N / gcd) % now.D;
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    Compute();

    vector<int> numbers;
    while (true) {
        int n;
        cin >> n;
        if (cin.eof()) break;

        numbers.push_back(n);
    }

    for (int i = 0; i < numbers.size() - 1; ++i) {
        arr[numbers[i]].Print(false);
    }
    arr[numbers.back()].Print(true);

    return 0;
}