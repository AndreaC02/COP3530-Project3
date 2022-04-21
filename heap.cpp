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
    maxHeap.erase(maxHeap.end() - 1);

    int leftchild = 1;
    int rightchild = 2;

    while (maxHeap[parent].getSimilarityRanking() < maxHeap[leftchild].getSimilarityRanking() || maxHeap[parent].getSimilarityRanking() < maxHeap[rightchild].getSimilarityRanking())
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

void Heap::setSimilarityRanking(Series curr)
{
    int similarityRanking = 0;

    // genre
    for (int i = 0; i < comparison.getGenre().size(); i++)
    {
        for (int j = 0; j < curr.getGenre().size(); j++)
        {
            if (comparison.getGenre()[i] == curr.getGenre()[j])
                similarityRanking += 10;

        }
    }

    // year released
    int difference = comparison.getReleaseYear() - curr.getReleaseYear();
    difference = abs(difference);
    if (difference <= 5)
        similarityRanking += 7;
    else if (difference <= 10)
        similarityRanking += 5;
    
      
    // director
    if (comparison.getDirector() == curr.getDirector())
    {
        similarityRanking += 5;
    }

    // cast
    for (int k = 0; k < comparison.getCast().size(); k++)
    {
        for (int l = 0; l < curr.getCast().size(); l++)
        {
            if (comparison.getCast()[k] == curr.getCast()[l])
                similarityRanking += 3;

        }
    }

    // duration
    int diff = comparison.getReleaseYear() - curr.getReleaseYear();
    diff = abs(diff);
    if (diff <= 20)
    {
        similarityRanking += 3;
    }



    curr.setSimilarityRanking(similarityRanking);
    
}

void Heap::buildHeap()
{
    int n = maxHeap.size();
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
        heapify(i);
}

void Heap::heapify(int index)
{
    int n = maxHeap.size();
    int l = index; 
    int left = 2 * index + 1; 
    int right = 2 * index + 2; 

    if (left < n && maxHeap[left].getSimilarityRanking() > maxHeap[l].getSimilarityRanking())
        l = left;

    if (right < n && maxHeap[right].getSimilarityRanking() > maxHeap[l].getSimilarityRanking())
        l = right;

    if (l != index) 
    {
        swap(maxHeap[index], maxHeap[l]);
        heapify(l);
    }
}
