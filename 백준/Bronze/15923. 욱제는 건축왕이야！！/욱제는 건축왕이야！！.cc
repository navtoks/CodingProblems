#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int diff;
        int next = (i + 1) % n;
        if (x[i] == x[next]) diff = y[i] - y[next];
        else diff = x[i] - x[next];
        result += (diff > 0 ? diff : -diff);
    }
    cout << result;

    return 0;
}