#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr(201, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++arr[x + 100];
    }

    int v;
    cin >> v;
    cout << arr[v + 100];
}