#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    int n = s.size();

    int i = 0;
    vector<string> arr;
    while (i < n) {
        if (s[i] == '<') {
            arr.push_back("");
            while (s[i] != '>' && i < n) arr.back() += s[i++];
            arr.back() += s[i++];
        }
        else {
            arr.push_back("");
            if (s[i] == ' ') arr.back() += s[i++];
            while (s[i] != ' ' && s[i] != '<' && i < n) arr.back() += s[i++];
        }
    }

    for (const auto& elt : arr) {
        if (elt[0] == '<') cout << elt;
        else {
            n = 0;
            if (elt[0] == ' ') {
                cout << ' ';
                ++n;
            }
            for (i = elt.size() - 1; i >= n; --i) cout << elt[i];
        }
    }

    return 0;
}