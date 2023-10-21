#include <iostream>
#include <string>
using namespace std;

string s;
string vowels{"AEIOU"};

bool IsVowel(char c) {
    for (const auto& v : vowels) {
        if (c == v) return true;
    }
    return false;
}

int FindA(int start) {
    for (int i = start - 1; i >= 0; --i) {
        if (s[i] == 'A') return i;
    }
    return -1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m >> s;

    int i;
    for (i = s.size() - 1; i >= 0; --i) {
        if (!IsVowel(s[i])) break;
    }
    if (i == 0) {
        cout << "NO";
        return 0;
    }

    string result{s[i]};
    i = FindA(i);
    if (i == -1) {
        cout << "NO";
        return 0;
    }

    i = FindA(i);
    if (i == -1) {
        cout << "NO";
        return 0;
    }
    result += "AA";

    for (int j = 0; j < m - 3; ++j) {
        if (i - j > 0) result += s[i - j - 1];
        else break;
    }

    if (result.size() != m) cout << "NO";
    else {
        if (!IsVowel(result[0]) && result[1] == 'A' && result[2] == 'A') {
            cout << "YES\n";
            for (i = m - 1; i >= 0; --i) cout << result[i];
        }
    }

    return 0;
}