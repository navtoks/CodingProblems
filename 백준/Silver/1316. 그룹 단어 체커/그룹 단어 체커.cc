#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsGroupWord(const string& s) {
    vector<bool> repeated(26, false);
    repeated[s[0] - 'a'] = true;
    for (int i = 1; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if (s[i] != s[i - 1]) {
            if (repeated[c]) return false;
        }
        repeated[c] = true;
    }
    return true;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (IsGroupWord(s)) ++cnt;
    }
    cout << cnt;

    return 0;
}