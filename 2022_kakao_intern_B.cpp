int T = 1;
#include <bits/stdc++.h>
using namespace std;

int ans;
vector<int> queue1, queue2;

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

// 두 큐 합 같게 만들기
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll s1 = 0, s2 = 0;
    for(ll x : queue1) {s1 += x;}
    for(ll x : queue2) {s2 += x;}
    if((s1+s2) & 1) return -1;

    vt<int> v;
    for(int x : queue1) v.pb(x);
    for(int x : queue2) v.pb(x);

    bool found = 0;
    int l = 0;
    int r = sz(queue1);
    while(l != r) {
        if(s1 > s2) {
            s1 -= v[l];
            s2 += v[l];
            l = (l+1) % sz(v);
            if(l == 0) break;
        } else if(s1 < s2) {
            s1 += v[r];
            s2 -= v[r];
            r = (r+1) % sz(v);
            if(r == sz(queue1)) break;
        } else {
            found = 1;
        }
        if(found) break;
        answer++;
    }

    answer = found == 1 ? answer : -1;
    return answer;
}
////

void sol() {
    queue1 = {1,1};
    queue2 = {1,5};
    ans = solution(queue1, queue2);

    cout << ans << en;


    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(T--) {
        sol();
    }

    return 0;
}
