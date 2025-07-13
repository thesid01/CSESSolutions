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

    ll n;
    cin>>n;

    ll ans = 1;

    for(int i=2; i<=n; i++) {
        int t;
        cin>>t;
        ans = ans ^ t ^ i;
    }

    cout<<ans<<endl;

    return 0;
}