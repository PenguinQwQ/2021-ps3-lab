#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H
#include <DataStructures/Edge.h>
class WeightedEdge : public Edge{
  public:
   WeightedEdge(int source, int destination, int weight);
   ~WeightedEdge();
   bool operator ==(const WeightedEdge& a)
   {
      return (this->GetSource() == a.GetSource()) && (this->GetDestination() == a.GetDestination()) && (this->GetWeight() == a.GetWeight());
   }
   bool operator ==(WeightedEdge& a)
   {
      return (this->GetSource() == a.GetSource()) && (this->GetDestination() == a.GetDestination()) && (this->GetWeight() == a.GetWeight());
   }
  public:
   int GetSource() const;
   int GetDestination() const;
   int GetWeight() const;
  public:
   int w;
};
#endif