#include <iostream>
using namespace std;

struct Vector {
    int x, y;
    friend istream& operator>>(istream& in, Vector& v);
    Vector operator-(const Vector& other) {
        return Vector{x - other.x, y - other.y};
    }
    int Cross(const Vector& other) const {
        return x * other.y - y * other.x;
    }
};

istream& operator>>(istream& in, Vector& v) {
    in >> v.x >> v.y;
    return in;
}

int Direction(const Vector& v1, const Vector& v2) {
    int cross = v1.Cross(v2);
    if (cross > 0) return 1;
    if (cross == 0) return 0;
    return -1;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    Vector p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    Vector v1 = p2 - p1;
    Vector v2 = p3 - p2;

    cout << Direction(v1, v2);

    return 0;
}