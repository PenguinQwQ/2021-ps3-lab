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
assert(g.AddEdge(1,2) == true);
assert(g.RemoveVertex(2) == true);
assert(g.ContainsEdge(1,2) == false);

/*
printf("%lu\n", g.GetEdges().size());
std::vector<Edge> test = g.GetEdges();
for(std::vector<Edge>::iterator it = test.begin() ; it != test.end() ; it++)
    {
        printf("(%d,%d)\n", (*it).GetSource(), (*it).GetDestination());
    }
*/



}