#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <utility>

template<class T, class U>
std::pair<T, U> operator < (const std::pair<T, U>& x, const std::pair<T, U>& y)
{
    return x.first < y.first ||  ((x.first == y.first) && x.second < y.second);
}

class WeightedGraph : public Graph{
 friend class UndirectedWeightedGraph; 
 public:
  WeightedGraph();
  ~WeightedGraph();
 public:
  virtual bool AddEdge(int vertex1, int vertex2, int weight);
 public:
  int GetWeight(int vertex1, int vertex2) const;
  std::vector<WeightedEdge> GetEdges() const;
  std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;
  std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
  private:
   std::map<std::pair<int, int>, int> G;

};
#endif