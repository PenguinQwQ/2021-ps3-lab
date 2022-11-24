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
    for (auto i : vertices)
        for (auto j : vertices)
            {
                this->transport[i][j] = -1;
                if(graph->ContainsEdge(i, j))
                {
                    this->transport[i][j] = i;
                    this->connect[i][j] = true;
                    this->dis[i][j] = graph->GetWeight(i,j);
                    continue;
                }
                this->connect[i][j] = false;
            }
    for (auto k : vertices)
        for (auto u : vertices)
            for (auto v : vertices)
            {
                if((this->connect[u][k] == false) || (this->connect[k][v] == false)) continue;
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
