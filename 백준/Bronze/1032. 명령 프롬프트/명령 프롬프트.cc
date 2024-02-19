#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    string s, input;
    cin >> n >> s;

    input = s;
    int m = input.size();
    while (--n) {
        cin >> s;
        for (int i = 0; i < m; ++i) {
            if (s[i] != input[i]) input[i] = '?';
        }
    }
    cout << input;

    return 0;
}