#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s1, s2;

bool IsRearrangeable() {
    vector<int> cnts(26, 0);
    for (const auto& c : s1) ++cnts[c - 'a'];
    for (const auto& c : s2) --cnts[c - 'a'];

    for (const auto& cnt : cnts) {
        if (cnt != 0) return false;
    }
    return true;
}

bool HasSameEnd() {
    return (s1.front() == s2.front()) && (s1.back() == s2.back());
}

bool IsVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool HasSameConsonants() {
    string s;
    for (const auto& c : s1) {
        if (!IsVowel(c)) s += c;
    }
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (IsVowel(s2[idx])) ++idx;
        if (s[i] != s2[idx]) return false;
        ++idx;
    }
    return true;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    cin >> s1 >> s2;

    if (IsRearrangeable() && HasSameEnd() && HasSameConsonants()) cout << "YES";
    else cout << "NO";
    
    return 0;
}