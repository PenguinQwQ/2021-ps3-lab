#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H
#include <DataStructures/Edge.h>
class WeightedEdge : public Edge{
  public:
   WeightedEdge(int source, int destination, int weight);
   ~WeightedEdge();
   bool operator ==(const WeightedEdge& a)
   {
      return (this->u == a.u) && (this->v == a.v) && (this->w == a.w);
   }
  public:
   int GetSource() const;
   int GetDestination() const;
   int GetWeight() const;
  private:
   int u, v, w;
};
#endif