// thesid01

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};

void postOrder(int node, vector<int> &ans, map<int, vector<int>> &tree) {
    ans[node] = 1;

    for(auto child: tree[node]) {
        postOrder(child, ans, tree);
        ans[node] += ans[child];
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    ll till = 0;
        
    for (int i=0; i<t; i++) {
        ll n, k;
        cin>>n>>k;
        
        ll step = 1;
        ll result = 0;

        while (true) {
            ll removed_this_round = n / 2;

            if (k <= removed_this_round) {
                result = step * (2 * k);
                break;
            } else {
                k -= removed_this_round;
                n = (n + 1) / 2;
                step *= 2;
            }
        }
        cout << result << endl;

    }

    return 0;
}