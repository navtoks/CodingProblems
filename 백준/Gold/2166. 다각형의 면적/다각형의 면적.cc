#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Vector {
    ll x, y;
    friend istream& operator>>(istream& in, Vector& v);
    Vector operator-(const Vector& other) {
        return Vector{x - other.x, y - other.y};
    }
    ll Cross(const Vector& other) const {
        return x * other.y - y * other.x;
    }
};

istream& operator>>(istream& in, Vector& v) {
    in >> v.x >> v.y;
    return in;
}

ll ComputeArea(const Vector& v1, const Vector& v2) {
    ll cross = v1.Cross(v2);
    return -cross;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Vector> arr(n);
    for (auto& elt : arr) cin >> elt;

    Vector base = arr[0];
    vector<Vector> diff(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        arr[i] = arr[i + 1] - base;
    }

    ll sum = 0;
    for (int i = 0; i < n - 2; ++i) {
        sum += ComputeArea(arr[i], arr[i + 1]);
    }
    if (sum < 0) sum *= -1;

    cout.precision(1);
    cout << fixed << static_cast<double>(sum) / 2.0;

    return 0;
}