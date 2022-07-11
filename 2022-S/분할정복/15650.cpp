#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m, choose;
bool visit[9];
vector<int> v;

void f(int lastin) {
    if (choose == m) {
        for (int i=0; i<v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    for (int i=lastin+1; i<=n; i++) {
        if (!visit[i]) {
            v.push_back(i);
            visit[i] = true;
            choose++;
            f(i);
            v.pop_back();
            visit[i] = false;
            choose--;
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    f(0);
    return 0;
}