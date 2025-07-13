// thesid01

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <climits>

using namespace std;

const int MOD = 1e9+7;

// map<pair<int, int>, int> dp;

// int solve(int index, int remaining, vector<int> &coins) {

//     if (remaining == 0) return 0;
//     if(index >= (int)coins.size()) return INT_MAX;
//     if(dp.find({index, remaining}) != dp.end()) return dp[{index, remaining}];

//     int ans = INT_MAX, taken = 0;

//     while(taken*coins[index] <= remaining) {
        
//         // for(int i=0; i<index;i++) cout<<" ";
//         // cout<<"Taken "<<coins[index]<<" "<<taken<<" times, reamaining "<< remaining - taken*coins[index]<<" "<<ans<<endl;

//         int t = solve(index + 1, remaining - taken*coins[index], coins);
//         if (t != INT_MAX)
//             ans = min(ans, t + taken);
//         taken++;
//     }

//     // for(int i=0; i<index;i++) cout<<" ";cout<<ans<<endl;

//     return dp[{index,remaining}] = ans;
// }

int main() {
    int n,x;
    cin>>n>>x;

    vector<int> arr(n, 0);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    int ans = INT_MAX;

    sort(arr.begin(), arr.end(), greater<int>());

    // for (size_t i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    

    // for(int i=0; i<n; i++) {
    //     // cout<<"Starting @ "<<i<<" reamaining "<<x<<endl;
    //     ans = min(solve(i, x, arr), ans);
    // }
    // if(ans == INT_MAX) ans = -1;
    // cout<<ans;

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int coin : arr) {
        for (int amount = coin; amount <= x; ++amount) {
            if (dp[amount - coin] != INT_MAX)
                dp[amount] = min(dp[amount], dp[amount - coin] + 1);
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;

    return 0;
}