#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stack>
using namespace std;

void bfs(map<string, vector<string>>& graph, string start) {
    queue<string> q;
    map<string, int> distance;
    set<string> visited;

    q.push(start);
    visited.insert(start);
    distance[start] = 0;

    while (!q.empty()) {
        string node = q.front();
        q.pop();

        for (auto& neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
                distance[neighbor] = distance[node] + 1;
            }
        }
    }

    cout << "=== 너비 우선 탐색 (BFS) ===" << endl;
    for (auto& d : distance)
        cout << d.first << ": 거리 " << d.second << endl;
}

void dfs_topo(map<string, vector<string>>& graph, string node,
    set<string>& visited, stack<string>& st) {
    visited.insert(node);

    for (auto& neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end())
            dfs_topo(graph, neighbor, visited, st);
    }

    st.push(node);
}

void topological_sort(map<string, vector<string>>& graph) {
    set<string> visited;
    stack<string> st;

    for (auto& pair : graph) {
        if (visited.find(pair.first) == visited.end())
            dfs_topo(graph, pair.first, visited, st);
    }

    cout << "\n=== 위상 정렬 결과 ===" << endl;
    bool first = true;
    while (!st.empty()) {
        if (!first) cout << " → ";
        cout << st.top();
        st.pop();
        first = false;
    }
    cout << endl;
}


int main() {
    map<string, vector<string>> graph1 = {
        {"철수", {"영희", "준호", "승우", "동근"}},   
        {"영희", {"철수", "동근"}},
        {"동근", {"영희", "재상", "철수"}},        
        {"준호", {"철수", "승우"}},
        {"승우", {"철수", "준호","재상"}},
        {"재상", {"승우", "동근"}}
    };

    map<string, vector<string>> graph2 = {
        {"점화", {"수프 넣기", "라면 넣기", "계란 풀기"}},
        {"냄비에 물 붓기", {"점화"}},
        {"라면 넣기", {"계란 풀기"}},
        {"수프 넣기", {"계란 풀기"}},
        {"계란 풀기", {}},
        {"라면 봉지 뜯기", {"라면 넣기", "수프 넣기"}}
    };

    bfs(graph1, "철수");
    topological_sort(graph2);
    return 0;
}