#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>

const int M = 2000;

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
  std::map<int, int> NodeMap;
  std::map<int, int> NodeVal;
  typename TGraph::value_type dis[M][M];
  bool connect[M][M];
  int transport[M][M];
};

template <typename TGraph>
bool MultiSourceShortestPaths<TGraph>::HasPathOf(int source, int destination) const
{
  if(this->connect[*NodeMap.find(source)][*NodeMap.find(destination)]) return true;
  else return false;
}

template <typename TGraph>
std::optional<typename TGraph::value_type> MultiSourceShortestPaths<TGraph>::TryGetDistanceOf(int source, int destination) const
{
  if(this->connect[*NodeMap.find(source)][*NodeMap.find(destination)]) return this->dis[*NodeMap.find(source)][*NodeMap.find(destination)];
  else return std::nullopt;
}


static std::vector<int> Path;
static int Mid[M][M];
static std::map<int, int> nodeval;

void GetMid(int u, int v)
{
    if(Mid[u][v] != -1) 
      {
        GetMid(u, Mid[u][v]);
        GetMid(Mid[u][v], v);
      }
    else
      Path.push_back(nodeval[v]);
}

template <typename TGraph>
std::optional<std::vector<int>> MultiSourceShortestPaths<TGraph>::TryGetShortestPathOf(int source, int destination) const
{
    Path.clear();
    nodeval.clear();
    nodeval = this->NodeVal;
    if(this->connect[*NodeMap.find(source)][*NodeMap.find(destination)] == false) return std::nullopt;
    for (int i = 0 ; i <= M - 1 ; i++)
      for (int j = 0 ; j <= M - 1 ; j++)
        Mid[i][j] = this->transport[i][j];

    Path.push_back(NodeVal[source]);
    GetMid(source, destination);
    return Path;
}
#endif
