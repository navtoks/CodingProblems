#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int n, m;
mi arr;

struct X {
    int x, y;
    X operator+(const X& o) const { return {x + o.x, y + o.y}; }
    int Get() const {
        bool x_valid = (x >= 0 && x < m);
        bool y_valid = (y >= 0 && y < n);
        if (x_valid && y_valid) return arr[y][x];
        return -10000;
    }
};
using vx = vector<X>;

void SetArr() {
    cin >> n >> m;
    arr = mi(n, vi(m));
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }
}

int TetrominoSum(const vx& tetromino, const X& position) {
    int sum = 0;
    for (const auto& elt : tetromino) {
        auto now = elt + position;
        sum += now.Get();
    }
    return sum;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    SetArr();

    // straight - horizontal and vertical
    vector<vx> tetrominos{
        // straight
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},   // horizontal
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},   // vertical

        // square
        {{0, 0}, {1, 0}, {0, 1}, {1, 1}},

        // T-shaped
        {{0, 0}, {1, 0}, {2, 0}, {1, -1}},  // up
        {{0, 0}, {1, 0}, {2, 0}, {1, 1}},   // down
        {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},  // left
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},   // right

        // L-shaped
        {{0, 0}, {1, 0}, {2, 0}, {2, -1}},  // up
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},   // up reflected
        {{0, 0}, {1, 0}, {2, 0}, {0, 1}},   // down
        {{0, 0}, {1, 0}, {2, 0}, {0, -1}},  // down reflected
        {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},  // left
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}},   // left reflected
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},   // right
        {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},  // right reflected

        // skew
        {{0, 0}, {1, 0}, {1, -1}, {2, -1}}, // horizontal
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},   // horizontal reflected
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},   // vertical
        {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}}  // vertical reflected
    };

    int max_sum = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            X position{x, y};
            for (const auto& tetromino : tetrominos) {
                int sum = TetrominoSum(tetromino, position);
                max_sum = (sum > max_sum ? sum : max_sum);
            }
        }
    }
    cout << max_sum;

    return 0;
}