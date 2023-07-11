#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    unordered_set<string> arr;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            auto temp = s.substr(i, j - i + 1);
            arr.insert(temp);
        }
    }

    cout << arr.size();

    return 0;
}