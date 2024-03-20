#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int Gcd(int a, int b) {
    int r = a % b;
    if (r) return Gcd(b, r);
    return b;
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string s;
        getline(cin, s);

        vector<string> arr;
        stringstream ss(s);
        string buffer;
        while (getline(ss, buffer, ' ')) arr.push_back(buffer);

        int m = arr.size();
        vector<int> nums(m);
        for (int i = 0; i < m; ++i) {
            nums[i] = stoi(arr[i]);
        }

        int max_gcd = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int gcd = Gcd(nums[i], nums[j]);
                if (gcd > max_gcd) max_gcd = gcd;
            }
        }
        cout << max_gcd << '\n';
    }
    

    return 0;
}