#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int INF = 1e9;
const int MAX = 100;

int G[MAX][MAX]; // Ma trận kề đồ thị gốc
int n; // Số đỉnh

// 1. Thuật toán Dijkstra
void Dijkstra(int start) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) 
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        
        if (dist[u] == INF) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) 
            if (G[u][v] && dist[u] + G[u][v] < dist[v]) dist[v] = dist[u] + G[u][v];
    }
    cout << "Khoang cach ngan nhat tu dinh " << start << ": ";
    for (int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << endl;
}

void Prim() {
    int parent[MAX], key[MAX];
    bool mstSet[MAX];
    for (int i = 0; i < n; i++) key[i] = INF, mstSet[i] = false;
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!mstSet[v] && (u == -1 || key[v] < key[u])) u = v;
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
            if (G[u][v] && !mstSet[v] && G[u][v] < key[v]) parent[v] = u, key[v] = G[u][v];
    }

    // In ma trận đỉnh kề của cây khung
    int MST[MAX][MAX] = {0};
    for (int i = 1; i < n; i++) {
        MST[i][parent[i]] = MST[parent[i]][i] = G[i][parent[i]];
    }
    cout << "Ma tran ke cay khung (Prim):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << setw(3) << MST[i][j] << " ";
        cout << endl;
    }
}

// 3. Cấu trúc cho Kruskal
struct Edge { int u, v, w; };
bool compareEdges(Edge a, Edge b) { return a.w < b.w; }

int find(int i, vector<int>& parent) {
    return (parent[i] == i) ? i : (parent[i] = find(parent[i], parent));
}

void Kruskal() {
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (G[i][j] != 0) edges.push_back({i, j, G[i][j]});
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int MST[MAX][MAX] = {0};
    for (auto& e : edges) {
        int rootU = find(e.u, parent), rootV = find(e.v, parent);
        if (rootU != rootV) {
            MST[e.u][e.v] = MST[e.v][e.u] = e.w;
            parent[rootU] = rootV;
        }
    }
    cout << "Ma tran ke cay khung (Kruskal):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << setw(3) << MST[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> G[i][j];

    Dijkstra(0); // Giả sử Hà Nội là đỉnh 0
    Prim();
    Kruskal();
    return 0;
}
