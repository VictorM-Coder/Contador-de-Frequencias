#pragma once
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct Edge {
    string destiny;
    string movie;
};

struct BFSLevel {
    string actor;
    int level;
    string movie;
};

const string KEVIN_BACON = "Kevin Bacon";

class BaconGraph {
    unordered_map<string, vector<Edge>> _adj_list;

public:
    void add_edge(const string& origin, const string& destiny, const string& movie_name) {
        _adj_list[origin].push_back({destiny, movie_name});
        _adj_list[destiny].push_back({origin, movie_name});
    }

    void count_connections(const string& goal) {
        if (_adj_list.find(KEVIN_BACON) == _adj_list.end() ||
            _adj_list.find(goal) == _adj_list.end()) {
            cout << "Ator não encontrado no grafo." << endl;
            return;
        }

        unordered_set<string> visited;
        queue<BFSLevel> q;

        visited.insert(KEVIN_BACON);
        q.push({KEVIN_BACON, 0, ""});

        while (!q.empty()) {
            auto [current_actor, level, movie_used] = q.front();
            q.pop();

            if (current_actor == goal) {
                cout << "O Número de Bacon de " << goal << " é " << level << " pelo filme " << movie_used << endl;
                return;
            }

            for (const auto& edge : _adj_list[current_actor]) {
                if (visited.find(edge.destiny) == visited.end()) {
                    visited.insert(edge.destiny);
                    q.push({edge.destiny, level + 1, edge.movie});
                }
            }
        }

        cout << "Caminho não encontrado até " << goal << "." << endl;
    }
};
