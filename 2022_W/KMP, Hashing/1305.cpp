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
int f[1010101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int l;
    string s;
    cin >> l >> s;
    for (int i=1, j=0; i<l; i++) {
        while (j>0 && s[i]!=s[j]) j=f[j-1];
        if (s[i]==s[j]) {
            f[i] = ++j;
        }
    }
    cout << l-f[l-1];
    return 0;
}