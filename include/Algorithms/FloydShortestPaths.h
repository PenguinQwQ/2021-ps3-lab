#ifndef FLOYED_SHORTEST_PATHS
#define FLOYED_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/MultiSourceShortestPaths.h>
#include <iostream>
#include <assert.h>
#include <Exceptions/GLException.h>
#include <exception>

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
    auto p = graph->GetVertices();
    int cnt = 0;
    for (auto i : p)
      {
        this->NodeMap.insert(std::pair<int, int>(i, ++cnt));
        this->NodeVal.insert(std::pair<int, int>(cnt, i));
      }
    for (auto i : p)
        for (auto j : p)
            {
                int u = this->NodeMap[i], v = this->NodeMap[j];
                this->transport[u][v] = -1;
                if(u == v)
                {     
                    this->connect[u][v] = true;
                    this->dis[u][v] = typename TGraph::value_type();
                    continue;                    
                }
                if(graph->ContainsEdge(i, j))
                {
                    this->connect[u][v] = true;
                    this->dis[u][v] = graph->GetWeight(i, j);
                    continue;
                }
                this->connect[u][v] = false;
            }
 
    for (int k = 1 ; k <= cnt ; k++)
        for (int u = 1 ; u <= cnt ; u++)
            for (int v = 1 ; v <= cnt ; v++)
                {
                    if(this->connect[u][k] && this->connect[k][v] && (this->connect[u][v] == false))
                        {
                            this->connect[u][v] = true;
                            this->dis[u][v] = this->dis[u][k] + this->dis[k][v];
                            this->transport[u][v] = k;
                            continue;
                        }
                    if(this->connect[u][k] && this->connect[k][v] && this->connect[u][v] && (this->dis[u][v] > this->dis[u][k] + this->dis[k][v]))
                        {
                            this->dis[u][v] = this->dis[u][k] + this->dis[k][v];
                            this->transport[u][v] = k;
                            continue;                           
                        }
                }
    
    try{
        for (int i = 1 ; i <= cnt ; i++)
            if(this->dis[i][i] < typename TGraph::value_type())
            {
                /*
                const std::string str = "Floyd";
                throw GLException(str);
                */
               throw "Floyd";
            }
    }
    catch(GLException err)
    {
        std::cout << err.GetMessage();
    }
    catch(const char* str)
    {
        std::cout << str;
    }
    /*
    for (auto t : p)
        for (auto i : p)
            for (auto j: p)
            {
                int k = this->NodeMap[t], u = this->NodeMap[i], v = this->NodeMap[j];
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
            */
}

#endif
