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

vt<pii> adj[50001];
bool isSummit[50001];
bool isGate[50001];
bool vis[50001];
int summit = INF, intensity = INF;

int bfs(int mid, vt<int> &gates, vt<int> &summits) {
    mset(vis, 0);
    queue<int> q;
    int summit = INF;
    for(int x : gates) {
        q.push(x);
        vis[x] = 1;
    }

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        if(isSummit[curr]) {
            if(curr < summit) summit = curr;
            continue;
        }

        for(int i=0; i<sz(adj[curr]); ++i) {
            int next = adj[curr][i].F;
            int w = adj[curr][i].S;

            if(!vis[next] && !isGate[next] && w <= mid) {
                q.push(next);
                vis[next] = 1;
            }
        }
    }

    return summit;
}

// 등산코스 정하기
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for(auto v : paths) {
        int s = v[0], e = v[1], w = v[2];
        adj[s].pb({e,w});
        adj[e].pb({s,w});
    }

    for(int x : gates) {
        isGate[x] = 1;
    }

    for(int x : summits) {
        isSummit[x] = 1;
    }
    
    int l = 0, r = 1e7;
    while(l+1 < r) {
        int mid = (l+r) / 2;

        int s = bfs(mid, gates, summits);
        if(s != INF) {
            summit = s;
            intensity = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    if(summit == INF && intensity == INF) {
        summit = bfs(r, gates, summits);
        intensity = r;
    }

    answer.pb(summit), answer.pb(intensity);
    return answer;
}
////

void sol() {
    vt<int> ans;
    int n = 6;
    vt<vt<int>> paths = {{1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4},
                        {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}};
    vt<int> gates = {1,3};
    vt<int> summits = {5};
    ans = solution(n, paths, gates, summits);

    for(int x : ans) cout << x << ' ';
    cout << en;

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(T--) {
        sol();
    }

    return 0;
}
