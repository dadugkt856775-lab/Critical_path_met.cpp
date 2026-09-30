#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 6;

    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 3});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 4});
    graph[2].push_back({3, 2});
    graph[2].push_back({4, 3});
    graph[3].push_back({5, 2});
    graph[4].push_back({5, 4});

    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (auto edge : graph[u])
            indegree[edge.first]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> earliest(n, 0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int duration = edge.second;

            earliest[v] = max(earliest[v],
                              earliest[u] + duration);

            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    int projectTime = *max_element(
        earliest.begin(), earliest.end()
    );

    cout << "Minimum Project Completion Time: "
         << projectTime;

    return 0;
}
