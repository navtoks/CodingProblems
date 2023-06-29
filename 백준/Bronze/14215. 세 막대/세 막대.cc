#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int m = max(a, max(b, c));
    if (a + b + c <= 2 * m) cout << (a + b + c - m) * 2 - 1;
    else cout << a + b + c;

    return 0;
}