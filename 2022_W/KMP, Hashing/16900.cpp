#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll f[505050];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string s;
    ll k;
    cin >> s >> k;
    for (ll i=1, j=0; i<s.size(); i++) {
        while(j>0 && s[i]!=s[j]) j=f[j-1];
        if (s[i]==s[j]) {
            f[i] = ++j;
        }
    }
    ll com = f[s.size()-1];
    ll dif = s.size() - com;
    cout << com + dif*k;
    return 0;
}