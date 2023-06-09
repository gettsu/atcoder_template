#include <bits/stdc++.h>
std::vector<int> topological_sort(std::vector<std::vector<int>>& G, int V) {
    // 入力次数の検査
    std::vector<int> indegree(V, 0);
    for (int i = 0; i < V; ++i) {
        for (auto& v : G[i]) {
            indegree[v]++;
        }
    }
    // 結果を保持する配列
    std::vector<int> sorted_vertices;
    // 入力の次数が0の点を見つけたら、キューに加える
    std::queue<int> que;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    // キューが空になるまで操作する
    while (que.size()) {
        int v = que.front();
        que.pop();

        for (auto& nx : G[v]) {
            indegree[nx]--;
            if (indegree[nx] == 0)
                que.push(nx);
        }

        sorted_vertices.emplace_back(v);
    }
    return sorted_vertices;
}
