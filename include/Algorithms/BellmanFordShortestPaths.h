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
    this->cnt = 0;
    auto vertices = graph->GetVertices();
    auto edges = graph->GetEdges();
    //Initialize the distance
    for (auto p : vertices)
    {
        this->vis[p] = false;
        this->reach[p] = false;
        this->dfn[p] = 0;
  //      std::cout << this->d[p] << std::endl;
    }
    this->d[source] = typename TGraph::value_type();
    this->vis[source] = true;
    this->reach[source] = true;
    this->dfn[source] = (this->cnt)++;
    int V = vertices.size();
    for (int i = 1 ; i <= V - 1 ; i++)
        for (auto e : edges)
            {
                int u = e.GetSource(), v = e.GetDestination(), undir_u = 0, undir_v = 0;
                typename TGraph::value_type w = e.GetWeight();
                printf("%d->%d with weight %d \n", u, v, w);
            if(graph->G.find(std::pair<int, int>(v, u)) != graph->G.end())        
                {
                    undir_u = v; undir_v = u;
                }
            while(1)
            {
            if(this->vis[u] == false) break;;
            if(this->vis[u] && (this->vis[v] == false))
                {
                    this->dfn[v] = (this->cnt)++;
                    this->vis[v] = true;
                    this->d[v] = this->d[u] + w;
                    this->prev[v] = u;
                    break;
                }
            if(this->vis[u] && this->vis[v] && (this->dfn[u] < this->dfn[v]) && (this->d[v] > this->d[u] + w))
            {
                this->d[v] = this->d[u] + w;
                this->prev[v] = u;
                break;
            }
            break;
            }

            if(undir_u && undir_v)
            {
            if(this->vis[v] == false) break;;
            if(this->vis[v] && (this->vis[u] == false))
                {
                    this->dfn[u] = (this->cnt)++;
                    this->vis[u] = true;
                    this->d[u] = this->d[v] + w;
                    this->prev[u] = v;
                    continue;
                }
            if(this->vis[u] && this->vis[v] && (this->dfn[v] < this->dfn[u]) && (this->d[u] > this->d[v] + w))
            {
                this->d[u] = this->d[v] + w;
                this->prev[u] = v;
                continue;
            }
            }

        }

 /*   for (auto p : vertices)
        printf("d[%d]=%d\n", p, this->d[p]);
        */

}
#endif