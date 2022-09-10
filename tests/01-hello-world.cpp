#include <DataStructures/Edge.h>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <DataStructures/Graph.h>
int main()
{
Graph g; // 创建一张新的图

assert(g.AddVertex(1) == true);
assert(g.AddVertex(2) == true);
assert(g.AddVertex(3) == true);
assert(g.AddEdge(1, 2) == true);
assert(g.AddEdge(1, 1) == true);
assert(g.AddEdge(1, 1) == false);
assert(g.ContainsEdge(1, 1) == true);
assert(g.RemoveEdge(1,1) == true);
assert(g.AddEdge(1, 1) == true);
assert(g.GetVertices().size() == g.CountVertices()); // 4
/*
printf("%lu\n", g.GetEdges().size());
std::vector<Edge> test = g.GetEdges();
for(std::vector<Edge>::iterator it = test.begin() ; it != test.end() ; it++)
    {
        printf("(%d,%d)\n", (*it).GetSource(), (*it).GetDestination());
    }
*/
assert(g.GetEdges().size() == 2);
assert(g.GetIncomingEdges(1).size() == 1);
assert(g.GetOutgoingEdges(1).size() == 2); // {{1, 2}, {1, 3}}
assert(g.GetDegree(1) == 2);
assert(g.GetNeighbors(1).size() == 2); // {2, 3}
assert(g.GetNeighbors(2).size() == 0);
}