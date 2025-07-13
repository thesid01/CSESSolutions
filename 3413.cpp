// thesid01

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MOD = 1e9+7;
const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};

int main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, K;
    cin>>n>>K;

    vector<ll> curr((n + 1) * K, 0), 
               prev((n + 1) * K, 0);
    vector<ll> ans(K,0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char a;
            cin>>a;
            int index = a - 'A';

            int idx1 = (j + 1) * K + index;
            int idx2 = j * K + index;

            curr[idx1] = min({prev[idx1], curr[idx2], prev[idx2]}) + 1;
            ans[index] += curr[idx1];
        }

        swap(curr, prev);
        fill(curr.begin(), curr.end(), 0);

    }

    // for(size_t k=0; k<26; k++) {
    //     for(size_t i=1; i<=n; i++) {
    //         for(size_t j=1; j<=n; j++) {
    //             cout<<prefix[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    for(int k=0; k<K; k++) {
        cout<<ans[k]<<'\n';
    }

    return 0;
}