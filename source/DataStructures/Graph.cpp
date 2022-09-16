#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
//Constructor
Graph::Graph()
{
    this->Edges.clear();
    this->vertexs.clear();
    //初始化
}
//Destructor
Graph::~Graph()
{
    this->Edges.clear();
    this->vertexs.clear();
}
bool Graph::AddVertex(int vertex)
{
    if(vertexs.find(vertex) != vertexs.end())
        return false;
    //否则，代表可以加点。
    vertexs.insert(vertex);
    Edges[vertex].clear();

    return true;
}

bool Graph::RemoveVertex(int vertex)
{
    if(vertexs.find(vertex) == vertexs.end())
        return false;//查找不到，不能删除
    vertexs.erase(vertex);
    return true;
}


bool Graph::AddEdge(int vertex1, int vertex2)
{
    if(vertexs.find(vertex1) == vertexs.end()) return false;
    if(vertexs.find(vertex2) == vertexs.end()) return false;
    Edge e(vertex1, vertex2);
    if(Edges.find(vertex1) == Edges.end())
    {
        std::vector<Edge> tmp;
        tmp.push_back(e);
        Edges[vertex1] = tmp;
    }
    else
    {
        for (auto v : Edges[vertex1])
        {
            if(v.GetDestination() == vertex2)
                return false;
        }
        Edges[vertex1].push_back(e);
    }
    return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    if(vertexs.find(vertex1) == vertexs.end()) return false;
    if(vertexs.find(vertex2) == vertexs.end()) return false;
    Edge e(vertex1, vertex2);
    if(Edges.find(vertex1) == Edges.end())
    {
        return false;
    }
    else
    {
        for (auto it = Edges[vertex1].begin() ; it != Edges[vertex1].end() ; it++)
            {
                if(it->GetDestination() == vertex2)
                    {
                        Edges[vertex1].erase(it);
                        return true;
                    }
            }
    }
    return false;
}

int Graph::CountVertices() const
{
    return vertexs.size();
}
int Graph::CountEdges() const
{
    int cnt = 0;
    for (auto it = vertexs.begin() ; it != vertexs.end() ; it++)
            cnt += Edges.at(*it).size();
    return cnt;
}
bool Graph::ContainsVertex(int vertex) const
{
    if(vertexs.find(vertex) != vertexs.end())
        return true;
    else  
        return false;
}
bool Graph::ContainsEdge(int vertex1, int vertex2) const
{
    if(vertexs.find(vertex1) == vertexs.end()) return false;
    if(vertexs.find(vertex2) == vertexs.end()) return false;
    for (auto it = Edges.at(vertex1).begin() ; it != Edges.at(vertex1).end() ; it++)
        {
            if(it->GetDestination() == vertex2)
                return true;
        }
    return false;
}
std::vector<int> Graph::GetVertices() const
{
    std::vector<int> t;
    t.clear();
    t.assign(vertexs.begin(), vertexs.end());
    return t;
}
std::vector<Edge> Graph::GetEdges() const
{
    std::vector<Edge> t;
    t.clear();
    for (auto it = vertexs.begin() ; it != vertexs.end() ; it++)
    {
        t.insert(t.end(), Edges.at(*it).begin(), Edges.at(*it).end());
    }
    return t;
}
std::vector<Edge> Graph::GetIncomingEdges(int vertex) const
{
    std::vector<Edge> vec;
    vec.clear();
    if(vertexs.find(vertex) == vertexs.end())
        return vec;
    for (auto it = Edges.begin() ; it != Edges.end() ; it++)
    {
        auto p = it->second;
        for (auto i : p)
        {
            if(i.GetDestination() == vertex)
                vec.push_back(i);
        }
    }
    return vec;
}
std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const
{
    std::vector<Edge> vec;
    vec.clear();
    if(vertexs.find(vertex) == vertexs.end()) 
        return vec;
    return Edges.at(vertex);
}
int Graph::GetDegree(int vertex) const
{
    if(vertexs.find(vertex) == vertexs.end())
        return 0;
    return Edges.at(vertex).size();
}
std::vector<int> Graph::GetNeighbors(int vertex) const
{
    std::vector<int> vec;
    vec.clear();
    if(vertexs.find(vertex) == vertexs.end())
        return vec;
    for (auto it = Edges.at(vertex).begin(); it != Edges.at(vertex).end() ; it++)
        {
            vec.push_back(it->GetDestination());
        }
    return vec;
}