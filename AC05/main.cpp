#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

#include "BaconGraph.hpp"
using namespace std;

int main() {
    BaconGraph graph;
    string line;
    set<string> actors;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string actor1, movie, actor2;

        getline(ss, actor1, ';');
        getline(ss, movie, ';');
        getline(ss, actor2, ';');

        graph.add_edge(actor1, actor2, movie);

        actors.insert(actor1);
        actors.insert(actor2);
    }

    vector names(actors.begin(), actors.end());
    sort(names.begin(), names.end());

    for (const auto& nome : names) {
        graph.count_connections(nome);
    }

    return 0;
}
