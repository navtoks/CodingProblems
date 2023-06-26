#include <iostream>
#include <string>
using namespace std;

int ToNumber(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string n;
    int b;
    cin >> n >> b;

    int result = 0;
    int mult = 1;
    for (int i = n.size() - 1; i >= 0; --i) {
        result += mult * ToNumber(n[i]);
        mult *= b;
    }
    cout << result;

    return 0;
}