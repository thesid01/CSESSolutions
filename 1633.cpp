// thesid01

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin>>n;

    vector<int> arr(n+1, 0);
    arr[0] = 1;

    for(int i=1; i<=n; i++) {
        int end = min(i,6);
        for(int j=1; j<=end; j++) {
            arr[i] = (arr[i] + arr[i - j])%MOD;
        }
    }

    cout<<arr[n];
    return 0;
}