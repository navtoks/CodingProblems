#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    int cnt = 0;
    set<string> arr;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "ENTER") {
            cnt += arr.size();
            arr.clear();
        }
        else arr.insert(s);
    }
    if (!arr.empty()) cnt += arr.size();
    cout << cnt;

    return 0;
}