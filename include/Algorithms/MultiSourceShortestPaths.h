#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>

const int M = 10000;

template <typename TGraph>
class MultiSourceShortestPaths {
 public:
  MultiSourceShortestPaths(){};
  MultiSourceShortestPaths(const TGraph *graph){};
  ~MultiSourceShortestPaths(){};
 public:
  bool HasPathOf(int source, int destination) const;
  std::optional<typename TGraph::value_type> TryGetDistanceOf(int source, int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const;
 public:
  typename TGraph::value_type dis[M][M];
  bool connect[M][M];
  int transport[M][M];
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
  if(this->connect[source][destination]) return this->dis[source][destination];
  else return std::nullopt;
}


static std::vector<int> Path;
static int Mid[M][M];

void GetMid(int u, int v)
{
    if(Mid[u][v] != -1) 
      {
        GetMid(u, Mid[u][v]);
        GetMid(Mid[u][v], v);
      }
    else
      Path.push_back(v);
}

template <typename TGraph>
std::optional<std::vector<int>> MultiSourceShortestPaths<TGraph>::TryGetShortestPathOf(int source, int destination) const
{
    Path.clear();
    if(this->connect[source][destination] == false) return std::nullopt;
    for (int i = 0 ; i <= M - 1 ; i++)
      for (int j = 0 ; j <= M - 1 ; j++)
        Mid[i][j] = this->transport[i][j];

    Path.push_back(source);
    GetMid(source, destination);
    return Path;
}
#endif
