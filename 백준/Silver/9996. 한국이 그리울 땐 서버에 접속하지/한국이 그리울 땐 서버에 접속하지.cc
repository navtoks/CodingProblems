#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    string p;
    cin >> n >> p;

    string a, b;
    int i = 0;
    while (p[i] != '*') a += p[i++];
    while (i + 1 < p.size()) b += p[++i];

    int as = a.size(), bs = b.size();

    while (n--) {
        string s;
        cin >> s;

        i = 0;
        bool flag = false;
        for (i = 0; i < a.size(); ++i) {
            flag = (s[i] != a[i]);
            if (flag) break;
        }

        for (i = 0; i < bs; ++i) {
            if (flag) break;
            flag = (s[s.size() - 1 - i] != b[bs - 1 - i]);
        }
        
        if (flag || as + bs > s.size()) cout << "NE\n";
        else cout << "DA\n";
    }

    return 0;
}