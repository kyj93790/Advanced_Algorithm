#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <tuple>
#include <cmath>
#include <set>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
vector<char> ans;

struct Trie {
    Trie *ch[26];
    int d, end;

    Trie() {
        for (ll i=0; i<26; i++) ch[i] = NULL;
        d = 0;
    }
    void insert(string s, int i, int len) {
        d = max(d, len);
        if (i == s.length()) {
            end = 1;
            return ;
        }
        if (!ch[s[i]-'a']) {
            ch[s[i]-'a'] = new Trie();
        }
        ch[s[i]-'a']->insert(s, i+1, len);
    }
};

bool comp(pair<Trie*, int> a, pair<Trie*, int> b) {
    return (a.first->d < b.first->d);
}

ll visit, n;
void dfs(Trie *curr) {
    vector<pair<Trie*, int> > v;
    for (ll i=0; i<26; i++) {
        if (curr->ch[i]) {
            v.push_back({curr->ch[i], i});
        }
    }
    if (curr->end) {
        ans.push_back('P');
        visit++;
    }
    if (visit == n) return ;
    sort(v.begin(), v.end(), comp);
    for (ll i=0; i<v.size(); i++) {
        ans.push_back(v[i].second+'a');
        dfs(v[i].first);
        if (visit == n) return ;
        ans.push_back('-');
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    Trie T;
    vector<string> v;
    string s;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> s;
        T.insert(s, 0, s.length());
    }
    dfs(&T);
    cout << ans.size() << '\n';
    for (ll i=0; i<ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}