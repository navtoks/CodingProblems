#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    vector<int> arr(26, 0);
    for (const auto& c : a) ++arr[c - 'a'];
    for (const auto& c : b) --arr[c - 'a'];

    int cnt = 0;
    for (const auto& elt : arr) {
        if (elt < 0) cnt -= elt;
        else cnt += elt;
    }
    cout << cnt;
    
    return 0;
}