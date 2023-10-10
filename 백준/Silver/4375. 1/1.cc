#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (cin.eof()) break;

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        int cnt = 1, now = 1;
        while (now) {
            now = 10 * now + 1;
            now %= n;
            ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}