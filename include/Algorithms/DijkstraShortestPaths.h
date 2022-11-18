#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>
#include <assert.h>

template <typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph>{
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
 public:
  DijkstraShortestPaths(const TGraph *graph, int source);
  ~DijkstraShortestPaths(){};
};

template <typename TGraph>
DijkstraShortestPaths<TGraph>::DijkstraShortestPaths(const TGraph *graph, int source)
{
    auto vec2 = graph->GetVertices();
    for (auto it : vec2)
    {
        this->reach[it] = false;
        this->vis[it] = false;
        this->prev[it] = 0;
    }
    this->reach[source] = true;
    this->d[source] = typename TGraph::value_type();
    this->pq.push(std::make_pair(this->d[source], source));
    while (this->pq.size() > 0)
    {
        int u = this->pq.top().second;
        typename TGraph::value_type dis = this->pq.top().first;
        this->pq.pop();
        if(this->vis[u]) continue;
        this->vis[u] = true;
        auto vec = graph->GetOutgoingEdges(u);
        for (auto it : vec)
        {
            typename TGraph::value_type w = it.GetWeight();
            int v = it.GetDestination();
            if(this->reach[v] == false) //Haven't reached v yet
            { 
                this->reach[v] = true;
                this->d[v] = dis + w;
                this->pq.push(std::make_pair(this->d[v], v));
                this->prev[v] = u;
            }
            else
            {
                if(this->d[v] > dis + w)
                {
                this->d[v] = dis + w;
                this->pq.push(std::make_pair(this->d[v], v));
                this->prev[v] = u; 
                }
            }
        }
    }
}
#endif
