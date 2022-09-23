#include <DataStructures/WeightedEdge.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/Edge.h>
#include <utility>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
UndirectedWeightedGraph::UndirectedWeightedGraph()
{
    selfring.clear();
}
UndirectedWeightedGraph::~UndirectedWeightedGraph()
{}
bool UndirectedWeightedGraph::AddEdge(int vertex1, int vertex2, int weight)
{
    //First check the vertexs are in the graph
    if(ContainsVertex(vertex1) == false)
        return false;
    if(ContainsVertex(vertex2) == false)
        return false;
    if(ContainsEdge(vertex1, vertex2) == true)
        return false;
    //Second solve the selfring situation
    if(vertex1 == vertex2)
    {
        WeightedGraph::AddEdge(vertex1, vertex2, weight);
        selfring.push_back(vertex1);
        return true;
    }
    //Third solve the remaining situation
    return WeightedGraph::AddEdge(vertex1, vertex2, weight) && WeightedGraph::AddEdge(vertex2, vertex1, weight);
}
bool UndirectedWeightedGraph::RemoveEdge(int vertex1,int vertex2)
{
    //First, check the vertexs exists and the Edge exists
    if(ContainsEdge(vertex1, vertex2) == false)
        return false;
    //Second check the selfring
    if(vertex1 == vertex2)
    {
        WeightedGraph::RemoveEdge(vertex1, vertex2);
        selfring.erase(find(selfring.begin(), selfring.end(), vertex1));
        return true;
    }
    //Third remove the remaining contents
    return WeightedGraph::RemoveEdge(vertex1, vertex2) && WeightedGraph::RemoveEdge(vertex2, vertex1);
}
int UndirectedWeightedGraph::CountEdges() const
{
    int cnt = WeightedGraph::CountEdges() + selfring.size();
    return cnt >> 1;
}
std::vector<WeightedEdge> UndirectedWeightedGraph::GetEdges() const
{
    std::vector<WeightedEdge> t;//ans set
    t.clear();
    for (auto it = vertexs.begin() ; it != vertexs.end() ; it++)
    {
        for (auto i = Edges.at(*it).begin() ; i != Edges.at(*it).end() ; i++)
            {
                int u = i->GetSource(), v = i->GetDestination(), w = G.at(std::pair(u, v));
                if(u <= v)
                    t.push_back(WeightedEdge(u, v, w));
            }
    }
    return t;
}
int UndirectedWeightedGraph::GetDegree(int vertex) const
{
    if(ContainsVertex(vertex) == false)
        return 0;
    int cnt = WeightedGraph::GetDegree(vertex);
    if(find(selfring.begin(), selfring.end(), vertex) != selfring.end())
        cnt++;
    return cnt;
}
