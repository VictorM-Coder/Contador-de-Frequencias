#pragma once

#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

template<typename T>
class Graph {
    map<T, size_t> _map_vertices;
    vector<vector<size_t>> _adj_matrix;

public:
    Graph(size_t size) {
        _map_vertices = map<T, size_t>();
        _adj_matrix = vector(size, vector<size_t>(size, 0));
    }

    /**
     * @brief Caso o valor o vértice ainda não exista, ele é inserido no grafo
     * @param value
     */
    void add_vertex(const T& value) {
        if (_not_contains_in_map(value)) {
            size_t index = _map_vertices.size();
            _map_vertices.insert({value, index});

            //Adiciona uma nova coluna vazia para todas as linhas
            for (auto& row : _adj_matrix) {
                row.push_back(0);
            }
            //Adiciona uma nova linha
            _adj_matrix.push_back(vector<size_t>(_map_vertices.size(), 0));
        }
    }

    void add_edge(const T& value1, const T& value2) {
        add_vertex(value1);
        add_vertex(value2);

        size_t index1 = _map_vertices[value1];
        size_t index2 = _map_vertices[value2];

        _adj_matrix[index1][index2] = 1;
        _adj_matrix[index2][index1] = 1;
    }

    bool has_edge(const T& value1, const T& value2) const {
        if (_not_contains_in_map(value1) || _not_contains_in_map(value2)) {
            return false;
        }
        return _adj_matrix[_map_vertices.at(value1)][_map_vertices.at(value2)] != 0;
    }

    bool has_connection(const T& value1, const T& value2) const {
        if (_not_contains_in_map(value1) || _not_contains_in_map(value2))
            return false;

        size_t start = _map_vertices.at(value1);
        size_t goal  = _map_vertices.at(value2);
        vector<bool> visited(_adj_matrix.size(), false);
        stack<size_t> st;
        st.push(start);

        while (!st.empty()) {
            size_t actual = st.top();
            st.pop();
            if (actual == goal) return true;

            if (visited[actual]) continue;

            visited[actual] = true;

            for (size_t j = 0; j < _adj_matrix[actual].size(); ++j) {
                if (_adj_matrix[actual][j] != 0 && !visited[j]) {
                    st.push(j);
                }
            }
        }
        return false;
    }

    bool is_bipartite() {
        size_t size = _map_vertices.size();
        if (size == 0) return true;

        vector color(size, -1);
        queue<size_t> q;

        for (size_t start = 0; start < size; ++start) {
            if (color[start] != -1) continue;

            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                size_t u = q.front(); q.pop();

                for (size_t v = 0; v < size; ++v) {
                    if (_adj_matrix[u][v] == 0) continue;

                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

private:
    bool _not_contains_in_map(const T& value) const {
        return _map_vertices.find(value) == _map_vertices.end();
    }
};