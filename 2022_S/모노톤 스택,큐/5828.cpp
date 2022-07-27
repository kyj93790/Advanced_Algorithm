#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define INF 1e16

typedef long long ll;
vector<pair<ll, ll> > v;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, g, b, d;
    pair<ll, ll> tmp;
    cin >> n >> g >> b >> d;
    v.push_back(p(0, INF));
    for (ll i=0; i<n; i++) {
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    v.push_back(p(d, INF));
    sort(v.begin(), v.end());
    ll pos = 0, j, result = 0, flag = 0;
    for (ll i=0; i<v.size()-1; ) {
        j = i+1;
        flag = 0;
        while (j<v.size() && v[j].first - pos <= g) {
            flag = 1;
            if (v[i].second > v[j].second) {
                if (b < v[j].first - pos) {
                    result += v[i].second * (v[j].first - pos - b);
                    b += v[j].first - pos - b;
                }
                b -= v[j].first - pos;
                pos = v[j].first;
                i = j;
                break ;
            }
            j++;
        }
        if (!flag) {
            cout << -1 << '\n';
            return 0;
        }
        if (i != j) {
            if (b < min(g, d - pos)) {
                result += v[i].second * (min(g, d - pos) - b);
                b += min(g, d - pos) - b;
            }
            if (g < d - pos) i++;
            else i = v.size()-1;
            b = g - (v[i].first - pos);
            pos = v[i].first;
        }
    }
    if (result >= INF || pos != d) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}