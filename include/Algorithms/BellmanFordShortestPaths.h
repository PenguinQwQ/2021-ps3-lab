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
        for (auto u : vertices)
        {
        for (auto e : graph->OutEdges[u])
            {
                v = e.GetDestination();
                typename TGraph::value_type w = e.GetWeight();
                printf("%d->%d with weight %d \n", u, v, w);
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

    for (auto p : vertices)
        printf("d[%d]=%d\n", p, this->d[p]);

}
#endif