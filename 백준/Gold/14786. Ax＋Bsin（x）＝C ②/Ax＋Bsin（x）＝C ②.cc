#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;

double func(double x) {
    return a * x + b * sin(x) - c;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    // x + (B / A) * sinx = C / A  with A >= B and A, B, C > 0
    // x + a * sinx = b where a \in [0, 1] and b > 0
    // By IVT, there is a solution x* in [0, b + 1]

    cin >> a >> b >> c;

    double x1 = 0, x2 = c / a + 1;
    if (c % a) x2 += 1;

    double x, f;
    while (x2 - x1 > 1e-10) {
        x = 0.5 * (x1 + x2);
        f = func(x);
        if (func(x1) * f < 0) x2 = x;
        else x1 = x;
    }

    cout.precision(15);
    cout << fixed << x;
    
    return 0;
}