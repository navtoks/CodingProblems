#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ComputeDivisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }
    sort(begin(divs), end(divs));
    return divs;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;

        auto divs = ComputeDivisors(n);
        int sum = -n;
        for (const auto& elt : divs) sum += elt;

        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < divs.size() - 2; ++i) {
                cout << divs[i] << " + ";
            }
            cout << divs[divs.size() - 2] << '\n';
        }
        else cout << n << " is NOT perfect.\n";
    }

    return 0;
}