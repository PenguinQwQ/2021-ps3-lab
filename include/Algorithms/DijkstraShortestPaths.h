#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#define mp make_pair
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>


template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>{
 public:
  DijkstraShortestPaths(const TGraph<TValue> *graph, int source);
};
template <template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::DijkstraShortestPaths(const TGraph<TValue> *graph, int source)
{
    for (auto it : graph->GetVertices())
    {
        ShortestPaths::d[*it] = TValue(15000000); 
        ShortestPaths::vis[*it] = false;
        ShortestPaths::prev[*it] = 0;
    }
    d[source] = TValue();
    pq.push(mp(d[source], source));
    while (pq.size() > 0)
    {
        int u = pq.top().second;
        TValue dis = pq.top().first;
        if(vis[u]) continue;
        vis[u] = true;
        for (auto it : graph->GetOutgoingEdges(u))
        {
            TValue w = it->GetWeight();
            int v = it->GetDestination();
            if(d[v] > dis + w)
            {
                d[v] = dis + w;
                pq.push(mp(d[v], v));
                prev[v] = u;
            }
        }
    }
}

#endif
