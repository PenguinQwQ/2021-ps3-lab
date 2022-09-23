#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <utility>
#include <DataStructures/UndirectedGraph.h>
#include <algorithm>
#include <stdio.h>
#include <vector>

UndirectedGraph::UndirectedGraph()
{
    selfring.clear();
}
UndirectedGraph::~UndirectedGraph()
{}
bool UndirectedGraph::AddEdge(int u, int v)
{
    //First check the vertexs
    if(ContainsVertex(u) == false)
        return false;
    if(ContainsVertex(v) == false)
        return false;
    //Second check the selfring
    if(u == v)//is selfrine
        {
            if(ContainsEdge(u, v))
                return false;//already existed
            else 
                {
                    Graph::AddEdge(u, v);
                    selfring.push_back(u);
                    return true;
                }
        }
    //Third try to add the two edges
    return Graph::AddEdge(u, v) && Graph::AddEdge(v, u);//no directed!
}
bool UndirectedGraph::RemoveEdge(int u, int v)
{
    //First, check the edge does exists(At the same time check the vertexs exists)
    if((ContainsEdge(u, v) || ContainsEdge(v, u)) == false)//The Edge doesn't exists!
        return false;
    //Second, Handle the selfring situation
    if(u == v)//is selfrine
    {
        //Remove the edge, and delete the selfring pointers
        Graph::RemoveEdge(u, u);
        selfring.erase(find(selfring.begin(), selfring.end(), u));
        return true;
    }
    //Third, Remove the Edge;
    return Graph::RemoveEdge(u, v) && Graph::RemoveEdge(v, u);
}
int UndirectedGraph::CountEdges() const
{
    int cnt = Graph::CountEdges() + selfring.size();
    return cnt >> 1;
}
std::vector<Edge> UndirectedGraph::GetEdges() const
{
    std::vector<Edge> t;//ans set
    t.clear();
    for (auto it = vertexs.begin() ; it != vertexs.end() ; it++)
    {
        for (auto i = Edges.at(*it).begin() ; i != Edges.at(*it).end() ; i++)
            {
                int u = i->GetSource(), v = i->GetDestination();
                if(u <= v)
                    t.push_back((*i));
            }
    }
    return t;
}
int UndirectedGraph::GetDegree(int vertex) const
{
    //Handle the vertex is not in the graph!
    if(ContainsVertex(vertex) == false)
        {
            return 0;
        }
    int cnt = Graph::GetDegree(vertex);
    if(find(selfring.begin(), selfring.end(), vertex) != selfring.end())
        cnt++;//exists selfrine, the add degree!
    return cnt;
}