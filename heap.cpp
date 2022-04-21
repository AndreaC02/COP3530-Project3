#include "heap.h"
#include "series.h"

using namespace std;


Heap::Heap()
{

}    
void Heap::push(Series obj)
{
    maxHeap.push_back(obj);
    int child = maxHeap.size() - 1;
    int parent = (child - 1) / 2;

    while (parent >= 0 && maxHeap[parent].getSimilarityRanking() < maxHeap[child].getSimilarityRanking())
    {
        swap(maxHeap[parent], maxHeap[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}
void Heap::pop()
{
    int parent = 0;
    swap(maxHeap[parent], maxHeap[maxHeap.size() - 1]);
    maxHeap.erase(arr.end() - 1);

    int leftchild = 1;
    int rightchild = 2;

    while (maxHeap[parent] < maxHeap[leftchild] || maxHeap[parent] < maxHeap[rightchild])
    {
        if (leftchild > rightchild)
        {
            swap(maxHeap[parent], maxHeap[leftchild]);
            parent = leftchild;
            leftchild = (2 * parent) + 1;
            rightchild = (2 * parent) + 2;
        }
        else
        {
            swap(maxHeap[parent], maxHeap[rightchild]);
            parent = rightchild;
            leftchild = (2 * parent) + 1;
            rightchild = (2 * parent) + 2;
        }

        if (leftchild > maxHeap.size() - 1)
        {
            leftchild = parent;
        }
        if (rightchild > maxHeap.size() - 1)
        {
            rightchild = parent;
        }
    }
    

}
Series Heap::top()
{
    
    return maxHeap[0];

}

void Heap::printSimilarities()
{
    for (int i = 0; i < maxHeap.size(); i++)
    {
        cout << maxHeap[i].getSimilarityRanking() << " " ;

    }
}
