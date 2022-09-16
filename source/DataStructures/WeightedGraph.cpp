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
WeightedGraph::~WeightedGraph()
{ this->G.clear();}
bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight)
{
    if(Graph::AddEdge(vertex1, vertex2) == false)
        return false;
    G[std::pair(vertex1, vertex2)] = weight;
    return true;
}
int WeightedGraph::GetWeight(int vertex1, int vertex2) const
{
    if(Graph::ContainsEdge(vertex1, vertex2)) 
        return G.at(std::pair<int, int>(vertex1, vertex2));
    else
        return 0;
}
std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const
{

    auto e = Graph::GetIncomingEdges(vertex);
    std::vector<WeightedEdge> ans;
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
std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const
{
    auto vec = Graph::GetOutgoingEdges(vertex);
    std::vector<WeightedEdge> ans;
    ans.clear();
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        {
            int x = it->GetSource(), y = it->GetDestination();
            ans.push_back(WeightedEdge(x, y, G.at(std::pair<int, int>(x, y))));
        }
    return ans;
}

std::vector<WeightedEdge> WeightedGraph::GetEdges() const
{
    auto vec = Graph::GetEdges();
    std::vector<WeightedEdge> ans;
    ans.clear();
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        {
            int x = it->GetSource(), y = it->GetDestination();
            ans.push_back(WeightedEdge(x, y, G.at(std::pair<int, int>(x, y))));
        }
    return ans;
}