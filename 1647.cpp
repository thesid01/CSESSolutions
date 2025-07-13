// thesid01

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};
const vector<char> dir = {'U', 'L', 'D', 'R'};

int main() {
    
    vector<int> lg(1e6+1, 0);
    lg[1] = 0;
    for(int i=2; i<1e6+1; i++) lg[i] = lg[i/2] + 1;

    int n,m;
    cin>>n>>m;

    int K = lg[n] + 1;

    vector<vector<int>> st(K + 1, vector<int>(n+1, 0));

    for(int i=0; i<n; i++) cin>>st[0][i];

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    // for(auto i: st){
    //     for(auto j: i) cout<<j<<" "; cout<<endl;
    // }

    for(int j = 0; j<m; j++) {
        int L, R;
        cin>>L>>R;
        L--;R--;
        int i = lg[R - L + 1];
        int r = R - (1 << i) + 1;
        // cout<<"----"<<endl;
        // cout<<i<<" "<<L<<endl;
        // cout<<i<<" "<<r<<endl;
        // cout<<L<<" "<<L + (1<<i) -1 <<endl;
        // cout<<R - (1<<i) + 1<<" "<<R<<endl;
        // cout<<"----"<<endl;
        int ans = min(st[i][L], st[i][r]);
        cout<<ans<<endl;
    }
    return 0;
}