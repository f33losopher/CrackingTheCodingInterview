/*
 * Graph.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: G516674
 */
#include "Graph.h"

Graph::Graph(int V) {
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src) {
	priority_queue< iPair, vector <iPair>, greater<iPair > > pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int vertex = pq.top().second;
		pq.pop();

		cout << "Node to investigate: " << vertex << endl;

		list<iPair>::iterator itr;
		for (itr = adj[vertex].begin(); itr != adj[vertex].end(); ++itr) {

			int neighbor = itr->first;
			int weightToNeighbor = itr->second;

			cout << "  Neighbor: " << neighbor << " Weight to Neighbor: " << weightToNeighbor << endl;

			cout << "  dist[" << neighbor << "]: " << dist[neighbor] << endl;
			cout << "  dist[" << vertex << "]:   " << dist[vertex] << endl;
			cout << "  dist[" << vertex << "] + " << weightToNeighbor << " = " << dist[vertex] + weightToNeighbor << endl;
			if (dist[neighbor] > dist[vertex] + weightToNeighbor) {
				dist[neighbor] = dist[vertex] + weightToNeighbor;
				pq.push(make_pair(dist[neighbor], neighbor));
			}
		}
	}

	printf("Vertex   Distance from Source\n");
	for (int i=0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);

	cout << "********************\n";
}


