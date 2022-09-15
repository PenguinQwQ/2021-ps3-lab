#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <utility>

class WeightedGraph : public Graph{
 public:
  WeightedGraph();
  ~WeightedGraph();
 public:
  bool AddEdge(int vertex1, int vertex2, int weight);
  bool RemoveEdge(int vertex1, int vertex2, int weight);
 public:
  int GetWeight(int vertex1, int vertex2) const;
  std::vector<WeightedEdge> GetEdges() const;
  std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;
  std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
  private:
   std::map<pair<int, int>, int> G;

};
#endif