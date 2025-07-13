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

    cout<<n;
    if(n != 1) cout<<" ";

    while(n != 1) {
        if(n%2 == 0) {
            n=n/2;
        } else {
            n=n*3 + 1;
        }
        cout<<n;
        if(n != 1) cout<<" ";
    }
    cout<<endl;

    return 0;
}