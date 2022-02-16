#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int f[1010101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string s, t;
    // 공백 포함하여 문자열 받기 위해 getline 사용
    getline(cin, s);
    getline(cin, t);
    // failure 함수 전처리
    for (int i=1, j=0; i<t.length(); i++) {
        // 일치하지 않으면 앞으로 계속 땡김
        while (j>0 && t[i]!=t[j]) j=f[j-1];
        if (t[i]==t[j]) f[i] = ++j;
    }
    vector<int> v;
    for (int i=0, j=0; i<s.length(); i++) {
        while (j>0 && s[i]!=t[j]) j=f[j-1];
        if (s[i] == t[j]) {
            if (j==t.length()-1) {
                v.push_back(i-j+1);
                j=f[j];
            }
            else j++;
        }
    }
    cout << v.size() << '\n';
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}