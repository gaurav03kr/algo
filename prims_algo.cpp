#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter cost adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    vector<int> selected(n, 0);
    selected[0] = 1;

    int edges = 0, mincost = 0;

    while(edges < n - 1) {
        int minimum = INT_MAX, a = -1, b = -1;
        for(int i = 0; i < n; i++) {
            if(selected[i]) {
                for(int j = 0; j < n; j++) {
                    if(!selected[j] && cost[i][j] && cost[i][j] < minimum) {
                        minimum = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        cout << "Edge: " << a << " - " << b << " | Weight: " << cost[a][b] << endl;
        mincost += cost[a][b];
        selected[b] = 1;
        edges++;
    }

    cout << "Minimum Cost: " << mincost;
    return 0;
}
