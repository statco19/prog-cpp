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

// 코딩 테스트 공부
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int dp[151][151];
    mset(dp,INF);

    int A = mINF, C = mINF;
    for(vt<int> v : problems) {
        A = max(A, v[0]);
        C = max(C, v[1]);
    }

    // Exception 1 : alp, cop가 모두 max_alp, max_cop보다 큰 경우
    if(alp >= A && cop >= C) {
        return 0;
    }

    // Exception 2 : alp 혹은 cop 중 하나만 max 값보다 큰 경우
    alp = min(alp, A);
    cop = min(cop, C);

    dp[alp][cop] = 0;
    for(int i=alp; i<=A; ++i) {
        for(int j=cop; j<=C; ++j) {
            if(i < A) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            }

            if(j < C) {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            }

            for(int k=0; k<sz(problems); ++k) {
                int alp_req = problems[k][0];
                int cop_req = problems[k][1];
                int alp_rwd = problems[k][2];
                int cop_rwd = problems[k][3];
                int cost = problems[k][4];
                                
                if(i >= alp_req && j >= cop_req) {
                    if(i+alp_rwd >= A && j+cop_rwd >= C) {
                        dp[A][C] = min(dp[A][C], dp[i][j] + cost);
                    } else if(i+alp_rwd >= A) {
                        dp[A][j+cop_rwd] = min(dp[A][j+cop_rwd], dp[i][j] + cost);
                    } else if(j+cop_rwd >= C) {
                        dp[i+alp_rwd][C] = min(dp[i+alp_rwd][C], dp[i][j] + cost);
                    } else {
                        dp[i+alp_rwd][j+cop_rwd] = min(dp[i+alp_rwd][j+cop_rwd], dp[i][j]+cost);
                    }
                }
            }
        }
    }

    answer = dp[A][C];
    
    return answer;
}
////

void sol() {
    int ans = 0;
    // int alp = 10, cop = 10;
    // vt<vt<int>> problems = {{10,15,2,1,2}, {20,20,3,3,4}};
    int alp = 0, cop = 0;
    vt<vt<int>> problems = {{0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2}};
    ans = solution(alp, cop, problems);

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
