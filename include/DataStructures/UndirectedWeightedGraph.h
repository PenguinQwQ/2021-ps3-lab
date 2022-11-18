#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H
#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <DataStructures/WeightedGraph.h>
#include <algorithm>
#include <utility>
#include <vector>
template <class T2>
class UndirectedWeightedGraph : public WeightedGraph<T2> {
    public:
    UndirectedWeightedGraph();
    ~UndirectedWeightedGraph();
    bool AddEdge(int vertex1, int vertex2, T2 weight) override;
    bool RemoveEdge(int vertex1, int vertex2) override;
    int CountEdges() const override;
    std::vector<WeightedEdge<T2>> GetEdges() const;
    int GetDegree(int vertex) const override;
    public:
    std::vector<int> selfring;
};

template <class T2>
UndirectedWeightedGraph<T2>::UndirectedWeightedGraph()
{
    selfring.clear();
}

template <class T2>
UndirectedWeightedGraph<T2>::~UndirectedWeightedGraph()
{}

template <class T2>
bool UndirectedWeightedGraph<T2>::AddEdge(int vertex1, int vertex2, T2 weight)
{
    //First check the vertexs are in the graph
    if(WeightedGraph<T2>::ContainsVertex(vertex1) == false)
        return false;
    if(WeightedGraph<T2>::ContainsVertex(vertex2) == false)
        return false;
    if(WeightedGraph<T2>::ContainsEdge(vertex1, vertex2) == true)
        return false;
    //Second solve the selfring situation
    if(vertex1 == vertex2)
    {
        WeightedGraph<T2>::AddEdge(vertex1, vertex2, weight);
        selfring.push_back(vertex1);
        return true;
    }
    //Third solve the remaining situation
    return WeightedGraph<T2>::AddEdge(vertex1, vertex2, weight) && WeightedGraph<T2>::AddEdge(vertex2, vertex1, weight);
}
template <class T2>
bool UndirectedWeightedGraph<T2>::RemoveEdge(int vertex1, int vertex2)
{
    //First, check the vertexs exists and the Edge exists
    if(WeightedGraph<T2>::ContainsEdge(vertex1, vertex2) == false)
        return false;
    //Second check the selfring
    if(vertex1 == vertex2)
    {
        WeightedGraph<T2>::RemoveEdge(vertex1, vertex2);
        for (auto it = selfring.begin() ; it != selfring.end() ; it++)
        {
            if((*it) == vertex1)
            {
                this->selfring.erase(it);
                break;    
            }
        }
        return true;
    }
    //Third remove the remaining contents
    return WeightedGraph<T2>::RemoveEdge(vertex1, vertex2) && WeightedGraph<T2>::RemoveEdge(vertex2, vertex1);
}
template <class T2>
int UndirectedWeightedGraph<T2>::CountEdges() const
{
    int cnt = WeightedGraph<T2>::CountEdges() + selfring.size();
    return cnt >> 1;
}
template <class T2>
std::vector<WeightedEdge<T2>> UndirectedWeightedGraph<T2>::GetEdges() const
{
    std::map<int, std::vector<Edge> > vec = Graph::Edges;

    std::vector<WeightedEdge<T2>> t;//ans set
    t.clear();
    for (auto it = Graph::vertexs.begin() ; it != Graph::vertexs.end() ; it++)
    {
        for (auto i = vec.find(*it)->second.begin(); i != vec.find(*it)->second.end() ; i++)
            {
                int u = i->GetSource(), v = i->GetDestination(), w = WeightedGraph<T2>::G.at(std::pair(u, v));
                if(u <= v)
                    t.push_back(WeightedEdge<T2>(u, v, w));
            }
    }
    return t;
}
template <class T2>
int UndirectedWeightedGraph<T2>::GetDegree(int vertex) const
{
    if(WeightedGraph<T2>::ContainsVertex(vertex) == false)
        return 0;
    int cnt = WeightedGraph<T2>::GetDegree(vertex);

 //   if(UndirectedWeightedGraph<T2>::find(this->selfring.begin(), this->selfring.end(), vertex) != this->selfring.end())
    for (auto it = selfring.begin() ; it != selfring.end() ; it++)
    {
        if((*it) == vertex)
        {
            cnt++;
            break;    
        }
    }
    return cnt;
}


















#endif