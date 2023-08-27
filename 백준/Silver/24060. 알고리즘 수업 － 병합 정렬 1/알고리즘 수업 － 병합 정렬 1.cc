#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> temp;
int n, k, cnt = 0;
int val = -1;

void Merge(int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) temp[t++] = arr[i++];
        else temp[t++] = arr[j++];
    }
    while (i <= q) temp[t++] = arr[i++];
    while (j <= r) temp[t++] = arr[j++];
    
    i = p, t = 0;
    while (i <= r) {
        arr[i++] = temp[t++];
        ++cnt;
        if (k == cnt) val = arr[i - 1];
    }
}

void MergeSort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(p, q);
        MergeSort(q + 1, r);
        Merge(p, q, r);
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> n >> k;

    arr = vector<int>(n);
    temp = vector<int>(n);
    for (auto& elt : arr) cin >> elt;

    MergeSort(0, n - 1);
    cout << val;

    return 0;
}