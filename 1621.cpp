// thesid01

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> arr(n, 0);
    
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    int ans = 0;
    if (n > 0) {
        ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                ans++;
            }
        }
    }
    
    cout<<ans;

    return 0;
}