#ifndef WEIGHTEDEDGE_H
#define WEIGHTEDEDGE_H
#include <DataStructures/Edge.h>
template <class T>
class WeightedEdge : public Edge{
  public:
   WeightedEdge(int source, int destination, T weight);
   ~WeightedEdge();
   bool operator ==(const WeightedEdge& a)
   {
      return (this->GetSource() == a.GetSource()) && (this->GetDestination() == a.GetDestination());
   }
   bool operator ==(WeightedEdge& a)
   {
      return (this->GetSource() == a.GetSource()) && (this->GetDestination() == a.GetDestination());
   }
  public:
   T GetWeight() const;
  public:
   T w;
};

template <class T>
WeightedEdge<T>::WeightedEdge(int x, int y, T weight):Edge(x,y),w(weight){}

template <class T>
WeightedEdge<T>::~WeightedEdge()
{}
template <class T>
T WeightedEdge<T>::GetWeight() const
{
    return this->w;
}


#endif