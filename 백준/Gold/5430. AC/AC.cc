#include <iostream>
#include <string>
#include <deque>
using namespace std;

void PrintResult() {

}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        string p;
        cin >> p >> n;

        deque<int> arr(n);
        char c;
        if (n == 0) cin >> c >> c;
        else {
            cin >> c;
            for (auto& elt : arr) cin >> elt >> c;
        }

        bool reversed = false;
        bool has_error = false;
        for (const auto& c : p) {
            if (c == 'R') reversed = !reversed;
            else {
                if (arr.empty()) {
                    has_error = true;
                    break;
                }
                if (reversed) arr.pop_back();
                else arr.pop_front();
            }
        }

        if (has_error) cout << "error\n";
        else {
            cout << '[';
            if (!arr.empty()) {
                if (reversed) {
                    auto iter = rbegin(arr);
                    for(; iter != rend(arr) - 1; ++iter) {
                        cout << *iter << ',';
                    }
                    cout << *iter;
                }
                else {
                    auto iter = begin(arr);
                    for(; iter != end(arr) - 1; ++iter) {
                        cout << *iter << ',';
                    }
                    cout << *iter;
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}