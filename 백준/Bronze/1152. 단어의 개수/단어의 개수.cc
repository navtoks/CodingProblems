#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    int cnt = 0;
    for (const auto& c : s) {
        if (c == ' ') ++cnt;
    }

    if (s.front() == ' ') --cnt;
    if (s.back() == ' ') --cnt;

    cout << cnt + 1;
}