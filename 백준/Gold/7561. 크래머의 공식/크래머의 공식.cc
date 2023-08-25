#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using mi = vector<vi>;

mi a(3, vi(3));
vi b(3);

void SetArr() {
    for (int i = 0; i < 3; ++i) {
        for (auto& elt : a[i]) cin >> elt;
        cin >> b[i];
    }
}

ll Det(int i) {
    mi mat = a;
    if (i != 4) {
        for (int j = 0; j < 3; ++j) mat[j][i] = b[j];
    }

    ll det = 0;
    for (i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        det += mat[0][i] * (mat[1][j] * mat[2][k] - mat[1][k] * mat[2][j]);
    }
    return det;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        SetArr();

        vi dets(3);
        for (int i = 0; i < 3; ++i) {
            dets[i] = Det(i);
            cout << dets[i] << ' ';
        }

        ll det = Det(4);
        cout << det << '\n';

        if (det == 0) cout << "No unique solution";
        else {
            cout << "Unique solution:";
            for (int i = 0; i < 3; ++i) {
                double now = double(dets[i]) / double(det);
                if (now > -0.0005 && now < 0.0005) now = 0;
                cout.precision(3);
                cout << ' ' << fixed << now;
            }
        }
        cout << "\n\n";
    }

    return 0;
}