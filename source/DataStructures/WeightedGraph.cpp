#include <DataStructures/WeightedGraph.h>
#include <DataStructures/WeightedEdge.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
//Constructor
WeightedGraph::WeightedGraph()
{
    this->Edges.clear();
    this->vertexs.clear();
    //初始化
}
//Destructor
WeightedGraph::~WeightedGraph()
{
    this->Edges.clear();
    this->vertexs.clear();
}
bool WeightedGraph::AddVertex(int vertex)
{
    auto it = find(vertexs.begin(), vertexs.end(), vertex);//在vertex点列中查找vertex
    if(it != vertexs.end())
        return false;
    //否则，代表可以加点。
    vertexs.push_back(vertex);
    return true;
}

bool WeightedGraph::RemoveVertex(int vertex)
{
    auto k = find(vertexs.begin(), vertexs.end(), vertex);//在vertex点列中查找vertex
    if(k == vertexs.end())
        return false;//查找不到，不能删除
    vertexs.erase(k);
    return true;
}


bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight)
{
    auto i1  = find(vertexs.begin(), vertexs.end(), vertex1);
    auto i2  = find(vertexs.begin(), vertexs.end(), vertex2);
    if(i1 == vertexs.end() || i2 == vertexs.end())
    {
        return false;
    }
    auto it = find(Edges[vertex1].begin(), Edges[vertex1].end(), WeightedEdge(vertex1, vertex2, weight));
    if(it != Edges[vertex1].end()) //说明在vec中有vertex2，说明该边已存在，那么就不可以重复添加！
    {   
        return false;
    }
    Edges[vertex1].push_back(WeightedEdge(vertex1, vertex2, weight));//否则，就加边。
    return true;
}

bool WeightedGraph::RemoveEdge(int vertex1, int vertex2, int weight)
{
    auto i1  = find(vertexs.begin(), vertexs.end(), vertex1);
    auto i2  = find(vertexs.begin(), vertexs.end(), vertex2);
    if(i1 == vertexs.end() || i2 == vertexs.end())
        return false;
    auto it = find(Edges[vertex1].begin(), Edges[vertex1].end(), WeightedEdge(vertex1, vertex2, weight));
    if(it == Edges[vertex1].end()) //无法删除不存在的边
        return false;
    Edges[vertex1].erase(it);//否则，就删除该边。
    return true;

}

int WeightedGraph::CountVertices() const
{
    return vertexs.size();
}
int WeightedGraph::CountEdges() const
{
    auto vec = vertexs;
    auto S = Edges;
    int cnt = 0;
    for(auto it = vec.begin() ; it != vec.end() ; it++)
        {
            cnt += S[*it].size();
        }
    return cnt;
}
bool WeightedGraph::ContainsVertex(int vertex) const
{
    auto vec = vertexs;
    auto it = find(vec.begin(), vec.end(), vertex);//在vertex点列中查找vertex
    if(it != vec.end())
        return true;
    else  
        return false;
}
bool WeightedGraph::ContainsEdge(int vertex1, int vertex2) const
{
    auto ver = vertexs;
    auto i1  = find(ver.begin(), ver.end(), vertex1);
    auto i2  = find(ver.begin(), ver.end(), vertex2);
    if(i1 == ver.end() || i2 == ver.end())
        return false;
    auto S = Edges;
    auto vec = S[vertex1];
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        {
            if((*it).GetDestination() == vertex2)
                return true;
        }
    return false;
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const
{
    auto ver = vertexs;
    auto i1  = find(ver.begin(), ver.end(), vertex1);
    auto i2  = find(ver.begin(), ver.end(), vertex2);
    if(i1 == ver.end() || i2 == ver.end())
        return false;
    auto S = Edges;
    auto vec = S[vertex1];
    for (auto it = vec.begin() ; it != vec.end() ; it++)
        {
            if((*it).GetDestination() == vertex2)
                return (*it).GetWeight();
        }
    return 0;
}

std::vector<int> WeightedGraph::GetVertices() const
{
    return vertexs;
}
std::vector<WeightedEdge> WeightedGraph::GetEdges() const
{
    auto vec = vertexs;
    auto S = Edges;
    std::vector<WeightedEdge> ans;
    ans.clear();
    for(auto it = vec.begin() ; it != vec.end() ; it++) //这里遍历所有节点
        {
            for(auto i = S[*it].begin() ; i != S[*it].end() ; i++) //这里遍历所有的边,*it->*i
                {
                    ans.push_back(*i);
                }
        }
    return ans;
}
std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const
{
    auto v = vertexs;
    auto i1  = find(v.begin(), v.end(), vertex);
    if(i1 == v.end())
        {
            std::vector<WeightedEdge> tmp;
            tmp.clear();
            return tmp;
        }

    auto vec = vertexs;
    auto S = Edges;
    std::vector<WeightedEdge> ans;
    ans.clear();
    for(auto it = vec.begin() ; it != vec.end() ; it++) //这里遍历所有节点
        {
            for(auto i = S[*it].begin() ; i != S[*it].end() ; i++) //这里遍历所有的边,*it->*i
                {
                    if((*i).GetDestination() == vertex) //说明有一条边的终点为vertex
                    {
                       ans.push_back(*i);
                    }
                }
        }
    return ans;
}
std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const
  {
    auto v = vertexs;
    auto i1  = find(v.begin(), v.end(), vertex);
    if(i1 == v.end())
        {
            std::vector<WeightedEdge> tmp;
            tmp.clear();
            return tmp;
        }
    auto S = Edges;
    auto endlist = S[vertex];//vertex的所有终点
    std::vector<WeightedEdge> ans;
    ans.clear();
    for(auto it = endlist.begin() ; it != endlist.end() ; it++) //这里遍历所有节点
        {
            if(find(v.begin(), v.end(), (*it).GetDestination()) != v.end())
            {
                ans.push_back(*it);
            }
        }
    return ans;
  }
int WeightedGraph::GetDegree(int vertex) const
  {
    auto v = vertexs;
    auto i1  = find(v.begin(), v.end(), vertex);
    if(i1 == v.end())
        return 0;
    int ans = 0;
    auto S = Edges;
    for (auto it = S[vertex].begin() ; it != S[vertex].end() ; it++)
        {
            if(find(v.begin(), v.end(), (*it).GetDestination()) != v.end())
                ans++;
        }
    return ans;
  }
std::vector<int> WeightedGraph::GetNeighbors(int vertex) const
  {
    auto v = vertexs;
    auto i1  = find(v.begin(), v.end(), vertex);
    if(i1 == v.end()) // null index
        {
            std::vector<int> tmp;
            tmp.clear();
            return tmp;
        }
    auto S = Edges;
    std::vector<int> ans;
    ans.clear();
    for (auto it = S[vertex].begin() ; it != S[vertex].end() ; it++)
        {
            if(find(v.begin(), v.end(), (*it).GetDestination()) != v.end() && find(ans.begin(), ans.end(), (*it).GetDestination()) == ans.end()) //no resideration of the same point
                ans.push_back((*it).GetDestination());
        }
    return ans;
  }