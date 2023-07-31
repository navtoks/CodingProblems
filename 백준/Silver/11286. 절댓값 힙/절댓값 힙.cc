#include <iostream>
#include <queue>
using namespace std;

int Abs(int n) {
    return n > 0 ? n : -n;
}

struct Compare {
    bool operator()(int a, int b) {
        int A = Abs(a);
        int B = Abs(b);
        if (A == B) return a > b;
        return A > B;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, Compare> arr;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (arr.empty()) cout << 0 << '\n';
            else {
                cout << arr.top() << '\n';
                arr.pop();
            }
        }
        else arr.push(x);
    }

    return 0;
}