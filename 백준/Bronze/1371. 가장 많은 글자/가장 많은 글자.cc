#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<string> arr;
    while (true) {
        string s;
        getline(cin, s);
        if (cin.eof()) break;
        arr.push_back(s);
    }

    vector<int> cnts(26, 0);
    for (const auto& s : arr) {
        for (const auto& c : s) {
            if (c == ' ') continue;
            ++cnts[c - 'a'];
        }
    }

    int max_i = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnts[i] > cnts[max_i]) max_i = i;
    }

    for (int i = 0; i < 26; ++i) {
        if (cnts[i] == cnts[max_i]) cout << static_cast<char>(i + 'a');
    }

    return 0;
}