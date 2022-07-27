#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define INF 1e13

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
        if (!flag) { // while 문 안에 들어가지 않는 경우는 다음 station이 너무 먼 경우
            cout << -1 << '\n';
            return 0;
        }
        // while 안에는 들어가지만 if 문 내에 들어가지 못한다면 ? 현재 있는 station이 가장 저렴함
        if (i != j) {
            // 최대 이동할 수 있는 만큼?
            // 이게 최선이 아닐 수 있음.... 중간에 살짝 비싼데서 더 사는게 낫고, 최대 이동한 station에 너무 비싸면 ?
            // 풀매수 하고 일단 다음 Station으로만 이동
            // 다음 station이 종착지인 경우 풀 매수할 필요 없음. 필요한 만큼만 사고 끝내기
            if (i+1 == v.size()-1) result += v[i].second * (v[i+1].first - pos - b);
            else result += v[i].second * (g - b);
            b = g - (v[i+1].first - pos);
            pos = v[i+1].first;
            i++;
        }
    }
    if (result >= INF || pos != d) cout << -1 << '\n';
    else cout << result << '\n';
    return 0;
}