#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int ones = 0, zeros = 0;
    if (s[0] == '1') ++ones;
    else ++zeros;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '1') ++ones;
            else ++zeros;
        }
    }
    cout << min(ones, zeros);

    return 0;
}