/**************************************************************
* File:    Graph.h
* Project: CMSC 341 - Project 5 - Graph Traversal 
* Author : Christopher Sidell
* Date   : 12/9/2014
* Section: Lecture-01
* E-mail: csidell1@umbc.edu
*
Graph definition, Vertex definition and implementation and edge
	definition and implementation
*************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

//Turn this to true to see debug output
#define PRJ_DEBUG false

#include "Util.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <math.h>
#include <list>

using namespace std;

//Forward defintion for Vertex class
class Vertex;

/*
	Edge Class Definition & Implementation (for completeness)
	Held by the vertex class to define an endpoint between
		two nodes with a cost
*/
class Edge
{
public:
	//Constructor, takes an endpoint and a cost
	Edge(Vertex* ve, int cost)
	:m_dest(ve), m_cost(cost){};

	//GetCost
	//Returns cost of edge
	int GetCost() {return m_cost;}

	//GetDest
	//Returns end vertex
	Vertex* GetDest() {return m_dest;}
private:
	//Pointer to end vertex
	Vertex* m_dest;
	//Weight of edge
	int m_cost;
};

/*
	Vertex Class Definition & Implementation (for completeness)
	Used by the graph class to hold the edges to other nodes
*/
class Vertex
{
public:
	//Vertex
	//Define node with an id
	Vertex(int id):m_id(id){};

	//~Vertex
	//Delete all edges
	~Vertex()
	{
		//For all edges in map
		for (std::map<int,Edge*>::iterator it=m_adj.begin(); 
				it!=m_adj.end(); ++it)
		{
			delete it->second;
		}
	}

	//Id
	//Returns id of the vertex
	int Id(){return m_id;}

	/*
		AddEdge
		Adds edge to the vertex
		Precondition: Vertex is defined and cost is positive
	*/
	void AddEdge(Vertex* to, const int cost)
	{
		//Debug printing
		if(PRJ_DEBUG)
			{ cout << "\tVERTEX: Edge("<< cost <<") from " 
			<< Id() << " to " << to->Id() << endl; }

		//Insert id * edge pair
		m_adj.insert(pair<int,Edge*>(to->Id(), new Edge(to, cost)));
	}

	//Print
	//Prints vertex information to console
	void Print()
	{
		//For all edges in map
		for (std::map<int,Edge*>::iterator it=m_adj.begin(); 
				it!=m_adj.end(); ++it)
		{	
			//Debug print them to console
			if(PRJ_DEBUG)
				{ cout << "\tdest: " << it->second->GetDest()->Id() 
				<< " | cost: " << it->second->GetCost() << endl; }
		}
	}

	//GetAdj
	//Returns edge map to caller
	map<int, Edge*> GetAdj() { return m_adj; }
private:
	//Holds id of vertex
	int m_id; 

	//Holds all edges to nodes with weights
	map<int, Edge*> m_adj;
};

/*
	Graph Class Definition
	Holder of vertex's and graph traversal functions
*/
class Graph
{
public:
	/*****************
	 * Graph
	 * 	Default constructor
	 * Precondition: None
	 * Postcondition: Graph object exists
	 *****************/
	Graph();

	/*****************
	 * Graph
	 * 	Sets up all nodes on graph, no edges are created
	 * Precondition: none
	 * Postcondition: Graph nodes are created
	 *****************/
	Graph(string file);

	/*****************
	 * ~Graph
	 * 	Destroy all edge and vertex instances in graph
	 * Precondition: Graph created
	 * Postcondition: All memory released
	 *****************/
	~Graph();

	/*****************
	 * AddVertex
	 * 	Add new vertex to graph
	 * Precondition: id doesn't already exist in graph
	 * Postcondition: New node is added at given number
	 *****************/
	void AddVertex(const int id);

	/*****************
	 * AddEdge
	 * 	Add edge from node id(from) to node id(to) with weight(cost)
	 * Precondition: from & to exist in graph, cost is positive
	 * Postcondition: Edge is added between both nodes (undirected)
	 *****************/
	void AddEdge(const int from, const int to, int cost);

	/*****************
	 * trips
	 * 	Create edges and calculate how many trips it takes x tourists from
	 * 		source to destination
	 * Precondition: source and destination exist, tourists is positive, nonzero
	 * Postcondition: 
	 *****************/
	int trips(int source, int destination, int tourists);

	/*****************
	 * Dijkstra
	 * 	Modified Dijkstra's algorithm to find out shortest trip length
	 * Precondition: Source exists in graph, distV and prev are defined
	 * Postcondition: distV will be rewritten, previous will be rewritten
	 *****************/
	void Dijkstra(int source, vector<int>& distV, vector<Vertex*>& previous);

	/*****************
	 * Print (DEBUG ONLY)
	 * 	Print graph with all vertexes and edges
	 * Precondition: None
	 * Postcondition: None
	 *****************/
	void Print()
	{
		if(PRJ_DEBUG)
			cout << "GRAPH:" << endl;
		for (std::map<int,Vertex*>::iterator it=m_vmap.begin(); it!=m_vmap.end(); ++it)
		{
			if(PRJ_DEBUG)
				cout << "node: " << it->second->Id() << endl;
			it->second->Print();
		}
	}

	/*****************
	 * PrintDistances (DEBUG ONLY)
	 * 	Print distances from dijkstra's algorithm
	 * Precondition: Dijkstra's algorithm was run once
	 * Postcondition: none
	 *****************/
	void PrintDistances()
	{
		for (unsigned int i = 0; i < m_distance.size(); ++i)
		{
			if(PRJ_DEBUG)
				cout << i+1 << " - " << m_distance[i] << endl;
		}
	}
private:
	//Holds vertex map
	map<int, Vertex*> m_vmap;

	//Hold all edge information
	vector<string> m_edges;

	//Hold all distance information
	vector<int> m_distance;
};

#endif