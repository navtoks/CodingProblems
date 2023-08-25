#include <iostream>
#include <vector>
using namespace std;

int FindMaxIdx(const vector<int>& arr) {
    int idx = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= arr[idx]) idx = i;
    }
    return idx;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& elt : arr) cin >> elt;

    int cnt = 0;
    while (true) {
        int max_idx = FindMaxIdx(arr);
        if (max_idx == 0) break;
        --arr[max_idx];
        ++arr[0];
        ++cnt;
    }
    cout << cnt;
    
    return 0;
}