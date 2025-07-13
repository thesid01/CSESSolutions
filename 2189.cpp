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

int main() {

    int n;
    cin>>n;
    
    for(int i=0; i<n; i++) {
        double x1, x2, y1, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        double cross = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);

        if (cross == 0) {
            cout << "TOUCH" << endl;
        } else if (cross > 0) {
            cout << "LEFT" << endl;
        } else {
            cout << "RIGHT" << endl;
        }

    }

    return 0;
}
