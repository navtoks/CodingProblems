#include <iostream>
#include <string>
using namespace std;

void AddString(string& temp, const string& a) {
    for (auto i = rbegin(a); i != rend(a); ++i) temp += *i;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();
    string result = "z";
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string a, b, c;
            a = s.substr(0, i);
            b = s.substr(i, j - i);
            c = s.substr(j, n - j);

            string temp;
            AddString(temp, a);
            AddString(temp, b);
            AddString(temp, c);
            if (temp < result) result = temp;
        }
    }
    cout << result;

    return 0;
}