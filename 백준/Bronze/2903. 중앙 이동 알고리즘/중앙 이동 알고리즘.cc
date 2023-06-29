#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int base = 3;
    for (int i = 1; i < n; ++i) {
        base += (1 << i);
    }
    cout << base * base;

    return 0;
}