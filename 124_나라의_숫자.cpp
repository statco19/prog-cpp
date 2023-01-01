int T = 1;
#include <bits/stdc++.h>
using namespace std;

////
#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define mset(ar, val) memset(ar, val, sizeof(ar))
#define en '\n'

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

// 124 나라의 숫자
string solution(int n) {
    vt<string> v = {"4", "1", "2"};
    string answer = "";
    
    while(n) {
        int x = n%3;
        n /= 3;

        if(x == 0) n--;
        answer += v[x];
    }
    return string(rev(answer));
}
////

void sol() {
    vt<int> v = {1,2,3,4,5,6,7,8,9,10};
    for(int n : v) {
        cout << solution(n) << en;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(T--) {
        sol();
    }

    return 0;
}
