#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    queue<int> arr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push(x);
    }

    int order = 1;
    stack<int> temp;
    while (order <= n) {
        if (!arr.empty() && order == arr.front()) {
            ++order;
            arr.pop();
            continue;
        }
        if (!temp.empty() && order == temp.top()) {
            ++order;
            temp.pop();
            continue;
        }

        if (arr.empty()) {
            if (order != temp.top()) break;
            ++order;
            temp.pop();
            continue;
        }

        temp.push(arr.front());
        arr.pop();
    }

    if (order > n) cout << "Nice";
    else cout << "Sad";

    return 0;
}