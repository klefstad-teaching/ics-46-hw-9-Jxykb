#include "dijkstras.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
  int numVertices = G.numVertices;
  vector<int> distances(numVertices, INF);
  vector<bool> visited(numVertices, false);
  previous.resize(numVertices, -1);

  priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
  minHeap.push(Edge(source, 0));
  distances[source] = 0;

  while (!minHeap.empty()) {
    Edge curr = minHeap.top();
    minHeap.pop();
    int u = curr.src;

    if (visited[u]) {
      continue;
    }
    visited[u] = true;

    for (const Edge& edge : G[u]) {
      int v = edge.dst;
      int weight = edge.weight;
      if (!visited[v] && distances[u] + weight < distances[v]) {
        distances[v] = distances[u] + weight;
        previous[v] = u;
        minHeap.push(Edge(v, distances[v]));
      }
    }
  }
  return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
  vector<int> shortestPath;
  if(distances[destination] == INF){
    return shortestPath;
  }

  for(int i = destination; i != -1; i = previous[i]){
    shortestPath.push_back(i);
  }
  reverse(shortestPath.begin(), shortestPath.end());
  return shortestPath;
}

void print_path(const vector<int>& v, int total){
  if (v.empty()) {
    cout << "Empty Path" << endl;
  }
  for (int edge : v) {
    cout << edge << " ";
  }
  cout << endl;
  cout << "Total Cost is " << total;
}