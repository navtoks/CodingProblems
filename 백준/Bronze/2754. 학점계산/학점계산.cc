#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    if (s == "F") cout << "0.0";
    else {
        double score = 'D' - s[0] + 1;
        if (s[1] == '+') score += 0.3;
        else if (s[1] == '-') score -= 0.3;

        cout.precision(1);
        cout << fixed << score;
    }
}