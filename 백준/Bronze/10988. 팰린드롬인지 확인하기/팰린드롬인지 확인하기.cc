#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(const string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << IsPalindrome(s);
}