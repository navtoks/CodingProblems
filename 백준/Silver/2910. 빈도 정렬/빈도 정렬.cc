#include <iostream>
#include <map>
using namespace std;

struct X {
    int i, cnt;
    bool operator<(const X& o) const {
        if (cnt == o.cnt) return i < o.i;
        return cnt > o.cnt;
    }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;

    map<int, X> arr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (arr.find(x) == end(arr)) arr.insert({x, X{i, 1}});
        else ++arr[x].cnt;
    }
    
    map<X, int> sorted;
    for (const auto& elt : arr) {
        sorted.insert({elt.second, elt.first});
    }

    for (const auto& elt : sorted) {
        for (int i = 0; i < elt.first.cnt; ++i) {
            cout << elt.second << ' ';
        }
    }

    return 0;
}