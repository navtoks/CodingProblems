#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int sum = 0, temp = 0, sign = 1;
    for (const auto& c : s) {
        if (c == '+' || c == '-') {
            sum += sign * temp;
            temp = 0;
        }
        else {
            temp = temp * 10 + (c - '0');
        }

        if (c == '-') sign = -1;
    }
    sum += sign * temp;

    cout << sum;

    return 0;
}