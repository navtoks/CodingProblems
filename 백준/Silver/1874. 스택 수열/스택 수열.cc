#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& elt : arr) cin >> elt;

    int top = 0;
    stack<int> checker;
    string result;
    for (const auto& elt : arr) {
        while (top < elt) {
            checker.push(++top);
            result += '+';
        }
        if (checker.top() == elt) {
            checker.pop();
            result += '-';
        }
        else {
            checker.push(top);
            break;
        }
    }

    if (checker.empty()) {
        for (const auto& c : result) cout << c << '\n';
    }
    else cout << "NO";

    return 0;
}