#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm> // Thêm thư viện này

using namespace std;

const int INF = 1e7;

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    system("chcp 65001 > nul");
    #endif

    vector<string> cities = {
        "Hà nội", "Hải dương", "Phủ lý", "Hòa bình", "Sơn tây", 
        "Thái nguyên", "Bắc ninh", "Hưng yên", "Bắc giang", "Uông bí", "Hải phòng"
    };
    int V = cities.size();

    vector<vector<int>> dist(V, vector<int>(V, INF));
    vector<vector<int>> next_node(V, vector<int>(V, -1));

    for (int i = 0; i < V; i++) dist[i][i] = 0;

    auto addEdge = [&](int u, int v) {
        dist[u][v] = 1; dist[v][u] = 1;
        next_node[u][v] = v; next_node[v][u] = u;
    };

    addEdge(0, 1); addEdge(0, 2); addEdge(0, 3); addEdge(0, 4); 
    addEdge(0, 5); addEdge(0, 6); addEdge(6, 8); addEdge(6, 9); 
    addEdge(8, 9); addEdge(9, 10); addEdge(1, 10); addEdge(1, 7); addEdge(2, 7);

    // Thuật toán Floyd-Warshall
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_node[i][j] = next_node[i][k];
                }
            }
        }
    }

    int start = 0;
    cout << "========================================================\n";
    cout << "  KẾT QUẢ FLOYD-WARSHALL: ĐƯỜNG ĐI TỪ " << cities[start] << "\n";
    cout << "========================================================\n\n";

    for (int i = 0; i < V; i++) {
        if (i == start) continue;
        cout << "-> Đến: " << setw(15) << left << cities[i] 
             << " | " << dist[start][i] << " chặng | Lộ trình: ";

        int curr = start;
        cout << cities[curr];
        while (curr != i) {
            curr = next_node[curr][i];
            cout << " -> " << cities[curr];
        }
        cout << "\n";
    }

    return 0;
}