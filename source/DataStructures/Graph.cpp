#include <DataStructures/Graph.h>
#include <DataStructures/Edge.h>
#include <vector>
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
{}
bool Graph::AddVertex(int vertex)
{
    std::vector<int>::iterator it = find(vertexs.begin(), vertexs.end(), vertex);//在vertex点列中查找vertex
    if(it != vertexs.end())
        return false;
    //否则，代表可以加点。
    vertexs.push_back(vertex);
    return true;
}

bool Graph::RemoveVertex(int vertex)
{
    std::vector<int>::iterator it = find(vertexs.begin(), vertexs.end(), vertex);//在vertex点列中查找vertex
    if(it == vertexs.end())
        return false;//查找不到，不能删除
    //否则，代表查找到了，可以删除。
    vertexs.erase(it);
    return true;

}


bool Graph::AddEdge(int vertex1, int vertex2)
{
    std::vector<int> vec = Edges[vertex1];//所有vertex1的邻居，也即后继节点。
    std::vector<int>::iterator it = find(vec.begin(), vec.end(), vertex2);
    if(it != vec.end()) //说明在vec中有vertex2，说明该边已存在，那么就不可以重复添加！
        return false;
    Edges[vertex1].push_back(vertex2);//否则，就加边。
    return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2)
{
    std::vector<int> vec = Edges[vertex1];//所有vertex1的邻居，也即后继节点。
    std::vector<int>::iterator it = find(vec.begin(), vec.end(), vertex2);
    if(it == vec.end()) //说明在vec中无vertex2，无法删除不存在的边
        return false;
    Edges[vertex1].erase(it);//否则，就删除该节点，也就删除了边。
    return true;

}

int Graph::CountVertices() const
{
    return vertexs.size();
}
int Graph::CountEdges() const
{
    std::vector<int> vec = vertexs;
    std::map<int, std::vector<int> > S = Edges;
    int cnt = 0;
    for(std::vector<int>::iterator it = vec.begin() ; it != vec.end() ; it++)
        {
            cnt += S[*it].size();
        }
    return cnt;
}
bool Graph::ContainsVertex(int vertex) const
{
    std::vector<int> vec = vertexs;
    std::vector<int>::iterator it = find(vec.begin(), vec.end(), vertex);//在vertex点列中查找vertex
    if(it != vec.end())
        return true;
    else  
        return false;
}
bool Graph::ContainsEdge(int vertex1, int vertex2) const
{
    std::map<int, std::vector<int> > S = Edges;
    std::vector<int> vec = S[vertex1];
    std::vector<int>::iterator it = find(vec.begin(), vec.end(), vertex2);//在vertex点列中查找vertex2
    if(it != vec.end())
        return true;
    else 
        return false;
}
std::vector<int> Graph::GetVertices() const
{
    return vertexs;
}
std::vector<Edge> Graph::GetEdges() const
{
    std::vector<int> vec = vertexs;
    std::map<int, std::vector<int> > S = Edges;
    int u, v;
    std::vector<Edge> ans;
    ans.clear();
    for(std::vector<int>::iterator it = vec.begin() ; it != vec.end() ; it++) //这里遍历所有节点
        {
            for(std::vector<int>::iterator i = S[*it].begin() ; i != S[*it].end() ; i++) //这里遍历所有的边,*it->*i
                {
                    Edge t(*it, *i);
                    ans.push_back(t);
                }
        }
    return ans;
}
std::vector<Edge> Graph::GetIncomingEdges(int vertex) const
{
    std::vector<int> vec = vertexs;
    std::map<int, std::vector<int> > S = Edges;
    int u, v;
    std::vector<Edge> ans;
    ans.clear();
    for(std::vector<int>::iterator it = vec.begin() ; it != vec.end() ; it++) //这里遍历所有节点
        {
            for(std::vector<int>::iterator i = S[*it].begin() ; i != S[*it].end() ; i++) //这里遍历所有的边,*it->*i
                {
                    if(*i == vertex) //说明有一条边的终点为verteex
                    {
                       Edge t(*it, vertex);//*it->vertex
                       ans.push_back(t);
                    }
                }
        }
    return ans;
}
  std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const
  {
    std::map<int, std::vector<int> > S = Edges;
    std::vector<int> endlist = S[vertex];//vertex的所有终点
    int u, v;
    std::vector<Edge> ans;
    ans.clear();
    for(std::vector<int>::iterator it = endlist.begin() ; it != endlist.end() ; it++) //这里遍历所有节点
        {
            Edge t(vertex, *it);//vertex->*it
            ans.push_back(t);
        }
    return ans;
  }
  int Graph::GetDegree(int vertex) const
  {
        std::map<int, std::vector<int> > S = Edges;
        return S[vertex].size();
  }
  std::vector<int> Graph::GetNeighbors(int vertex) const
  {
        std::map<int, std::vector<int> > S = Edges;
        return S[vertex];
  }