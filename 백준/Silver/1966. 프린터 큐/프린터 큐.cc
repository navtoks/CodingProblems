#include <iostream>
#include <deque>
using namespace std;

struct X {
    int i, p;
};

int FindMaxPriority(const deque<X>& arr) {
    int max_priority = 0;
    for (const auto& elt : arr) {
        if (elt.p > max_priority) max_priority = elt.p;
    }
    return max_priority;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        deque<X> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i].i = i;
            cin >> arr[i].p;
        }

        for (int i = 1; i <= n; ++i) {
            int max_priority = FindMaxPriority(arr);
            while (arr[0].p < max_priority) {
                arr.push_back(arr[0]);
                arr.pop_front();
            }
            if (arr[0].i == m) {
                cout << i << '\n';
                break;
            }
            else arr.pop_front();
        }
    }

    return 0;
}