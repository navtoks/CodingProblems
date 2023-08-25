#include <iostream>
#include <string>
using namespace std;

string s;

void Overwrite(int i, char c) {
    int n;
    if (c == 'A') n = 4;
    else n = 2;
    for (int j = 0; j < n; ++j) s[i + j] = c;
}

bool HasXs(int i) {
    return s[i] == 'X' && s[i + 1] == 'X';
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> s;

    int i = 0;
    int n = s.size();
    while (i < n) {
        if (i + 1 < n && HasXs(i)) {
            i += 2;
            if (i + 1 < n && HasXs(i)) {
                Overwrite(i - 2, 'A');
                i += 2;
            }
            else Overwrite(i - 2, 'B');
        }
        else ++i;
    }

    bool flag = false;
    for (const auto& c : s) {
        if (c == 'X') flag = true;
    }

    if (flag) cout << -1;
    else cout << s;

    return 0;
}