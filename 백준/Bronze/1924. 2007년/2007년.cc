#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> nums{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> days{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int x, y;
    cin >> x >> y;

    int day = 0;
    for (int i = 0; i < x; ++i) day += nums[i];
    day += y - 1;

    cout << days[day % 7];
    
    return 0;
}