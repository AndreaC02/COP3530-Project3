#include "heap.h"
#include "series.h"

using namespace std;


Heap::Heap()
{

}    
void Heap::push(Series obj)
{
    maxHeap.push_back(obj);
    heapSort();
}
void Heap::pop()
{


}
Series Heap::top()
{
    
    return maxHeap[0];

}
void Heap::heapSort()
{

}