// thesid01

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MOD = 1e9+7;
const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>> arr(n, vector<char>(m)); 
    vector<vector<bool>> visited(n, vector<bool>(m)); 
    queue<pair<int, int>> q;
    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {

            if (!visited[i][j]) {

                visited[i][j] = true;

                if(arr[i][j] == '.') {

                    ans++;
                    q.push({i, j});
                    while (!q.empty()) {

                        pair<int, int> curr = q.front();
                        q.pop();

                        for(int k=0; k<4; k++) {
                            int newI = curr.first + dx[k],
                                newJ = curr.second + dy[k];

                            if (newI >=0 && newI < n && newJ >=0 && newJ < m) {

                                 if (!visited[newI][newJ]) {
                                    visited[newI][newJ] = true;
                                    if(arr[newI][newJ] == '.') {
                                        q.push({newI, newJ});
                                    }   
                                }
                            }
                                
                        }
                    }    
                }
            }
        }
    }

    cout<<ans;

    return 0;
}