/*
 * Graph.h
 *
 *  Created on: Mar 1, 2018
 *      Author: G516674
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

// Code taken from
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
class Graph {
	int V;

	// Destination Vertex, Weight to Vertex
	list<iPair> *adj;

public:
	Graph(int V);

	void addEdge(int u, int v, int w);

	void shortestPath(int s);
};



#endif /* GRAPH_H_ */
