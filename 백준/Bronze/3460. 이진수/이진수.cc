#include <iostream>
#include <vector>
using namespace std;

void Solve(int n) {
    vector<bool> bits;
    while (n) {
        bits.push_back(n % 2);
        n >>= 1;
    }

    for (int i = 0; i < bits.size(); ++i) {
        if (bits[i]) cout << i << ' ';
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solve(n);
    }

    return 0;
}