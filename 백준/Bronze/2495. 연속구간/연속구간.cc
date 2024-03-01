#include <iostream>
#include <string>
using namespace std;

int CountMaxContLength(const string& s) {
    int n = s.size();
    int cnt = 1, max_cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == s[i]) ++cnt;
        else {
            if (cnt > max_cnt) max_cnt = cnt;
            cnt = 1;
        }
    }
    if (cnt > max_cnt) max_cnt = cnt;

    return max_cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        cout << CountMaxContLength(s) << '\n';
    }

    return 0;
}