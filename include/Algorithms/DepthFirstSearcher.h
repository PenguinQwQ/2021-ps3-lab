#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <stack>
#include <set>

template <typename TGraph>
class DepthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action)
{
//Here we store the traveled points by stack!
std::set<int> vis;
std::stack<int> stk;
  if(graph->ContainsVertex(start) == false)
    return;

stk.push(start);
vis.emplace(start);
while(!stk.empty())
{
  int u = stk.top();
  stk.pop();
  action(u);
  for (int v : graph->GetNeighbors(u))
  {
    if(vis.find(v) == vis.end()) 
    {
      vis.emplace(v);
      stk.push(v);
    }
  }
}
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate)
{
  std::set<int> vis;
  std::stack<int> stk;
  if(graph->ContainsVertex(start) == false)
      return std::nullopt;
  stk.push(start);
  vis.emplace(start);
  while(!stk.empty())
  {
    int u = stk.top();
    stk.pop();
    if(predicate(u)) return u;
    for (int v : graph->GetNeighbors(u)){
      if(vis.find(v) == vis.end())
      {
          stk.push(v);
          vis.emplace(v);
      }
    }
  }
  return std::nullopt;
}
#endif
