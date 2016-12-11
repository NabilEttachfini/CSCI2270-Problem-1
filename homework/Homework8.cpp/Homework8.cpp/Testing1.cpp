//
//  Testing1.cpp
//  Homework8.cpp
//
//  Created by Nabil Ettachfini on 11/14/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//
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

void Graph::addEdge(string v1, string v2, int dist)
{
    if (dist < 0)
    {
        //check for bad input
        return;
    }
    //set up adjVertex to add
    adjVertex a;
    //find the home vertex
    vertex * home = findVertex(v1);
    //find the vertex it connects to
    vertex * dest = findVertex(v2);
    if (home == NULL || dest == NULL)
    {
        //check if the vertices were found
        cout << "addEdge: vertices not found" << endl;
        return;
    }
    //set the destination vector pointer
    a.v = dest;
    //set the distance
    a.distance = dist;
    //put the adjVector in the adj vector of the vertex
    home->adj.push_back(a);
}

void Graph::addVertex(string n)
{
    //make a temporary vertex variable
    vertex v;
    //set its name
    v.name = n;
    //initialize it to be un-visited
    v.visited = false;
    //initialize the district to -1 (unassigned)
    v.district = -1;
    //put vertex in class member vertices vector
    vertices.push_back(v);
}

void Graph::displayEdges()
{
    //iterate through each vertex
    for(int i = 0; i < vertices.size(); i++)
    {
        //print district and home city name
        cout << vertices[i].district << ":" <<vertices[i].name << "-->";
        //iterate through all adjacent citys
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
            //print each connected city name and distance from home city
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
            //incriment to next district
            distID++;
        }
    }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
    if (distID < 0)
    {
        cout << "BFTTraversalLabel: distID must be positive integer" << endl;
        return;
    }
    queue<vertex*> q;
    // Label all as unvisited.
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
    // Find the starting node and enqueue it.
    for(int i = 0; i < vertices.size(); i++)
    {
        // Find the starting node and enqueue it.
        if (vertices[i].name == startingCity)
        {
            //push starting city to stack
            q.push(&vertices[i]);
            //set that it is visited
            vertices[i].visited = true;
            //set its district ID
            vertices[i].district = distID;
        }
    }
    // Now do the rest of the search.
    while (q.empty() != true)
    {
        //get the first node in the queue
        vertex * u = q.front();		// get the next one from the queue
        //pop that element from of the queue
        q.pop();						// remove that one from the queue
        for (int j = 0; j < u->adj.size(); j++)
        {
            if (u->adj[j].v->visited == false)
            {
                //set vertex as visited
                u->adj[j].v->visited = true;
                //push to queue
                q.push(u->adj[j].v);
                //set the district ID
                u->adj[j].v->district = distID;
            }
        }
    }
}

vertex * Graph::findVertex(std::string name)
{
    //iterate through list of vertices
    int i;
    for (i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == name)
        {
            //when we find it, return its address
            return &vertices[i];
        }
    }
    //else return null (not found)
    return NULL;
}
