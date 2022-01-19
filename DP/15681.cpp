#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101010];
int dp[101010];
int visit[101010];

int subtree(int r) {
    int cnt = 0;
    for (int i=0; i<v[r].size(); i++) {
        if (visit[v[r][i]] == 0) {
            visit[v[r][i]] = 1;
            cnt += subtree(v[r][i]);
        }
    }
    cnt++;
    dp[r] = cnt;
    return (cnt);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, R, Q;
    cin >> N >> R >> Q;
    for (int i=0; i<N-1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    visit[R] = 1;
    subtree(R);
    for (int i=0; i<Q; i++){
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
    return (0);
}