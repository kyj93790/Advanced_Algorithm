#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int cnt;
vector<pair<int, int> > v;

void hanoi(int origin, int dest, int h) {
    if (h == 1) {
        v.push_back(make_pair(origin, dest));
        cnt++;
        return ;
    }
    int new_dest = 6 - (origin + dest);
    hanoi(origin, new_dest, h-1);
    v.push_back(make_pair(origin, dest));
    cnt++;
    hanoi(new_dest, dest, h-1);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    hanoi(1, 3, n);
    cout << cnt << '\n';
    for (int i=0; i<v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}