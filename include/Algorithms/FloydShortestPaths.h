#ifndef FLOYED_SHORTEST_PATHS
#define FLOYED_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/MultiSourceShortestPaths.h>
#include <iostream>
#include <assert.h>

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph> {
   // static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
 public:
  FloydShortestPaths(const TGraph *graph);
  ~FloydShortestPaths(){};
};

template <typename TGraph>
FloydShortestPaths<TGraph>::FloydShortestPaths(const TGraph *graph)
{
    auto vertices = graph->GetVertices();
    int cnt = 0;
    for (auto i : vertices)
    {
        this->NodeMap.insert(std::pair<int, int>(i, ++cnt));//value->Node index
        this->NodeVal.insert(std::pair<int, int>(cnt, i));//Node index->value
    }
    for (auto i : vertices)
        for (auto j : vertices)
            {
                int u = *NodeMap.find(i), v = *NodeMap.find(j);
                this->transport[u][v] = -1;
                if(u == v)
                {     
                    this->transport[u][v] = i;
                    this->connect[u][v] = true;
                    this->dis[u][v] = typename TGraph::value_type();
                    continue;                    
                }
                if(graph->ContainsEdge(*NodeVal.find(u), *NodeVal.find(v)))
                {
                    this->transport[u][v] = u;
                    this->connect[u][v] = true;
                    this->dis[u][v] = graph->GetWeight(*NodeVal.find(u),*NodeVal.find(v));
                    continue;
                }
                this->connect[u][v] = false;
            }
    for (auto t : vertices)
        for (auto i : vertices)
            for (auto j: vertices)
            {
                int k = *NodeMap.find(t), u = *NodeMap.find(i), v = *NodeMap.find(j);
                if((this->connect[u][k] == false) || (this->connect[k][v] == false)) continue;
                if(k == u || u == v || v == k) continue;
                if(this->connect[u][k] && this->connect[k][v] && (this->connect[u][v] == false))
                    {
                        this->connect[u][v] = true;
                        this->dis[u][v] = this->dis[u][k] + this->dis[k][v];
                        this->transport[u][v] = k;
                        continue;
                    }
                if(this->dis[u][k] + this->dis[k][v] < this->dis[u][v])
                {
                    this->dis[u][v] = this->dis[u][k] + this->dis[k][v];
                    this->transport[u][v] = k;
                        continue;
                }
            }
}

#endif
