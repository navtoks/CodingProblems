#include <iostream>
#include <list>
using namespace std;

struct X {
    int x, idx;
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    list<X> arr;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }

    int dist = 0;
    auto iter = begin(arr);
    while (n--) {
        if (dist >= 0) {
            while (dist--) {
                ++iter;
                if (iter == end(arr)) iter = begin(arr);
            }
        }
        else {
            dist *= -1;
            while (dist--) {
                if (iter == begin(arr)) iter = end(arr);
                --iter;
            }
        }
        dist = iter->x;
        cout << iter->idx << ' ';
        iter = arr.erase(iter);
        if (dist > 0) {
            if (iter == begin(arr)) iter = end(arr);
            --iter;
        }
    }

    return 0;
}