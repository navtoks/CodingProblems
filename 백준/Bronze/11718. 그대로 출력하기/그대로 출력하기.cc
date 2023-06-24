#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        getline(cin, s);
        if (cin.eof()) break;
        cout << s << '\n';
    }
}