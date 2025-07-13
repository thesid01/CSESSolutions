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
    int n;
    cin>>n;

    vector<int> ans(n+1, 0);
    map<int, vector<int>> tree;

    for (int i=2; i<=n; i++) {
        int boss;
        cin>>boss;
        tree[boss].push_back(i);
    }


    // for(auto i: tree) {
    //     cout<<i.first<<" : ";
    //     for (auto j: i.second) {
    //         cout<<j<<", ";
    //     }
    //     cout<<endl;
    // }

    postOrder(1, ans, tree);

    for (int i=1; i<=n; i++) {
        cout<<ans[i] - 1<<" ";
    }

    return 0;
}