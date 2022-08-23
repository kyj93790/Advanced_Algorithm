#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
vector<tuple<ll, ll, ll> > v[101010];
ll n, m, d, x, y, r, ans;

void f(ll i) { // row : i
    vector<pair<ll, ll> > L, R;
    set<ll> s;
    for (ll j=0; j<v[i].size(); j++) {
        ll day = get<0>(v[i][j]), left = get<1>(v[i][j]), right = get<2>(v[i][j]);
        L.push_back({left, day});
        R.push_back({right, day});
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    ll idx=0, li=0, ri=0, mn;
    while (li < L.size() && ri < R.size()) {
        if (L[li].first <= R[ri].first) {
            mn = L[li].first;
            if (!s.empty()) ans += (mn-idx-1)*(d-(*s.rbegin()));
            else ans += (mn-idx-1)*d;
            idx = mn-1;
            while (li < L.size() && L[li].first == mn) {
                s.insert(L[li].second);
                li++;
            }
        } else if (L[li].first > R[ri].first) {
            mn = R[ri].first;
            if (!s.empty()) ans += (mn-idx)*(d-(*s.rbegin()));
            else ans += (mn-idx)*d;
            idx = mn;
            while (ri < R.size() && R[ri].first == mn) {
                s.erase(R[ri].second);
                ri++;
            }
        }
    }
    while (ri < R.size()) {
        mn = R[ri].first;
        if (!s.empty()) ans += (mn-idx)*(d-(*s.rbegin()));
        else ans += (mn-idx)*d;
        idx = mn;
        while (ri < R.size() && R[ri].first == mn) {
            s.erase(R[ri].second);
            ri++;
        }
    }
    ans += (m-idx)*d;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> d;
    for (ll i=1; i<=d; i++) {
        cin >> x >> y >> r;
        ll j, k;
        for (j=x-r, k=0; j<=x+r; j++, k++) {
            ll gap = abs(j-x);
            double dif = sqrt(r*r - gap*gap);
            v[j].push_back({i, ceil(y-dif), y+dif});
        }
    }
    for (ll i=1; i<=n; i++) {
        f(i);
    }
    cout << ans << '\n';
    return 0;
}
