#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 3 * i * (i + 1) / 2;
    }
    cout << sum;

    return 0;
}