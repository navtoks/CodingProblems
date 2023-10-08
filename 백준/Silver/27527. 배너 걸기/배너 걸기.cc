#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int t;
unordered_map<int, int> cnts;

void ComputeThreshold(int m) {
    t = 9 * m;
    t = (t % 10 ? t / 10 + 1 : t / 10);
}

bool CountHeight(int h) {
    if (cnts.find(h) == end(cnts)) cnts[h] = 1;
    else ++cnts[h];

    return cnts[h] >= t;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto& elt : arr) cin >> elt;
    ComputeThreshold(m);

    int i = 0;
    bool flag = false;
    while (!flag && i < m) {
        flag = CountHeight(arr[i++]);
    }

    while (!flag && i < n) {
        --cnts[arr[i - m]];
        flag = CountHeight(arr[i++]);
    }

    if (flag) cout << "YES";
    else cout << "NO";

    return 0;
}