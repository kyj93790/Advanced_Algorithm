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
ll cnt;

struct Trie {
    map<char, Trie> next;
    int cut = 0;
    
    void insert(string s, ll i) {
        if (i >= s.length()) return ;
        auto it = next.find(s[i]);
        if (it == next.end()) it = next.insert({s[i], Trie()}).first;
        it->second.insert(s, i+1);
    }
    void check(string s, ll i) {
        if (cut) return ;
        if (i >= s.length()) {
            cnt++;
            return ;
        }
        auto it = next.find(s[i]);
        if (it == next.end()) {
            it = next.insert({s[i], Trie()}).first;
            it->second.cut = 1;
            cnt++;
            return ;
        }
        it->second.check(s, i+1);
    }
};

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t, n, m;
    cin >> t;
    while (t--) {
        vector<string> vn, vm;
        string s;
        Trie T;
        cin >> n;
        cnt = 0;
        for (ll i=0; i<n; i++) {
            cin >> s;
            vn.push_back(s);        
        }
        cin >> m;
        if (m == 0) {
            cout << 1 << '\n';
            continue;
        }
        for (ll i=0; i<m; i++) {
            cin >> s;
            T.insert(s, 0);
        }
        for (ll i=0; i<n; i++) {
            T.check(vn[i], 0); 
        }
        cout << cnt << '\n';
    }
    return 0;
}

// 중간에 잘린 위치를 만나게 되면 ex) filter에서 t ! 
//                  그 string은 그냥 무시 (이미 잘림)
// 끝까지 봤을 때 이미 있으면 명령어 횟수 +1 (* 안됨)
// 잘리지도 않았고 없는 문자열이면 하나 추가, flag 세우기