#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsValid(const string& s) {
    stack<char> arr;
    for (const auto& c : s) {
        if (c == '(') arr.push('(');
        if (c == '[') arr.push('[');
        if (c == ')') {
            if (arr.empty() || arr.top() != '(') return false;
            arr.pop();
        }
        if (c == ']') {
            if (arr.empty() || arr.top() != '[') return false;
            arr.pop();
        }
    }

    if (arr.empty()) return true;
    return false;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);


    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;

        if (IsValid(s)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}