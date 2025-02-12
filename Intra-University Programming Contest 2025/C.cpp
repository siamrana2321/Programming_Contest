#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdio>

using namespace std;

#define INF INT_MAX

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Node {
    int u, cost;
    Node(int _u, int _cost) : u(_u), cost(_cost) {}
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

void dijkstra(int N, vector<vector<Edge> > &graph) {
    vector<int> dist(N + 1, INF);
    vector<int> second_dist(N + 1, INF);
    
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(Node(1, 0));
    dist[1] = 0;

    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        int u = top.u, d = top.cost;

        if (d > second_dist[u]) continue;

        for (size_t i = 0; i < graph[u].size(); i++) {
            Edge e = graph[u][i];
            int v = e.v, w = e.w;
            int new_cost = d + w;

            if (new_cost < dist[v]) {
                second_dist[v] = dist[v];
                dist[v] = new_cost;
                pq.push(Node(v, new_cost));
            } 
            else if (new_cost > dist[v] && new_cost < second_dist[v]) {
                second_dist[v] = new_cost;
                pq.push(Node(v, new_cost));
            }
        }
    }

    if (second_dist[N] == INF)
        printf("-1\n");
    else
        printf("%d\n", second_dist[N]);
}

int main() {
    int T;
    cin >> T;

    for (int case_no = 1; case_no <= T; case_no++) {
        int N, R;
        cin >> N >> R;

        vector<vector<Edge> > graph(N + 1);

        for (int i = 0; i < R; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(Edge(v, w));
            graph[v].push_back(Edge(u, w));
        }

        printf("Case %d: ", case_no);
        dijkstra(N, graph);
    }

    return 0;
}
