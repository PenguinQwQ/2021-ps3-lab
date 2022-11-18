#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>
#include <assert.h>
template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
    public:
        BellmanFordShortestPaths(const TGraph *graph, int source);
        ~BellmanFordShortestPaths(){};
};
template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
    auto vertices = graph->GetVertices();
    //Initialize the distance
    for (auto p : vertices)
    {
        this->vis[p] = false;
        this->reach[p] = false;
  //      std::cout << this->d[p] << std::endl;
    }
    this->d[source] = typename TGraph::value_type();
    this->vis[source] = true;

    auto edges = graph->GetEdges();
    int V = vertices.size();
    int u, v;
    for (int i = 1 ; i <= V ; i++)
    {
        for (auto e : edges)
        {
            u = e.GetSource();
            v = e.GetDestination();
            typename TGraph::value_type w = e.GetWeight();
            if(this->vis[u] == false) continue;
            if(this->vis[u] && this->vis[v] == false)
                {
                    this->vis[v] = true;
                    this->d[v] = this->d[u] + w;
                    continue;
                }
            if(this->vis[u] && this->vis[v] && (this->d[v] > this->d[u] + w))
            {
                this->d[v] = this->d[u] + w;
                continue;
            }
        }
    }
}



#endif