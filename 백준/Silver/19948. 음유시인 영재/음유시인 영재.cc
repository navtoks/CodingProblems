#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetIdx(char c) {
    if (c == ' ') return 26;
    if (islower(c)) return c - 'a';
    return c - 'A';
}

void Counts(const string& s, vector<int>& arr) {
    --arr[GetIdx(s[0])];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] != s[i]) --arr[GetIdx(s[i])];
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    string s;
    vector<int> arr(27, 0);

    getline(cin, s);
    cin >> arr[26];
    for (int i = 0; i < 26; ++i) cin >> arr[i];

    string title;
    title += toupper(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == ' ' && s[i] != ' ') title += toupper(s[i]);
    }

    Counts(s, arr);
    Counts(title, arr);

    bool flag = false;
    for (const auto& elt : arr) {
        if (elt < 0) flag = true;
    }

    if (flag) cout << -1;
    else cout << title;
    
    return 0;
}