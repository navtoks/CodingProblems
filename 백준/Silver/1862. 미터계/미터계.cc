#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> arr;
    while (n) {
        arr.push_back(n % 10);
        n /= 10;
    }

    int result = 0;
    int mult = 1;
    for (const auto& elt : arr) {
        if (elt > 4) result += mult * (elt - 1);
        else result += mult * elt;
        mult *= 9;
    }
    cout << result;
    
    return 0;
}