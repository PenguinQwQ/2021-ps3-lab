#include <DataStructures/Edge.h>
#include <cassert>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <iostream>
#include <cstdio>
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
int main()
{
    /*
    WeightedGraph<double> g;
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(1) == false);  
    assert(g.AddEdge(1,2,0.2) == true);
    assert(g.AddEdge(1,3,0.3) == true);
    assert(g.GetWeight(1, 2) == 0.2);
    */
auto g = new Graph();
for (int i = 1 ; i <= 6 ; i++)
    	g->AddVertex(i);
g->AddEdge(1, 2);
g->AddEdge(2, 3);
g->AddEdge(3, 4);
g->AddEdge(4, 1);
g->AddEdge(1, 2);
g->AddEdge(5, 6);
g->AddEdge(6, 5);

BreadthFirstSearcher<Graph>::VisitAllVertices(g, 1, [](int u) -> void{
    printf("%d", u);
});
BreadthFirstSearcher<Graph>::VisitAllVertices(g, 5, [](int u) -> void{
    printf("%d", u);
});
delete g;


    return 0;
}