#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <utility>
#include <string>

template<class T, class U>
std::pair<T, U> operator < (const std::pair<T, U>& x, const std::pair<T, U>& y)
{
    return x.second < y.second;
}

template <class T2>
class WeightedGraph : public Graph{
 public:
    typedef T2 value_type;
 public:
  WeightedGraph();
  ~WeightedGraph();
 public:
  virtual bool AddEdge(int vertex1, int vertex2, T2 weight);
 public:
  T2 GetWeight(int vertex1, int vertex2) const;
  std::vector<WeightedEdge<T2>> GetEdges() const;
  std::vector<WeightedEdge<T2>> GetIncomingEdges(int vertex) const;
  std::vector<WeightedEdge<T2>> GetOutgoingEdges(int vertex) const;
 public:
   std::map<std::pair<int, int>, T2> G;
};
template <class T2>
WeightedGraph<T2>::WeightedGraph():Graph()
{ 
//    static_assert(std::is_same<std::char_traits, T2>::value != true, "TValue requires operator+");
//    static_assert(std::is_same<std::string, T2>::value != true, "TValue requires operator+");
//    static_assert(std::is_same<T2, char>::value != true, "TValue requires operator+");
//    static_assert(std::is_arithmetic<T2>::value == true, "TValue requires operator+");
//    static_assert(std::is_constructible<T2>::value == true, "TValue requires default constructor");
    this->G.clear();}
//Destructor
template <class T2>
WeightedGraph<T2>::~WeightedGraph()
{ this->G.clear();}

template <class T2>
bool WeightedGraph<T2>::AddEdge(int vertex1, int vertex2, T2 weight)
{
    if(Graph::AddEdge(vertex1, vertex2) == false)
        return false;
    G[std::pair(vertex1, vertex2)] = weight;
    return true;
}
template <class T2>
T2 WeightedGraph<T2>::GetWeight(int vertex1, int vertex2) const
{
    if(Graph::ContainsEdge(vertex1, vertex2)) 
        return G.at(std::pair<int, int>(vertex1, vertex2));
    else
        return 0;
}
template <class T2>
std::vector<WeightedEdge<T2>> WeightedGraph<T2>::GetIncomingEdges(int vertex) const
{

    auto e = Graph::GetIncomingEdges(vertex);
    std::vector<WeightedEdge<T2>> ans;
    ans.clear();
    if(e.size() == 0)
        return ans;
    for (auto it = e.begin() ; it != e.end() ; it++)
        {
            int x = it->GetSource(), y = it->GetDestination();
            ans.push_back(WeightedEdge(x, y, G.at(std::pair<int, int>(x, y))));
        }
    return ans;
}
template <class T2>
std::vector<WeightedEdge<T2>> WeightedGraph<T2>::GetOutgoingEdges(int vertex) const
{
    auto vec = Graph::GetOutgoingEdges(vertex);
    std::vector<WeightedEdge<T2>> ans;
    ans.clear();
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        {
            int x = it->GetSource(), y = it->GetDestination();
            ans.push_back(WeightedEdge(x, y, G.at(std::pair<int, int>(x, y))));
        }
    return ans;
}

template <class T2>
std::vector<WeightedEdge<T2>> WeightedGraph<T2>::GetEdges() const
{
    auto vec = Graph::GetEdges();
    std::vector<WeightedEdge<T2>> ans;
    ans.clear();
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        {
            int x = it->GetSource(), y = it->GetDestination();
            ans.push_back(WeightedEdge(x, y, G.at(std::pair<int, int>(x, y))));
        }
    return ans;
}


#endif