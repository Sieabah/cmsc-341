/**************************************************************
* File:    Graph.cpp
* Project: CMSC 341 - Project 5 - Graph Traversal 
* Author : Christopher Sidell
* Date   : 12/9/2014
* Section: Lecture-01
* E-mail: csidell1@umbc.edu
*
Graph defintition
*************************************************************/

#include "Graph.h"
#include <fstream>
#include <sstream>
#include "Util.h"
#include "Exception.h"
#include <stdlib.h>
#include <queue>
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
#include <list>

#define INFINITE 0x3fffffff // 7*f ~ 1.000.000.000

//Graph
//Default constructor
Graph::Graph()
{}

//Graph(string)
//Constructor that initializes the graph with given file
Graph::Graph(string file)
{
	//Check if file exists
	if(!Util::FileExists(file.c_str()))
	{
		throw Exceptions("File does not exist!");
	}

	//Define the input file
	std::ifstream ifile;

	//Open file given
	ifile.open(file.c_str());

	//Define line
	std::string line;

	//Get and split numbers
	getline(ifile,line);
	std::stringstream ssin(line);

	//Get # of nodes and edges
	std::string nodes, edges;
	ssin >> nodes;
	ssin >> edges;

	//Create all nodes we'll need right now
	for (int i = 1; i < atoi(nodes.c_str())+1; ++i)
	{
		AddVertex(i);
		m_distance.push_back(INFINITE);
	}

	//While there are edges to define
	while(getline(ifile,line))
	{
		//Push line to edge holder until we get more information
		m_edges.push_back(line);
	}

	//Close file
	ifile.close();
}

//~Graph
//Delete all vertex's
Graph::~Graph()
{
	//For all vertex's in vertex map
	for (std::map<int,Vertex*>::iterator it=m_vmap.begin(); it!=m_vmap.end(); ++it)
		delete it->second;
}

//trips
//Calculate how many trips it'll take to bring x tourists from src to dest
int Graph::trips(int source, int destination, int tourists)
{
	//Create edges with tourists trip
	for (unsigned int i = 0; i < m_edges.size(); ++i)
	{
		//define holders
		int src, dest, cost;
		//Get edge information
		std::stringstream ssin(m_edges[i]);
		//Split out the numbers
		ssin >> src >> dest >> cost;

		//DEBUG PRINTING
		if(PRJ_DEBUG)
			cout << m_edges[i] << "| s,d,c " << src << " " << dest<< " " << cost << endl;

		//Convert costs based on amount of people needing to pass through
		AddEdge(src,dest,ceil((double)tourists/(cost-1)));
	}

	//DEBUG print of graph
	Print();

	//Define paths for Dijkstra's
	vector<Vertex*> paths;

	//Reun Dijkstra's algorithm on graph
	Dijkstra(source, m_distance, paths);

	for (vector<Vertex*>::iterator it = paths.begin() ; it != paths.end(); ++it)
	{
		if(*it)
			cout << (*it)->Id() << endl;
	}

	//Return distance * 2 for return trips, subtract one for final trip
	//return (m_distance[destination-1]/2)-1;
	return m_distance[destination-1];
}

//Dijkstra
//Complete modified dijkstra's algorithm on graph
void Graph::Dijkstra(int source, vector<int>& distV, vector<Vertex*>& previous)
{
	//Offset source
	source = source-1;

	//Setup distances
	int n = (int)distV.size();

	//Set all distances infinite
	for (int i = 0; i < n; ++i)
	{
		distV[i] = INFINITE;
	}

	//Set source to 0
	distV[source] = 0;

	//Get source vertex
	Vertex* src = m_vmap.at(source+1);

	//Create queue
	set< pair<int, Vertex*> > vqueue;

	//Remove any previous path information
	previous.clear();
	previous.resize(n, NULL);

	//Push first node
	vqueue.insert(make_pair(distV[src->Id()-1],src));

	//Until we're out of nodes
	while(!vqueue.empty())
	{
		//Debug printing
		PrintDistances();

		//Get the weight
		int weight = vqueue.begin()->first;

		//Get the vertex
		Vertex* ve = vqueue.begin()->second;

		//Pop off node
		vqueue.erase(vqueue.begin());

		//Get adj list
		map<int, Edge*> adjList = ve->GetAdj();

		//Go through edges
		for (std::map<int,Edge*>::iterator it=adjList.begin(); it!=adjList.end(); ++it)
		{
			//vertex #
			int v = it->second->GetDest()->Id()-1;
			//weight to go to
			int w = it->second->GetCost();

			int distance = weight+w;//;weight + w;
			if(distance < distV[v])
			{
				vqueue.erase(make_pair(distV[v], it->second->GetDest()));

				distV[v] = distance;
				previous[v] = ve;
				vqueue.insert(make_pair(distV[v], it->second->GetDest()));
			}

		}
	}

	//Debug print distances
	PrintDistances();
}

//AddVertex
//create vertex in vmap with id, and give vertex id
void Graph::AddVertex(const int id)
{
	m_vmap.insert(pair<int, Vertex*>(id,new Vertex(id)));
}

//AddEdge
//Add edge between two nodes with weight
void Graph::AddEdge(const int from, const int to, int cost)
{
	//Debug print
	if(PRJ_DEBUG)
		cout << "\tGRAPH: Edge from: " << from << " to " << to << " with " << cost << endl;

	//Get from node
	Vertex* source = m_vmap.at(from);
	//Get dest node
	Vertex* dest = m_vmap.at(to);

	//Add edge source->dest w/ cost
	source->AddEdge(dest,cost);

	//Add edge source<-dest w/ cost
	dest->AddEdge(source,cost);
}