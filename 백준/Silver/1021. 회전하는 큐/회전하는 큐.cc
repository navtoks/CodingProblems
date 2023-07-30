#include <iostream>
#include <list>
using namespace std;

list<int> arr;

void RotateRight() {
    arr.push_back(arr.front());
    arr.pop_front();
}

void RotateLeft() {
    arr.push_front(arr.back());
    arr.pop_back();
}

int CountRight(int x) {
    int cnt = 0;
    for (const auto& elt : arr) {
        if (elt == x) break;
        ++cnt;
    }
    return cnt;
}

int CountLeft(int x) {
    int cnt = 0;
    for (auto iter = rbegin(arr); iter != rend(arr); ++iter) {
        ++cnt;
        if (*iter == x) break;
    }
    return cnt;
}

int Process(int x) {
    int cnt_r = CountRight(x);
    int cnt_l = CountLeft(x);

    int cnt = min(cnt_r, cnt_l);
    if (cnt_r <= cnt_l) {
        while (cnt_r--) RotateRight();
    }
    else {
        while (cnt_l--) RotateLeft();
    }
    arr.pop_front();

    return cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        arr.push_back(i + 1);
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cnt += Process(x);
    }
    cout << cnt;

    return 0;
}