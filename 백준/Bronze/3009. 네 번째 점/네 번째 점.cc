#include <iostream>
#include <vector>
using namespace std;

struct X {
    int x, y;
    bool xequal(const X& other) { return x == other.x; }
    bool yequal(const X& other) { return y == other.y; }
};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<X> arr(3);
    for (auto& elt : arr) cin >> elt.x >> elt.y;

    int x;
    if (arr[0].xequal(arr[1])) x = arr[2].x;
    else if (arr[0].xequal(arr[2])) x = arr[1].x;
    else x = arr[0].x;

    int y;
    if (arr[0].yequal(arr[1])) y = arr[2].y;
    else if (arr[0].yequal(arr[2])) y = arr[1].y;
    else y = arr[0].y;

    cout << x << ' ' << y;

    return 0;
}