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
    WeightedGraph<double> g;
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(1) == false);  
    assert(g.AddEdge(1,2,0.2) == true);
    assert(g.AddEdge(1,3,0.3) == true);
    assert(g.GetWeight(1, 2) == 0.2);
    
    return 0;
}