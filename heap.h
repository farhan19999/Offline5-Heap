#include <bits/stdc++.h>
using namespace std;
#define Zero -999999999L

class Heap
{
private :
    int maxSize = 0;
    int* tree;
    int length = 0;
public:
    Heap(int maxSize)
    {
        this->maxSize = maxSize+1;
        this->tree = new int[maxSize];
    }

    Heap(vector<int>&v)
    {
        this->maxSize = v.size()+1;
        this->tree = new int[maxSize];
        for(int i = 0; i<v.size() ; i++ )insert(v[i]);
    }

    void swap(int OldParentIndex, int OldChildIndex )
    {
        int temp = tree[OldParentIndex];
        tree[OldParentIndex] = tree[OldChildIndex];
        tree[OldChildIndex] = temp;
    }

    void insert(int elem)
    {
        tree[++length] = elem;
        int last = length;

        while(tree[last/2] < tree[last] && last != 1)
        {
            swap(last/2, last);
            last = last/2;
        }
    }

    int getMax()
    {
        return tree[1];
    }

    void deleteKey()
    {
        if(isEmpty())return;
        tree[1] = tree[length];
        tree[length] = -1;
        length--;

        max_heapify(1);
    }
    int size()
    {
        return length;
    }
    bool isEmpty()
    {
        return length == 0;
    }

    void max_heapify(int idx)
    {
        int l = idx*2;
        int r = idx*2 + 1;

        if(r<=length && tree[r] > tree[idx] && tree[r] > tree[l])
        {
            swap(idx, r);
            max_heapify(r);
        }
        else if(l<=length && tree[l] > tree[idx])
        {
            swap(idx, l);
            max_heapify(l);
        }
    }

};

void heapsort(vector<int>&v)
{
    Heap h(v);
    for(int i = 0 ; i<v.size() ; i++)
    {
        v[i] = h.getMax();
        h.deleteKey();
    }
}
