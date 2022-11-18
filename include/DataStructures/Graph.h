#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <set>

#include <DataStructures/Edge.h>

const int N = 20000;

class Graph {
 public:
  Graph();
  ~Graph();
 public: 
  bool AddVertex(int vertex);
  bool RemoveVertex(int vertex);
  virtual bool AddEdge(int vertex1, int vertex2);
  virtual bool RemoveEdge(int vertex1, int vertex2);
 public:
  int CountVertices() const;
  virtual int CountEdges() const;
  bool ContainsVertex(int vertex) const;
  virtual bool ContainsEdge(int vertex1, int vertex2) const;
  std::vector<int> GetVertices() const;
  std::vector<Edge> GetEdges() const;
  std::vector<Edge> GetIncomingEdges(int vertex) const;
  std::vector<Edge> GetOutgoingEdges(int vertex) const;
  virtual int GetDegree(int vertex) const;
  std::vector<int> GetNeighbors(int vertex) const;
  public:
   std::map<int, std::vector<Edge> > Edges;//构造一个map，map[x]返回x键值节点的相连边的列表，用来存储边
   std::set<int> vertexs; //构造一个vector，用来存储点。
   
};



#endif
