#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> arr(26, -1);
    for (int i = 0; i < s.size(); ++i) {
        int now = s[i] - 'a';
        if (arr[now] == -1) {
            arr[now] = i;
        }
    }

    for (const auto& elt : arr) cout << elt << ' ';
}