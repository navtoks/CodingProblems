#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = 0, cnt = 0;
    for (const auto& c : s) n += (c - '0');
    if (s.size() != 1) {
        cnt = 1;
        while (n > 9) {
            int now = 0;
            while (n) {
                now += n % 10;
                n /= 10;
            }
            n = now;
            ++cnt;
        }
    }

    cout << cnt << '\n';
    if (n % 3) cout << "NO";
    else cout << "YES";

    return 0;
}