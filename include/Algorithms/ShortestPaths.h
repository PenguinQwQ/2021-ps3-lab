#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>
#include <DataStructures/WeightedGraph.h>
#include<type_traits>
#include <assert.h>
template <typename TGraph>
class ShortestPaths {
 public:
  ShortestPaths(){};
  ShortestPaths(const TGraph *graph, int source)
  {
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
  };
  ~ShortestPaths(){};
 public:
  bool HasPathTo(int destination) const;
  std::optional<typename TGraph::value_type> TryGetDistanceTo(int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
 public:
  bool vis[N];//queue point set 
  bool reach[N];//reached point set
  int prev[N]; 
  int dfn[N], cnt;
  typename TGraph::value_type d[N];//this is the array of dis!
  std::priority_queue <std::pair<typename TGraph::value_type, int>, std::vector<std::pair<typename TGraph::value_type, int>> , std::greater<std::pair<typename TGraph::value_type, int>> > pq;
};


template <typename TGraph>
std::optional<typename TGraph::value_type> ShortestPaths<TGraph>::TryGetDistanceTo(int destination) const
{
  if(vis[destination]) return d[destination];
  else return std::nullopt;
}
template <typename TGraph>
bool ShortestPaths<TGraph>::HasPathTo (int destination) const
{
  if(vis[destination]) return true;
  else return false;
}

template <typename TGraph>
std::optional<std::vector<int>> ShortestPaths<TGraph>::TryGetShortestPathTo(int destination) const
{
    std::vector<int> path;
    path.clear();
    if(vis[destination] == false) return std::nullopt;
    int index = destination;
    path.push_back(destination);
    while(prev[index] != 0)
    {
      path.push_back(prev[index]);
      index = prev[index];
    }
    return path;
}

#endif
