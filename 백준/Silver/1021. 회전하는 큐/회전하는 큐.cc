#include <iostream>
#include <list>
using namespace std;

void Right(list<int>& arr) {
    arr.push_back(arr.front());
    arr.pop_front();
}

void Left(list<int>& arr) {
    arr.push_front(arr.back());
    arr.pop_back();
}

int FindRight(const list<int>& arr, int x) {
    int cnt = 0;
    for (auto iter = begin(arr); iter != end(arr); ++iter) {
        if (*iter == x) break;
        ++cnt;
    }
    return cnt;
}

int FindLeft(const list<int>& arr, int x) {
    int cnt = 0;
    for (auto iter = rbegin(arr); iter != rend(arr); ++iter) {
        ++cnt;
        if (*iter == x) break;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    list<int> arr;
    for (int i = 0; i < n; ++i) {
        arr.push_back(i + 1);
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        int right_cnt = FindRight(arr, x);
        int left_cnt = FindLeft(arr, x);
        if (right_cnt <= left_cnt) {
            cnt += right_cnt;
            while (right_cnt--) {
                Right(arr);
            }
            arr.pop_front();
        }
        else {
            cnt += left_cnt;
            while (left_cnt--) {
                Left(arr);
            }
            arr.pop_front();
        }
    }
    cout << cnt;

    return 0;
}