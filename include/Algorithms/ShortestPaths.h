#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <queue>
const int N = 20000;
template <typename TGraph>
class ShortestPaths {
 public:
  ShortestPaths(){};
  ShortestPaths(const TGraph *graph, int source){};
  ~ShortestPaths(){};
 public:
  bool HasPathTo(int destination) const;
  std::optional<typename TGraph::value_type> TryGetDistanceTo(int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
 public:
  bool vis[N];//reachable point set 
  int prev[N]; 
  typename TGraph::value_type INF;
  typename TGraph::value_type d[N];//this is the array of dis!
  std::priority_queue <std::pair<typename TGraph::value_type, int>, std::vector<std::pair<typename TGraph::value_type, int>> , std::greater<std::pair<typename TGraph::value_type, int>> > pq;
};


template <typename TGraph>
std::optional<typename TGraph::value_type> ShortestPaths<TGraph>::TryGetDistanceTo(int destination) const
{
  if(vis[destination]) return d[destination];
  else return std::nullopt;
}

/*
template <template<typename> class TGraph>
bool ShortestPaths<TGraph, TValue>::HasPathTo (int destination) const
{
  if(vis[destination]) return true;
  else return false;
}

template <template<typename> class TGraph, typename TValue>
std::optional<std::vector<int>> ShortestPaths<TGraph, TValue>::TryGetShortestPathTo(int destination) const
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

*/
#endif
