#ifndef BELLMANFORD_SHORTEST_PATHS
#define BELLMANFORD_SHORTEST_PATHS
#include <vector>
#include <optional>
#include <utility>
#include <Algorithms/ShortestPaths.h>
#include <iostream>
#include <assert.h>
template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
    public:
        BellmanFordShortestPaths(const TGraph *graph, int source);
        ~BellmanFordShortestPaths(){};
};
/*

void SPFA()
{
	memset(d,0x7f,sizeof(d));
	memset(book,0,sizeof(book));
	d[s]=0;
	q[++r]=s;
	book[s]=1;
	while(l!=r)
		{
			int k=q[(++l)%5000];
			for(int i=head[k];i;i=e[i].next)
				{
					int v=e[i].to,w=e[i].val;
					if(d[v]>d[k]+w)
						{
							d[v]=d[k]+w;
							//pre[v]=k;记录前驱 
							if(!book[v])
								q[(++r)%5000]=v;
						}
				}
		}
}


*/

template <typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source)
{
    int l = 0, r = 0, u, v;
    static_assert(std::is_default_constructible<typename TGraph::value_type>::value == true, "TValue requires default constructor");
    auto vertices = graph->GetVertices(); 
    this->d[source] = typename TGraph::value_type();
    for (auto it : vertices) this->vis[it] = false;
    this->vis[source] = true;
    this->q[++r] = source;
    while(l != r)
    {
        int k = this->q[(++l) % 10000];
        for (auto e : graph->GetOutgoingEdges(k))
        {
            v = e.GetDestination();
            u = e.GetSource();
            typename TGraph::value_type w = e.GetWeight();
            if(this->vis[u] == false) continue;
            if(this->vis[u] && this->vis[v] == false)
                {
                    this->vis[v] = true;
                    this->d[v] = this->d[u] + w;
                    this->prev[v] = u;
                    this->q[(++r) % 10000] = v;
                    continue;
                }
            if(this->vis[u] && this->vis[v] && (this->d[v] > this->d[u] + w))
                {
                    this->d[v] = this->d[u] + w;
                    this->prev[v] = u;
                    this->q[(++r) % 10000] = v;
                    continue;
                }
        }
    }
  
  
  /*
    auto vertices = graph->GetVertices();
    auto edges = graph->GetEdges();
    //Initialize the distance
    for (auto p : vertices)
    {
        this->vis[p] = false;
        this->reach[p] = false;
  //      std::cout << this->d[p] << std::endl;
    }
    this->d[source] = typename TGraph::value_type();
    this->vis[source] = true;
    int V = vertices.size(), u, v;

    for (int i = 1 ; i <= V - 1 ; i++)
    {
        for (auto e : edges)
            {
                u = e.GetSource();
                v = e.GetDestination();
                typename TGraph::value_type w = e.GetWeight();
            if(this->vis[u] == false) continue;
            if(this->vis[u] && (this->vis[v] == false))
                {
                    this->vis[v] = true;
                    this->d[v] = this->d[u] + w;
                    this->prev[v] = u;
                    continue;
                }
            if(this->vis[u] && this->vis[v] && (this->d[v] > this->d[u] + w))
            {
                this->d[v] = this->d[u] + w;
                this->prev[v] = u;
                continue;
            }
            }
        }
    }

    */
}
#endif