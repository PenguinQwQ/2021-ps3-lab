#include <DataStructures/Edge.h>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
int main()
{
WeightedGraph g; // 创建一张新的图
assert(g.AddVertex(1) == true);
assert(g.AddVertex(2) == true);
assert(g.AddVertex(3) == true);
assert(g.AddEdge(1,2,2) == true);
assert(g.AddEdge(1,3,2) == true);
//assert(g.AddEdge(1,3,2) == false);
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