#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>


template <typename TGraph>
class MultiSourceShortestPaths {
 public:
  MultiSourceShortestPaths(){};
  MultiSourceShortestPaths(const TGraph *graph){};
  ~MultiSourceShortestPaths();
 public:
  bool HasPathOf(int source, int destination) const;
  std::optional<typename TGraph::value_type> TryGetDistanceOf(int source, int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const;
  void GetMid(int u, int v);
 public:
  typename TGraph::value_type dis[N][N];
  bool connect[N][N];
  int transport[N][N];
  static std::vector<int> Path;
};

template <typename TGraph>
bool MultiSourceShortestPaths<TGraph>::HasPathOf(int source, int destination) const
{
  if(this->connect[source][destination]) return true;
  else return false;
}

template <typename TGraph>
std::optional<typename TGraph::value_type> MultiSourceShortestPaths<TGraph>::TryGetDistanceOf(int source, int destination) const
{
  if(this->connect[source][destination]) return dis[source][destination];
  else return std::nullopt;
}

template <typename TGraph>
void MultiSourceShortestPaths<TGraph>::GetMid(int u, int v)
{
    if(this->transport[u][v] != -1) 
      {
        Path.push_back(this->transport[u][v]);
        GetMid(this->transport[u][v], v);
      }
    else
      Path.push_back(v);
    return;
}
template <typename TGraph>
std::optional<std::vector<int>> MultiSourceShortestPaths<TGraph>::TryGetShortestPathOf(int source, int destination) const
{
    Path.clear();
    if(this->connect[source][destination] == false) return std::nullopt;
    Path.push_back(source);
    GetMid(source, destination);
    return Path;
}


#endif
