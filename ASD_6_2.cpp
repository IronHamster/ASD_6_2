#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX_V = 100;
const int INF = numeric_limits<int>::max();

void floydWarshall(vector<vector<int>>& graf, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (graf[i][k] != INF && graf[k][j] != INF && graf[i][k] + graf[k][j] < graf[i][j]) {
                    graf[i][j] = graf[i][k] + graf[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m, i, j;
    cin >> n;

    while (n--) {
        cin >> m;
        vector<vector<int>> graf(MAX_V, vector<int>(MAX_V, INF));
        int maxVertex = 0; 
       
        for (int v = 0; v < MAX_V; ++v) {
            graf[v][v] = 0;
        }


        for (int k = 0; k < m; ++k) {
            cin >> i >> j;
            maxVertex = max(maxVertex, max(i, j));
            graf[i-1][j-1] = graf[j-1][i-1] = 1;
        }
        floydWarshall(graf, maxVertex);

        for (int a = 0; a < maxVertex; ++a) {
            for (int b = 0; b < maxVertex; ++b) {
                if (graf[a][b] == INF) {
                    cout << "NaN ";
                } else {
                    cout << graf[a][b] << " ";
                }
            }
            cout << endl;
        }
        if (n > 0)
            cout << endl;
    }

    return 0;
}