#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    double x_sum = 0, x_sqr_sum = 0, xy_sum = 0, y_sum = 0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        x_sum += x;
        x_sqr_sum += x * x;
        xy_sum += x * y;
        y_sum += y;
    }

    double a = n * xy_sum - x_sum * y_sum;
    double b = x_sqr_sum * y_sum - x_sum * xy_sum;
    double det = x_sqr_sum * n - x_sum * x_sum;

    cout.precision(3);
    cout << fixed << a / det << '\n' << b / det;

    return 0;
}