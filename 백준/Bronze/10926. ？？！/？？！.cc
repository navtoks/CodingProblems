#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    // cout << s << "??!";
    // warning: trigraph ??! ignored, use -trigraphs to enable [-Wtrigraphs]

    cout << s << '?' << '?' << '!';
}