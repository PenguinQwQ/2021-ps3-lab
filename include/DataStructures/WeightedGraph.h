#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>

class WeightedGraph{
 public:
  WeightedGraph();
  ~WeightedGraph();
 public:
  bool AddVertex(int vertex);
  bool RemoveVertex(int vertex);
  bool AddEdge(int vertex1, int vertex2, int weight);
  bool RemoveEdge(int vertex1, int vertex2, int weight);
 public:

  int CountVertices() const;
  int CountEdges() const;
  bool ContainsVertex(int vertex) const;
  bool ContainsEdge(int vertex1, int vertex2) const;
  int GetWeight(int vertex1, int vertex2) const;
  std::vector<int> GetVertices() const;
  std::vector<WeightedEdge> GetEdges() const;
  std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;
  std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
  int GetDegree(int vertex) const;
  std::vector<int> GetNeighbors(int vertex) const;
  private:
   std::map<int, std::vector<WeightedEdge> > Edges;//构造一个map，map[x]返回x键值节点的相连边的列表，用来存储边
   std::vector<int> vertexs; //构造一个vector，用来存储点。
};
#endif