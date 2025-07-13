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

int main() {
    int n,m;
    cin>>n>>m;

    vector<ll> arr(n+1, 0), prefixSum(n+1, 0);

    for(int i=0; i<n; i++) {
        cin>>arr[i+1];
        prefixSum[i+1] += arr[i+1] + prefixSum[i];
    }

    for(int i=0; i<m; i++) {
        int start, end;
        cin>>start>>end;
        cout<<prefixSum[end] - prefixSum[start-1]<<endl;
    }

    return 0;
}