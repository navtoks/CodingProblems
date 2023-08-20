#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int e, s, m;
    cin >> e >> s >> m;

    int n = 1;
    int a = 1, b = 1, c = 1;
    while (e != a || s != b || m != c) {
        a = (a == 15 ? 1 : a + 1);
        b = (b == 28 ? 1 : b + 1);
        c = (c == 19 ? 1 : c + 1);
        ++n;
    }
    cout << n;

    return 0;
}