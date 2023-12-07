#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> arr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push(x);
    }

    int sum = 0;
    while (arr.size() > 1) {
        int a = arr.top();  arr.pop();
        int b = arr.top();  arr.pop();
        ++sum;
        --a;
        --b;
        if (a) arr.push(a);
        if (b) arr.push(b);
    }

    if (!arr.empty()) sum += arr.top();

    if (sum > 1440) cout << -1;
    else cout << sum;
    
    return 0;
}