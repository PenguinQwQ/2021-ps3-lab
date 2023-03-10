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
#include <Algorithms/ShortestPaths.h>
#include <Algorithms/DijkstraShortestPaths.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/MultiSourceShortestPaths.h>

#include <Algorithms/FloydShortestPaths.h>

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
   /*
auto g = new Graph();
for (int i = 1 ; i <= 6 ; i++)
    	g->AddVertex(i);
g->AddEdge(1, 2);
g->AddEdge(2, 3);
g->AddEdge(3, 4);
g->AddEdge(4, 1);
g->AddEdge(5, 6);
g->AddEdge(6, 5);
 
BreadthFirstSearcher<Graph>::VisitAllVertices(g, 1, [](int u) -> void{
    printf("%d ", u);
});
printf("\n");
BreadthFirstSearcher<Graph>::VisitAllVertices(g, 5, [](int u) -> void{
    printf("%d ", u);
});

printf("\n");
DepthFirstSearcher<Graph>::VisitAllVertices(g, 1, [](int u) -> void{
    printf("%d ", u);
});
printf("\n");
DepthFirstSearcher<Graph>::VisitAllVertices(g, 5, [](int u) -> void{
    printf("%d ", u);
});
delete g;

*/
  auto *g = new UndirectedWeightedGraph<int>();
  for (int i = 1; i <= 6; ++i) {
    g->AddVertex(i);
  }
  g->AddEdge(1, 2, -1);
  g->AddEdge(2, 3, -2);
  g->AddEdge(3, 4, -3);
  g->AddEdge(4, 1, -4);
  g->AddEdge(5, 6, 5);
  g->AddEdge(6, 5, 6);
  
  ShortestPaths<UndirectedWeightedGraph<int>> *p = nullptr;
  for (int i = 1; i <= 6; ++i) {
    p = new DijkstraShortestPaths<UndirectedWeightedGraph<int>>(g, i);
    for (int j = 1; j <= 6; ++j) {
      printf("%d", p->HasPathTo(j));
    }
    printf("\n");
    delete p;
  }

  printf("Next The BellmanFord\n");
  for (int i = 1; i <= 6; ++i) {
    p = new BellmanFordShortestPaths<UndirectedWeightedGraph<int>>(g, i);
    for (int j = 1; j <= 6; ++j) {
      printf("%d", p->HasPathTo(j));
    }
    printf("\n");
    delete p;
  }
  printf("Next The Floyd!\n");
  MultiSourceShortestPaths<UndirectedWeightedGraph<int>> *mp = nullptr;
  mp = new FloydShortestPaths<UndirectedWeightedGraph<int> >(g);
    for (int i = 1 ; i <= 6 ; i++)
      printf("%d ", mp->HasPathOf(1, i));
    printf("\n");
  delete mp;
  delete g;
    return 0;
}