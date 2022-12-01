#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>
#include <queue>
#include <assert.h>
#include <GLException.h>
template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
    public:
        BellmanFordShortestPaths(const TGraph *graph, int source);
        ~BellmanFordShortestPaths(){};
};

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    try{
    int u, v;
    typename TGraph::value_type w;
    std::queue<int> q;
    auto vertices = graph->GetVertices();
    int p_n = vertices.size();
    for (auto point : vertices)
        {
            this->vis[point] = false;
            this->reach[point] = false;//not in the queue
            this->prev[point] = 0;
            this->SPFA_cnt[point] = 0;
        }
    q.push(source);
    this->SPFA_cnt[source]++;
    this->d[source] = typename TGraph::value_type();
    this->vis[source] = true;
    this->reach[source] = true;
    while(q.size()) 
    {
        u = q.front();
        q.pop();
        this->reach[u] = false;
        auto edges = graph->GetOutgoingEdges(u);
        for (auto e : edges)
        {
            v = e.GetDestination();
            w = e.GetWeight();
            if(this->vis[v] == false || (this->d[v] > this->d[u] + w))
            {
                this->vis[v] = true;
                this->d[v] = this->d[u] + w;
                this->prev[v] = u;
                if(this->reach[v] == false)
                {
                    this->SPFA_cnt[v]++;
                    q.push(v);
                    this->reach[v] = true;
                    if(this->SPFA_cnt[v] >= p_n)
                        throw NegativeCycleException("Bellman-Ford");
                }
            }
        }
    }
    }
    catch(NegativeCycleException err)
    {
        std::cout << err.GetMessage();
    }
}

#endif