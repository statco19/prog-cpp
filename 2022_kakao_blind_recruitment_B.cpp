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

// k진수에서 소수 개수 구하기
bool isPrime(ll x) {
    if(x == 1) return 0;
    for(ll i=2; i*i<=x; ++i) {
        if(x%i==0) return 0;
    }
    return 1;
}

int solution(int n, int k) {
    int answer = 0;

    string s = "";
    while(n) {
        s += to_string(n%k);
        n /= k;
    }
    s = string(rev(s));

    vt<ll> ar;
    string t = "";
    for(int i=0; i<sz(s); ++i) {
        if(s[i] == '0') {
            if(sz(t)) {
                ar.pb(stoll(t));
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if(sz(t)) ar.pb(stoll(t));

    for(ll x : ar) {
        if(isPrime(x)) answer++;
    }

    return answer;
}
////

void sol() {
    int ans = 0;
    // int n = 437674, k = 3;
    int n = 110011, k = 10;
    cout << solution(n,k) << en;

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(T--) {
        sol();
    }

    return 0;
}
