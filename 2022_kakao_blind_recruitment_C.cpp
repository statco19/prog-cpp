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

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

bool cmp(pair<string,int> &a, pair<string,int> &b) {
    return stoi(a.F) < stoi(b.F);
}

int timeCal(string s) {
    vt<string> v = split(s, ':');
    return stoi(v[0])*60 + stoi(v[1]);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    umap<string, int> elap;
    umap<string, int> timestamp;
    umap<string, bool> in;

    for(string rec : records) {
        vt<string> v = split(rec, ' ');

        if(in.find(v[1]) != in.end()) {
            if(in.find(v[1])->second == 0) {
                in.ioa(v[1], 1);
                timestamp.ioa(v[1], timeCal(v[0]));
            } else {
                in.ioa(v[1], 0);

                auto p = elap.find(v[1]);
                int x = timeCal(v[0]) - timestamp.find(v[1])->second;
                elap.ioa(v[1], p->second + x);
            }
        } else {
            in.ioa(v[1], 1);
            timestamp.ioa(v[1], timeCal(v[0]));
            elap.ioa(v[1], 0);
        }
    }

    for(auto it=in.begin(); it!=in.end(); ++it) {
        if(it->second == 1) {
            in.ioa(it->first, 0);

            auto p = elap.find(it->first);
            int x = timeCal("23:59") - timestamp.find(it->first)->second;
            elap.ioa(it->first, p->second + x);
        }
    }

    vt<pair<string,int>> v;
    for(auto it=elap.begin(); it!=elap.end(); ++it) {
        v.pb({it->first, it->second});
    }
    sort(all(v), cmp);

    for(auto p : v) {
        int e = p.S;
        if(e <= fees[0]) answer.pb(fees[1]);
        else {
            int fee = fees[1];
            fee += (int)ceil((double)(e - fees[0]) / fees[2]) * fees[3];
            answer.pb(fee);
        }
    } 

    return answer;
}
////

void sol() {
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

    for(int x : solution(fees, records)) {
        cout << x << ' ';
    }
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
