#include <DataStructures/WeightedEdge.h>
#include <DataStructures/Edge.h>

WeightedEdge::WeightedEdge(int x, int y, int weight):Edge(x,y),w(weight){}


WeightedEdge::~WeightedEdge()
{}

int WeightedEdge::GetSource() const{
    return this->u;
}

int WeightedEdge::GetDestination() const{
    return this->v;
}

int WeightedEdge::GetWeight() const
{
    return this->w;
}
