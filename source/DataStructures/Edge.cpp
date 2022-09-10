#include <DataStructures/Edge.h>
Edge::Edge(int x, int y)
{
    this->u = x;
    this->v = y;
}
Edge::~Edge()
{}
int Edge::GetSource() const
{
    return this->u;
}
int Edge::GetDestination() const
{
    return this->v;
}
