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
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
    public:
        BellmanFordShortestPaths(const TGraph *graph, int source);
        ~BellmanFordShortestPaths(){};
};

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    int u, v;
    typename TGraph::value_type w;
    std::vector<WeightedEdge<typename TGraph::value_type>> edges = graph->GetEdges();
    std::vector<WeightedEdge<typename TGraph::value_type>> Edges = edges;
    for (auto e : edges)  
    {
        u = e.GetSource();
        v = e.GetDestination();
        w = e.GetWeight();
        WeightedEdge<typename TGraph::value_type> tmp(v, u, w);
        Edges.push_back(tmp);   
    }

    this->cnt = 0;
    //Initialize the distance
    auto vertices = graph->GetVertices();
    for (auto p : vertices)
        this->vis[p] = false;
    this->vis[source] = true;
    int V = vertices.size();
    for (int i = 1 ; i <= V - 1 ; i++)
    {
        for (auto e : Edges)
        {
        u = e.GetSource();
        v = e.GetDestination();
        w = e.GetWeight(); 
        if(this->vis[u] == false) continue;
        if(this->vis[u] == true && this->vis[v] == false)
            {
                this->vis[v] = true;
                this->d[v] = this->d[u] + w;
                this->prev[v] = u;
                continue;
            }
        if(this->vis[u] && this->vis[v] && (this->d[u] + w < this->d[v]))
            {
            this->d[v] = this->d[u] + w;
            this->prev[v] = u;
            continue;
            }
        }
    }

/*
    this->cnt = 0;
    //Initialize the distance
    auto vertices = graph->GetVertices();
    for (auto p : vertices)
    {
        this->vis[p] = false;
        this->dfn[p] = 0;
    }
    this->d[source] = typename TGraph::value_type();
    this->vis[source] = true;
    this->dfn[source] = (this->cnt)++;
    int V = vertices.size();
    auto edges = graph->GetEdges();
    for (int i = 1 ; i <= V - 1 ; i++)
        for (auto e : edges)
            {
                int u = e.GetSource(), v = e.GetDestination(), undir = false;
                typename TGraph::value_type w = e.GetWeight();
              //  printf("%d->%d with weight %d \n", u, v, w);
            if(graph->G.find(std::pair<int, int>(v, u)) != graph->G.end())        
                    undir = true;
            while(1)
            {
              //  printf("%d->%d with weight %d \n", u, v, w);
            if(this->vis[u] == false) break;
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
            if(undir)
            {
             //   printf("%d->%d with weight %d \n", v, u, w);
            if(this->vis[v] == false) continue;
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

        */
}
#endif