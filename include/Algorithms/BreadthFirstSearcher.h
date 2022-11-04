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
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};

template <typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
  std::set<int> vis;
  std::queue<int> q;
  if(graph->ContainsVertex(start) == false)
    return;

  q.push(start);
  vis.emplace(start);
  while(!q.empty())
  {
    int cur = q.front();
    action(cur);
    q.pop();
    for (int u : graph->GetNeighbors(cur))
    {
      if(vis.find(u) == vis.end()) 
      {
        q.emplace(u);
        vis.emplace(u);
      }
    }
  }
}

template <typename TGraph>
std::optional<int> BreadthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
  std::set<int> vis;
  std::queue<int> q;

  if(graph->ContainsVertex(start) == false)
      return std::nullopt;
  q.push(start);
  vis.emplace(start);
  while(!q.empty())
  {
    int cur = q.front();
    if(predicate(cur) == true) return cur;
    q.pop();
    for (int u : graph -> GetNeighbors(cur))
    {
      if(vis.find(u) == vis.end()) 
      { 
        q.emplace(u);
        vis.emplace(u);
      }
    }
  } 
  return std::nullopt;
}



#endif