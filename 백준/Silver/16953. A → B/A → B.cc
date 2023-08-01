#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

ll a, b;
queue<ll> temp;
map<ll, int> dist;

bool Visited(ll u) {
    return dist.find(u) != end(dist);
}

void NextMove(ll u, ll v) {
    if (!Visited(v) && v <= b) {
        dist.insert({v, dist[u] + 1});
        temp.push(v);
    }
}

int Bfs() {
    dist.insert({a, 1});
    temp.push(a);

    ll u = a;
    while (!temp.empty()) {
        u = temp.front();
        temp.pop();

        NextMove(u, 2 * u);
        NextMove(u, 10 * u + 1);
    }

    if (!Visited(b)) return -1;
    return dist[b];
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    cin >> a >> b;
    cout << Bfs();

    return 0;
}