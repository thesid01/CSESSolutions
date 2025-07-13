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
const vector<char> dir = {'U', 'L', 'D', 'R'};

vector<bool> taken(1e6+1, false);
map<int, vector<int>> graph;

int main() {
    int n;
    cin>>n;

    for (int i = 0; i < n -1; i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 

    int parent, node;

    for(auto i: graph) {
        if(i.second.size() == 1) {
            node = i.second[0];
            parent = i.first;
            break;
        }
    }

    stack<pair<int, int>> st;
    st.push({node, parent});
    int ans = 0;

    while(!st.empty()) {
        node = st.top().first;
        parent = st.top().second;
        
        cout<<node<<" <- "<<parent<<" ";

        if(!taken[node] && !taken[parent]) {
            taken[node] = true;
            taken[parent] = true;
            ans++;
            cout<<"Taken";
        }
        cout<<endl;
        for(auto child: graph[node]) {
            if(!taken[child]) {
                st.push({child, node});
            }
        }
    }

    cout<<ans;

    return 0;
}