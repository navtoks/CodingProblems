#include <iostream>
#include <list>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    list<int> arr;
    for (int i = 0; i < n; ++i) {
        arr.push_back(i + 1);
    }

    cout << '<';
    auto iter = begin(arr);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < k - 1; ++j) {
            ++iter;
            if (iter == end(arr)) iter = begin(arr);
        }
        cout << *iter << ", ";
        iter = arr.erase(iter);
        if (iter == end(arr)) iter = begin(arr);
    }
    cout << arr.front() << '>';

    return 0;
}