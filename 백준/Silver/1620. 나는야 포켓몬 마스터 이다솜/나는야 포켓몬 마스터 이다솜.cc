#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    unordered_map<int, string> num_dict;
    unordered_map<string, int> str_dict;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        num_dict.insert({i + 1, s});
        str_dict.insert({s, i + 1});
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            int x = stoi(s);
            cout << num_dict[x] << '\n';
        }
        else {
            cout << str_dict[s] << '\n';
        }
    }

    return 0;
}