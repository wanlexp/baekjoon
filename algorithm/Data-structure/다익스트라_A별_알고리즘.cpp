#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

struct Edge {
    string to;
    int weight;
};


pair<vector<string>, int> dijkstra(
    unordered_map<string, vector<Edge>>& graph,
    const string& start,
    const string& goal
) {
    unordered_map<string, int> g;
    unordered_map<string, string> parent;

    // 초기화
    for (auto& node : graph) {
        g[node.first] = numeric_limits<int>::max();
        parent[node.first] = "";
    }
    g[start] = 0;

    // min-heap: (cost, node)
    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
    > pq;

    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (node == goal) break;
        if (cost > g[node]) continue;

        for (auto& edge : graph[node]) {
            int newCost = cost + edge.weight;
            if (newCost < g[edge.to]) {
                g[edge.to] = newCost;
                parent[edge.to] = node;
                pq.push({ newCost, edge.to });
            }
        }
    }

    // 경로 복원
    vector<string> path;
    string cur = goal;
    while (cur != "") {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    return { path, g[goal] };
}

pair<vector<string>, int> a_star(
    unordered_map<string, vector<Edge>>& graph,
    unordered_map<string, int>& h,
    const string& start,
    const string& goal
) {
    unordered_map<string, int> g;
    unordered_map<string, string> parent;

    // 초기화
    for (auto& node : graph) {
        g[node.first] = numeric_limits<int>::max();
        parent[node.first] = "";
    }
    g[start] = 0;

    // min-heap: (f = g + h, node)
    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
    > pq;

    pq.push({ h[start], start });

    while (!pq.empty()) {
        auto [fcost, node] = pq.top();
        pq.pop();

        if (node == goal) break;

        for (auto& edge : graph[node]) {
            int newG = g[node] + edge.weight;
            int newF = newG + h[edge.to];

            if (newG < g[edge.to]) {
                g[edge.to] = newG;
                parent[edge.to] = node;
                pq.push({ newF, edge.to });
            }
        }
    }

    // 경로 복원
    vector<string> path;
    string cur = goal;
    while (cur != "") {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    return { path, g[goal] };
}

int main() {
    unordered_map<string, vector<Edge>> graph = {
       {"v0", {{"v1", 10}, {"v2", 17}, {"v3", 30},{"v4", 23},{"v5", 25}}},
        {"v1", {{"v2",20}}},
        {"v2", {{"v5", 17}}},
        {"v3", {{"v1", 19},{"v6", 24}}},
        {"v4", {{"v3", 16}, {"v5", 28}, {"v6", 18}}},
        {"v5", {{"v7", 39}, {"v8", 25}}},
        {"v6", {{"v9", 20}}},
        {"v7", {{"v4", 20}, {"v9", 28}}},
        {"v8", {{"v7", 29}}},
        {"v9", {{"v8", 40}}}
    };

    unordered_map<string, int> h = {
       {"v0", 52}, {"v1", 61}, {"v2", 68}, {"v3", 40},
        {"v4", 34}, {"v5", 52}, {"v6", 19}, {"v7", 19},
        {"v8", 39}, {"v9", 0}
    };

    string start = "v0";
    string goal = "v9";

    auto [d_path, d_cost] = dijkstra(graph, start, goal);
    cout << "Dijkstra shortest path: ";
    for (auto& n : d_path) cout << n << " ";
    cout << "\nDijkstra cost: " << d_cost << "\n\n";

    auto [a_path, a_cost] = a_star(graph, h, start, goal);
    cout << "A* shortest path: ";
    for (auto& n : a_path) cout << n << " ";
    cout << "\nA* cost: " << a_cost << "\n";

    return 0;
}
