#include <DataStructures/WeightedGraph.h>
#include <utility>
#include <DataStructures/WeightedEdge.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
//Constructor
WeightedGraph::WeightedGraph():Graph()
{ this->G.clear();}
//Destructor
WeightedGraph::~WeightedGraph():~Graph()
{ this->G.clear();}
bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight)
{
    if(Graph::AddEdge(vertex1, vertex2) == false)
        return false;
    G[make_pair(vertex1, vertex2)] = weight;
    return true;
}
int WeightedGraph::GetWeight(int vertex1, int vertex2) const
{
    if(Graph::ContainsEdge(vertex1, vertex2)) 
        return G[make_pair(vertex1, vertex2)];
    else
        return 0;
}
std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const
{
    auto e = Graph::GetIncomingEdges(vertex);
    std::vector<WeightedEdge> ans;
    ans.clear();
    for (auto it = e.begin() ; it != e.end() ; it++)
        {
            ans.push_back(WeightedEdge((*it).GetSource(), (*it).GetDestination(), G[make_pair((*it).GetSource(), (*it).GetDestination())]));
        }
    return ans;
}
std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const
{
    auto vec = Graph::GetOutgoingEdges(vertex);
    std::vector<WeightedEdge> ans;
    ans.clear();
    for (auto it = e.begin() ; it != e.end() ; it++)
        {
            ans.push_back(WeightedEdge((*it).GetSource(), (*it).GetDestination(), G[make_pair((*it).GetSource(), (*it).GetDestination())]));
        }
    return ans;
}