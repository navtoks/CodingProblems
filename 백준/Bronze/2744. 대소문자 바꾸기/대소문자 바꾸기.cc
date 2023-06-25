#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    for (auto& c : s) {
        if (islower(c)) c = toupper(c);
        else c = tolower(c);
    }
    cout << s;
}