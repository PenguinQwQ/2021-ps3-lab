#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <queue>
#include <set>

template <typename TGraph>
class BreadthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};

template <typename TGraph>
static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
  set<int> vis;
  queue<int> q{start};
  while(!q.empty())
  {
    int cur = q.front();
    action(cur);
    q.pop();
    vis.emplace(cur);
    for (int u : g->GetNeighbors(cur))
    {
      if(!vis.contains(u)) q.emplace(u);
    }
  }
}

template <typename TGraph>
static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
  set<int> vis;
  queue<int> q{start};
  while(!q.empty())
  {
    int cur = q.front();
    if(predicate(cur) == true) return cur;
    q.pop();
    vis.emplace(cur);
    for (int u : g->GetNeighbors(cur))
    {
      if(!vis.contains(u)) q.emplace(u);
    }
  } 
  return std::nullopt;
}



#endif