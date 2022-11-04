#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>

template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>{
 public:
  DijkstraShortestPaths(const TGraph<TValue> *graph, int source);
  ~DijkstraShortestPaths(){};
};

template <template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::DijkstraShortestPaths(const TGraph<TValue> *graph, int source)

{
    this->INF = (TValue)200000;
    auto vec2 = graph->GetVertices();
    for (auto it : vec2)
    {
        this->d[it] = this->INF;
        this->vis[it] = false;
        this->prev[it] = 0;
    }
    this->d[source] = TValue();
    this->pq.push(std::make_pair(this->d[source], source));
    while (this->pq.size() > 0)
    {
        int u = this->pq.top().second;
        TValue dis = this->pq.top().first;
        this->pq.pop();
        if(this->vis[u]) continue;
        this->vis[u] = true;
        auto vec = graph->GetOutgoingEdges(u);
        for (auto it : vec)
        {
            TValue w = it.GetWeight();
            int v = it.GetDestination();
            if(this->d[v] > dis + w)
            {
                this->d[v] = dis + w;
                this->pq.push(std::make_pair(this->d[v], v));
                this->prev[v] = u;
            }
        }
    }
}
#endif
