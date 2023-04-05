//https://codeforces.com/contest/1332/problem/C
//String s is k-completed if :
//1. s is palindrom
//2. s[i] == s[i + k]
// n is divisible by k


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

using ll = long long;
#define pb push_back
#define ve vector

const int N = 2e5 + 10;
int n, k;
string s;
int p[N];
int cnts[N][26];
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


void solve() {
    cin >> n >> k;
    cin >> s;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        for(int j = 0; j < 26; j++) cnts[i][j] = 0;
    }

    int l = 0, r = n - 1;
    while(l <= r) {
        int r1 = find(l), r2 = find(r);
        if(r1 != r2) p[r1] = r2;
        l++; r--;
    }

    for(int i = 0; i < n; i++) {
        int nxt = i + k;
        if(nxt < n) {
            int r1 = find(i), r2 = find(nxt);
            if(r1 != r2) p[r1] = r2;
        }
    }

    set<int> se;
    for(int i = 0; i < n; i++) {
        int r = find(i);
        cnts[r][s[i] - 'a']++;
        se.insert(r);
    }

    int res = 0;
    for(auto r : se) {
        int tot = 0, mx = 0;
        for(int i = 0; i < 26; i++) {
            tot += cnts[r][i];
            mx = max(mx, cnts[r][i]);
        }
        res += (tot - mx);
    }

    cout << res << endl;

}

int main()
{   

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
