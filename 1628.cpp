// thesid01

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
// const vector<int> dx = {-1, 0, 1, 0};
// const vector<int> dy = {0, -1, 0, 1};

int main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, x;
    cin>>n>>x;
    int mid = n/2;

    vector<int> leftArr(mid), rightArr(n-mid);
    
    for(int i=0; i<mid; i++) {
        cin>>leftArr[i];
    }

    for (int i = 0; i < n-mid; i++) {
        cin>>rightArr[i];
    }

    unordered_map<int, int> leftCount;
    int k = leftArr.size();
    
    for (int mask = 0; mask < (1 << k); ++mask) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                sum += leftArr[i];

                // if (sum > MOD) break;
            }
        }
        // if (sum < MOD)
            leftCount[sum]++;
    }

    ll ans = 0;
    k = rightArr.size();

    for (int mask = 0; mask < (1 << k); ++mask) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                sum += rightArr[i];
                // if (sum > MOD) break;
            }
        }

        // if (sum < MOD)
        ans += leftCount[x-sum];
    }

    cout << ans << endl;

    return 0;
}
