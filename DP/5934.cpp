#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<int> v[50505];
ll S[50505][2];

void dp(int x, int root, int s) {
    for (int i=0; i<v[x].size(); i++) {
        if (v[x][i] == root) continue;
        if (s == 1) {
            if (!S[v[x][i]][0])
                dp(v[x][i], x, 0);
            S[x][1] += S[v[x][i]][0];
        }
        else {
            int r1, r2;
            if (!S[v[x][i]][1])
                dp(v[x][i], x, 1);
            if (!S[v[x][i]][0])
                dp(v[x][i], x, 0);
            r1 = S[v[x][i]][1];
            r2 = S[v[x][i]][0];
            if (r1 > r2) S[x][0] += r1;
            else S[x][0] += r2;
        }
    }
    if (s == 1) S[x][1]++;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        v[c1].push_back(c2);
        v[c2].push_back(c1);
    }
    dp(1, 0, 1);
    dp(1, 0, 0);
    if (S[1][0] > S[1][1]) cout << S[1][0] << '\n';
    else cout << S[1][1] << '\n';
    return (0);
}