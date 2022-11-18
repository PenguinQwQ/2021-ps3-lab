#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>
template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
    public:
        BellmanFordShortestPaths(const TGraph *graph, int source);
        ~BellmanFordShortestPaths(){};
};
template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    this->INF = (typename TGraph::value_type)1145141919;
    auto vertices = graph->GetVertices();
    //Initialize the distance
    for (auto p : vertices)
        this->d[p] = this->INF;
    this->d[source] = 0;
    auto edges = graph->GetEdges();
    int V = vertices.size();
    int u, v;
    for (int i = 1 ; i <= V - 1 ; i++)
    {
        for (auto e : edges)
        {
            u = e.GetSource();
            v = e.GetDestination();
            typename TGraph::value_type w = e.GetWeight();
            if(this->d[v] > this->d[u] + w)
                this->d[v] = this->d[u] + w;
        }
    }
}



#endif