#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

#define FOR(i, b, e) for (int i = b; i < e; ++i)

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int h, w, x, y;
    cin >> h >> w >> y >> x;

    mi b(h + y, vi(w + x));
    FOR(i, 0, h + y) FOR(j, 0, w + x) cin >> b[i][j];

    mi a(h, vi(w));
    FOR(i, 0, y) FOR(j, 0, w) a[i][j] = b[i][j];
    FOR(i, y, h) FOR(j, 0, x) a[i][j] = b[i][j];

    FOR(i, 0, h) FOR(j, w - x, w) a[i][j] = b[i + y][j + x];
    FOR(i, h - y, h) FOR(j, 0, w) a[i][j] = b[i + y][j + x];
    
    FOR(i, y, h - y) FOR(j, x, w - x) a[i][j] = b[i][j] - a[i - y][j - x];

    FOR(i, 0, h) {
        FOR(j, 0, w) cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}