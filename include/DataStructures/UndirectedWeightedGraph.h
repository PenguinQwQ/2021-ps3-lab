#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <DataStructures/WeightedGraph.h>
#include <utility>
class UndirectedWeightedGraph : public WeightedGraph{
    public:
    UndirectedWeightedGraph();
    ~UndirectedWeightedGraph();
    bool AddEdge(int vertex1, int vertex2, int weight) override;
    bool RemoveEdge(int vertex1, int vertex2) override;
    int CountEdges() const override;
    std::vector<WeightedEdge> GetEdges() const;
    int GetDegree(int vertex) const override;
    private:
    std::vector<int> selfring;
};
















#endif