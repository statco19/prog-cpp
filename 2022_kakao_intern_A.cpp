int T = 1;
#include <bits/stdc++.h>
using namespace std;

string ans;
vector<string> survey;
vector<int> choices;

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

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int score[26];
    memset(score,0,sizeof(score));

    for(int i=0; i<sz(choices); ++i) {
        if(choices[i] != 4) {
            if(choices[i]<4) {
                score[survey[i][0]-'A'] += abs(choices[i]-4);
            } else {
                score[survey[i][1]-'A'] += abs(choices[i]-4);
            }
        }
    }

    if(score['R'-'A'] >= score['T'-'A']) {
        answer += "R";
    } else {
        answer += "T";
    }

    if(score['C'-'A'] >= score['F'-'A']) {
        answer += "C";
    } else {
        answer += "F";
    }

    if(score['J'-'A'] >= score['M'-'A']) {
        answer += "J";
    } else {
        answer += "M";
    }

    if(score['A'-'A'] >= score['N'-'A']) {
        answer += "A";
    } else {
        answer += "N";
    }

    return answer;
}
////

void sol() {
    survey = {"TR", "RT", "TR"};
    choices = {7, 1, 3};
    ans = solution(survey, choices);

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
