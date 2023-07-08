#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    sort(begin(s), end(s), greater<char>());

    cout << s;
    
    return 0;
}