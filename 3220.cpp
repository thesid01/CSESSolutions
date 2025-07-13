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
// const vector<int> dx = {-1, 0, 1, 0};
// const vector<int> dy = {0, -1, 0, 1};

int main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, k;
    cin>>n>>k;

    int x, a, b, c;
    cin>>x>>a>>b>>c;

    ll ans = 0;
    ll windowSum = 0;

    deque<ll> q;
    q.push_back(x);
    windowSum = x;

    for(int i=1; i<k; i++) {
        q.push_back((a*q.back() + b)%c);
        windowSum += q.back();
    }

    ans = ans^windowSum;
    
    for(int i=k; i<n; i++) {
        windowSum -= q.front();
        q.push_back((a*q.back() + b)%c);
        windowSum += q.back();
        q.pop_front();
        ans = ans^windowSum;
    }

    cout<<ans<<endl;

    return 0;
}
