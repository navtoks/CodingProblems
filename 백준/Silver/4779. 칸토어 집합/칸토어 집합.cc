#include <iostream>
#include <string>
using namespace std;

void CantorSet(string& s, int n, int start) {
    if (n == 1) return;
    n /= 3;
    for (int i = 0; i < n; ++i) s[start + n + i] = ' ';
    CantorSet(s, n, start);
    CantorSet(s, n, start + 2 * n);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (cin.eof()) break;

        int l = 1;
        while (n--) l *= 3;

        string s(l, '-');
        CantorSet(s, l, 0);
        cout << s << '\n';
    }

    return 0;
}