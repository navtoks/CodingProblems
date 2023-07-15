#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsValid(const string& s) {
    stack<char> arr;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') arr.push('(');
        else {
            if (arr.empty()) return false;
            arr.pop();
        }
    }

    if (arr.empty()) return true;
    return false;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (IsValid(s)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}