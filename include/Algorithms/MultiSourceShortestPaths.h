#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>
#include <map>

const int M = 8000;

template <typename TGraph>
class MultiSourceShortestPaths {
 public:
  std::map<int, int> NodeMap;
  std::map<int, int> NodeVal;
  typename TGraph::value_type dis[M][M];
  bool connect[M][M];
  int transport[M][M];
 public:
  MultiSourceShortestPaths(){};
  MultiSourceShortestPaths(const TGraph *graph)
  {
    auto p = graph->GetVertices();
    int cnt = 0;
    for (auto i : p)
      {
       
        NodeMap.insert(std::pair<int, int>(i, ++cnt));
        NodeVal.insert(std::pair<int, int>(cnt, i));
         printf("%d->%d", cnt, i);
      }
    printf("NodeMap size is %d\n", NodeMap.size());
  };
  ~MultiSourceShortestPaths(){};
 public:
  bool HasPathOf(int source, int destination) const;
  std::optional<typename TGraph::value_type> TryGetDistanceOf(int source, int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const;
};

template <typename TGraph>
bool MultiSourceShortestPaths<TGraph>::HasPathOf(int source, int destination) const
{
  if(this->NodeMap.find(source) == this->NodeMap.end()) return false;
  if(this->NodeMap.find(destination) == this->NodeMap.end()) return false;
  if(this->connect[this->NodeMap.at(source)][this->NodeMap.at(destination)]) return true;
  else return false;
}

template <typename TGraph>
std::optional<typename TGraph::value_type> MultiSourceShortestPaths<TGraph>::TryGetDistanceOf(int source, int destination) const
{
  if(this->NodeMap.find(source) == this->NodeMap.end()) return std::nullopt;
  if(this->NodeMap.find(destination) == this->NodeMap.end()) return std::nullopt;
  if(this->connect[this->NodeMap.at(source)][this->NodeMap.at(destination)]) return this->dis[NodeMap.at(source)][NodeMap.at(destination)];
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
      Path.push_back(nodeval.at(v));
}

template <typename TGraph>
std::optional<std::vector<int>> MultiSourceShortestPaths<TGraph>::TryGetShortestPathOf(int source, int destination) const
{
  if(this->NodeMap.find(source) == this->NodeMap.end()) return std::nullopt;
  if(this->NodeMap.find(destination) == this->NodeMap.end()) return std::nullopt;
    Path.clear();
    nodeval.clear();
    nodeval = this->NodeVal;
    if(this->connect[this->NodeMap.at(source)][this->NodeMap.at(destination)] == false) return std::nullopt;
    for (int i = 0 ; i <= M - 1 ; i++)
      for (int j = 0 ; j <= M - 1 ; j++)
        Mid[i][j] = this->transport[i][j];

    Path.push_back(source);
    GetMid(this->NodeMap.at(source), this->NodeMap.at(destination));
    return Path;
}
#endif
