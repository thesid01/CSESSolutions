// thesid01

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

const vector<int> dx = {-1, 0, 1, 0}; // U, L, D, R
const vector<int> dy = {0, -1, 0, 1};
const vector<char> dir = {'U', 'L', 'D', 'R'};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    int startI, startJ, endI, endJ;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                startI = i;
                startJ = j;
            }
            if (graph[i][j] == 'B') {
                endI = i;
                endJ = j;
            }
        }
    }

    queue<pair<int, int>> q;
    visited[startI][startJ] = true;
    q.push({startI, startJ});

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == endI && y == endJ) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && graph[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y}; // track where we came from
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        // Reconstruct path
        string pathStr;
        int x = endI, y = endJ;

        while (make_pair(x, y) != make_pair(startI, startJ)) {
            auto [px, py] = parent[x][y];
            for (int i = 0; i < 4; i++) {
                if (px + dx[i] == x && py + dy[i] == y) {
                    pathStr += dir[i];
                    break;
                }
            }
            x = px;
            y = py;
        }

        reverse(pathStr.begin(), pathStr.end());
        cout << "YES" << endl;
        cout << pathStr.size() << endl;
        cout << pathStr << endl;
    }

    return 0;
}
