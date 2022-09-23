#include <DataStructures/Edge.h>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
int main()
{
UndirectedGraph g;
//
assert(g.AddVertex(1) == true);
assert(g.AddVertex(2) == true);
assert(g.AddVertex(3) == true);
assert(g.AddVertex(4) == true);
assert(g.AddVertex(5) == true);

assert(g.RemoveVertex(5) == true);
assert(g.RemoveVertex(5) == false);

assert(g.AddEdge(1, 2) == true);
assert(g.AddEdge(1, 2) == false);
assert(g.AddEdge(2, 1) == false);

assert(g.AddEdge(1, 3) == true);
assert(g.AddEdge(1, 1) == true);
assert(g.AddEdge(1, 1) == false);
assert(g.ContainsEdge(1, 1) == true);
//1->2, 1->3, 2->1, 1->1

assert(g.RemoveEdge(1,1) == true);
assert(g.ContainsEdge(1,1) == false);
assert(g.RemoveEdge(1,1) == false);
assert(g.AddEdge(1, 1) == true);

assert(g.CountVertices() == 4);
assert(g.CountEdges() == 3);
assert(g.ContainsVertex(5) == false);
assert(g.ContainsVertex(1) == true);
   
assert(g.ContainsEdge(1,1) == true);
assert(g.ContainsEdge(1,2) == true);
assert(g.ContainsEdge(2,1) == true);
assert(g.ContainsEdge(3,1) == true);

assert(g.GetEdges().size() == 3);
assert(g.GetDegree(1) == 4);
assert(g.GetNeighbors(1).size() == 3);
/*
printf("%lu\n", g.GetEdges().size());
std::vector<Edge> test = g.GetEdges();
for(std::vector<Edge>::iterator it = test.begin() ; it != test.end() ; it++)
    {
        printf("(%d,%d)\n", (*it).GetSource(), (*it).GetDestination());
    }
*/



}