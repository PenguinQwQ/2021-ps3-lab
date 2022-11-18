#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>
#include <queue>
#include <assert.h>
template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
    public:
        BellmanFordShortestPaths(const TGraph *graph, int source);
        ~BellmanFordShortestPaths(){};
};

/*

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    int u, v;
    typename TGraph::value_type w;
    std::vector<WeightedEdge<typename TGraph::value_type>> edges = graph->GetEdges();
    std::vector<WeightedEdge<typename TGraph::value_type>> Edges = edges;
    for (typename std::vector<WeightedEdge<typename TGraph::value_type>>::iterator it = edges.begin() ; it != edges.end() ; it++)  
    {
        u = (*it).GetSource();
        v = (*it).GetDestination();
        w = (*it).GetWeight();
        WeightedEdge<typename TGraph::value_type> tmp(v, u, w);
        Edges.push_back(tmp);   
    }
    this->cnt = 0;
    //Initialize the distance
    std::vector<int> vertices = graph->GetVertices();
    for (std::vector<int>::iterator it = vertices.begin() ; it != vertices.end() ; it++)
        this->vis[*it] = false;
    this->vis[source] = true;
    int V = vertices.size();
    for (int i = 1 ; i <= V - 1 ; i++)
    {
        for (typename std::vector<WeightedEdge<typename TGraph::value_type>>::iterator it = Edges.begin() ; it != Edges.end() ; it++)
        {
        u = (*it).GetSource();
        v = (*it).GetDestination();
        w = (*it).GetWeight(); 
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
}
*/

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    int u, v;
    typename TGraph::value_type w;
    std::queue<int> q;
    auto vertices = graph->GetVertices();
    for (auto point : vertices)
        {
            this->vis[point] = false;
            this->reach[point] = false;//not in the queue
            this->prev[point] = 0;
        }
    q.push(source);
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
                    q.push(v);
                    this->reach[v] = true;
                }
            }
        }
    }
}

#endif