#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) cout << ' ';
        for (int j = 0; j < 2 * i - 1; ++j) cout << '*';
        cout << '\n';
    }
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j) cout << ' ';
        for (int j = 0; j < 2 * i - 1; ++j) cout << '*';
        cout << '\n';
    }
}