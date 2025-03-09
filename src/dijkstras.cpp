#include "dijkstras.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
  int numVertices = G.numVertices;
  vector<int> distance(numVertices, INF);
  vector<bool> visited(numVertices, false);
  previous.resize(numVertices, -1);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prioQueue;
  distance[source] = 0;
  prioQueue.push({0, source});

  while(!prioQueue.empty()) {
    int u = prioQueue.top().second;
    prioQueue.pop();

    if (visited[u]){
      continue;
    }
    visited[u] = true;

    for (const Edge& edge : G[u]) {
      int v = edge.dst;
      int weight = edge.weight;

      if (!visited[v] && distance[u] + weight < distance[v]) {
        distance[v] = distance[u] + weight;
        previous[v] = u;
        prioQueue.push({distance[v], v});
      }
    }
  }
  return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    //cout << "Is this even running?" << endl;
    vector<int> shortestPath;
    if (distances[destination] == INF) {
        //cout << "No path to destination: " << destination << endl;
        return shortestPath;
    }

    set<int> visitedNodes;
    int i = destination;
    i = previous[i];
    for (i; i != -1; i = previous[i]) {
        shortestPath.push_back(i);
    }

    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

void print_path(const vector<int>& v, int total){

  for (int edge : v) {
    cout << edge << " ";
  }
  cout << endl;
  cout << "Total cost is " << total << endl;
}