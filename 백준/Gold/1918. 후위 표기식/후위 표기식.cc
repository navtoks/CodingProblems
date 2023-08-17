#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int Priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void Pop(stack<char>& temp) {
    cout << temp.top();
    temp.pop();
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    stack<char> temp;
    for (const auto& c : s) {
        if (c >= 'A' && c <= 'Z') cout << c;
        else {
            if (temp.empty()) temp.push(c);
            else {
                if (c == ')') {
                    while (temp.top() != '(') Pop(temp);
                    temp.pop();
                }
                else {
                    int now;
                    if (c == '(') now = 3;
                    else now = Priority(c);

                    int top = Priority(temp.top());
                    while (now <= top) {
                        Pop(temp);
                        if (temp.empty()) break;
                        top = Priority(temp.top());
                    }
                    temp.push(c);
                }
            }
        }
    }
    while (!temp.empty()) Pop(temp);
    
    return 0;
}