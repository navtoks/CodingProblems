#include <iostream>
#include <string>
using namespace std;

bool LogicGate(double w1, double w2, double b, string s) {
    double r00 = b;
    double r10 = w1 + b;
    double r01 = w2 + b;
    double r11 = w1 + w2 + b;

    if (s == "AND") return r00 < 0 && r10 < 0 && r01 < 0 && r11 >= 0;
    return r00 < 0 && r10 >= 0 && r01 >= 0 && r11 >= 0;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        string s;
        double w1, w2, b;
        cin >> s >> w1 >> w2 >> b;

        if (LogicGate(w1, w2, b, s)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}