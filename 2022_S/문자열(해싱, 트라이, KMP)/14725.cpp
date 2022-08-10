#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
struct Trie {
    map<string, Trie> next;

    void insert(vector<string> &tmp, ll idx) {
        if (idx >= tmp.size()) return;
        auto it = next.find(tmp[idx]);
        // 없는 자식 node면 추가
        // insert는 pair<iterator, bool>을 return
        // 성공 시(=중복 key 없을 때) {insert된 element의 iterator, true}
        // 실패 시(=중복 key 있을 때) {중복된 key의 element iterator, false}
        if (it == next.end()) it = next.insert({tmp[idx], Trie()}).first;
        it->second.insert(tmp, idx+1);
    }
    void print(int d) {
        for (auto &[s, np] : next) {
            // string 생성자 활용 출력.. WOW
            cout << string(2*d, '-') << s << '\n';
            np.print(d+1);
        }
    }
};

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, k;
    Trie t;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> k;
        vector<string> tmp;
        string s;
        for (ll j=0; j<k; j++) {
            cin >> s;
            tmp.push_back(s);
            t.insert(tmp, 0);
        }
    }
    t.print(0);
    return 0;
}