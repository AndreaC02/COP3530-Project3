#include "series.h"
#include <vector>
using namespace std;
class Heap 
{

    vector<Series> maxHeap;

public:
    Heap();
    void push(Series obj);
    void pop();
    Series top();
    void heapSort();
    void printSimilarities();
    




};