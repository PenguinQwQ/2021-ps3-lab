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
    this->INF = TValue();
    std::cout << "Tag One" << std::endl;
    for (auto it : graph->GetEdges())
    {
        this->INF = this->INF + it.GetWeight();
    }
    std::cout << "Tag Two" << std::endl;
    for (auto it : graph->GetVertices())
    {
        this->d[it] = this->INF;
        this->vis[it] = false;
        this->prev[it] = 0;
    }
    std::cout << "Tag Three" << std::endl;
    this->d[source] = TValue();
    this->pq.push(std::make_pair(this->d[source], source));
    std::cout << "Tag Four" << std::endl;
    while (this->pq.size() > 0)
    {
        std::cout << "Tag Five" << std::endl;
        int u = this->pq.top().second;
        TValue dis = this->pq.top().first;
        pq.pop();
        if(this->vis[u]) continue;
        this->vis[u] = true;
        for (auto it : graph->GetOutgoingEdges(u))
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

    for (auto it : graph->GetVertices())
    {
        std::cout << this->d[it] << std::endl;
    }

}
#endif
