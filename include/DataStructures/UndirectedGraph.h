#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <utility>
class UndirectedGraph : public Graph{
    public:
    UndirectedGraph();
    ~UndirectedGraph();
    bool AddEdge(int vertex1, int vertex2) override;
    bool RemoveEdge(int vertex1, int vertex2) override;
    int CountEdges() const override;
    std::vector<Edge> GetEdges() const;
    int GetDegree(int vertex) const override;
    private:
    std::vector<int> selfring;
};

#endif