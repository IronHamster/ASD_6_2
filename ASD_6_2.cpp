#include <iostream>
#include <vector>
#include <limits>

const int MAX_V = 100;
const int INF = std::numeric_limits<int>::max();

void floydWarshall(std::vector<std::vector<int>>& graf, int V) {
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
    std::cin >> n;

    while (n--) {
        std::cin >> m;
        std::vector<std::vector<int>> graf(MAX_V, std::vector<int>(MAX_V, INF));
        int maxVertex = 0; 
       
        for (int v = 0; v < MAX_V; ++v) {
            graf[v][v] = 0;
        }

        for (int k = 0; k < m; ++k) {
            std::cin >> i >> j;
            maxVertex = std::max(maxVertex, std::max(i, j));
            graf[i-1][j-1] = graf[j-1][i-1] = 1;
        }
        floydWarshall(graf, maxVertex);

        for (int a = 0; a < maxVertex; ++a) {
            for (int b = 0; b < maxVertex; ++b) {
                if (graf[a][b] == INF) {
                    std::cout << "NaN ";
                } else {
                    std::cout << graf[a][b] << " ";
                }
            }
            std::cout << std::endl;
        }
        if (n > 0)
            std::cout << std::endl;
    }

    return 0;
}
