#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i;
    for (i = 1; i * i < n; ++i) {
        if (n % i) continue;
        answer += 2;
    }
    if (i * i == n) ++answer;
    return answer;
}