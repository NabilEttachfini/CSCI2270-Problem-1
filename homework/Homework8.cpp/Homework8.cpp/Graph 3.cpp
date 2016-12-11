#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include "Graph.hpp"

using namespace std;

Graph::Graph()
{
}
Graph::~Graph()
{
}
void Graph::addEdge(string v1, string v2, int dist) // this is COMPLETE
{
	// add code here
    // for loop inside  for loop, check if position is equal to v1 or v2, if equal do the second for loop with same check.
    for(int i=0; i<vertices.size(); i++)
    {
        if(vertices[i].name== v1)
        {
            for( int j=0; j< vertices.size(); j++) // looking at size of vector
            {
                if(vertices[j].name==v2 && i != j){
                    adjVertex av;
                    av.v=&vertices[j];
                    av.distance= dist;
                    vertices[i].adj.push_back(av);
                 }
            }
        }
    }
}

void Graph::addVertex(string n) // double check this code
{
	// add code here
    if(findVertex(n)==NULL)
    {
        vertex v;
        v.name= n;
        v.visited = false;
        v.district=-1;
        vertices.push_back(v);
    }

}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
	{
        cout << vertices[i].district << ":" <<vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
		{
            cout << vertices[i].adj[j].v->name;
			cout << " (" << vertices[i].adj[j].distance << " miles)"; 
            if (j != vertices[i].adj.size()-1)
                cout << "***";
        }
        cout << endl;
    }
}

void Graph::assignDistricts()
{
    // Starting district numbers at 1
    int distID = 1;

    // For each of the vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        // Only consider a vertex that has not been assigned a district.
        if (vertices[i].district == -1)
        {
            // Run breadth first traversal and assign each node in the network to this district.
            BFTraversalLabel(vertices[i].name,distID);
            distID++;
        }
    }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
  queue<vertex*> q;
    vertex* start;
  // Label all as unvisited.
  for(int i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
  }
  // Find the starting node and enqueue it.
  for(int i = 0; i < vertices.size(); i++)
  {
      if (vertices[i].name == startingCity)
      {
          // set current vertex to be visited
          start=&vertices[i];
          break;
      }
  }
    start->visited=true;
    start->district=distID; // not sure if this line is correct
 // Now do the rest of the search.
    q.push(start);
 while (q.empty() != true)
 {
     start = q.front();		// get the next one from the queue
     q.pop();						// remove that one from the queue
     for(int i=0;i<start->adj.size();i++) // adj just adjust size, inlcuded in one of the libraries
     {
         if(start->adj[i].v->visited==false)
         {
             start->adj[i].v->visited=true;
             q.push(start->adj[i].v);
             start->adj[i].v->district = distID;
         }
     }
 }
}
vertex * Graph::findVertex(std::string name)
{
	 // add code here
    // use for loop
    for(int i=0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            return &vertices[i];
        }
    }
    return NULL;
}

