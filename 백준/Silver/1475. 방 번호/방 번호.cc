#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> arr(9, 0);
    for (const auto& c : s) {
        if (c == '9') ++arr[6];
        else ++arr[c - '0'];
    }
    if (arr[6] % 2) arr[6] = arr[6] / 2 + 1;
    else arr[6] /= 2;
    cout << *max_element(begin(arr), end(arr));

    return 0;
}