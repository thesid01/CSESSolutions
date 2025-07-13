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

    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> applicants, apartments;
    int ans = 0;

    for(int i=0; i<n; i++) {
        int t;
        cin>>t;
        applicants.push_back(t);
    }

    for(int i=0; i<m; i++) {
        int t;
        cin>>t;
        apartments.push_back(t);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i=0,j=0;
    while(i<n && j<m) {
        // cout<<applicants[i]<<" "<<apartments[j]<<endl;
        if(abs(applicants[i] - apartments[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if(applicants[i] > apartments[j]) {
            j++;
        } else {
            i++;
        }
    }

    cout<<ans<<endl;

    return 0;
}