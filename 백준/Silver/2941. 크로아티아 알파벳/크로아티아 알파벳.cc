#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '-') --i;
        else if (s[i] == '=') {
            --i;
            if (i > 0 && s[i] == 'z' && s[i - 1] == 'd') --i;
        }
        else if (s[i] == 'j') {
            if (i > 0 && (s[i - 1] == 'n' || s[i - 1] == 'l')) --i;
        }

        ++cnt;
    }
    cout << cnt;

    return 0;
}