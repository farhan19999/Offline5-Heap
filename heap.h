#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000


class Heap
{
private :
    int maxSize = 0;
    int* tree;
    int length = 0;
public:
    Heap(int maxSize)
    {
        this->maxSize = maxSize;
        this->tree = new int[maxSize+1];
    }


    Heap(vector<int>&v)
    {
        this->maxSize = v.size();
        this->tree = new int[maxSize+1];
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

        if(length == maxSize)
        {
            cout<<"Heap is full"<<endl;
            return;
        }

        //inserting new element node at the end of the tree
        tree[++length] = elem;
        int last = length;

        //up-heap bubbling
        while( last > 1 && tree[last/2] < tree[last])
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

        tree[1] = tree[length]; // exchanging the root with the last element node
        tree[length] = -INF;    //removing last element
        length--;

        max_heapify(1);         // max heapifing from the root
    }
  
    int size()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    //down-heap bubbling for max heap
    void max_heapify(int idx)
    {
        int left = idx*2;
        int right = idx*2 + 1;

        if(right<=length && tree[right] > tree[idx] && tree[right] > tree[left])
        {
            swap(idx, right);
            max_heapify(right);
        }
        else if(left<=length && tree[left] > tree[idx])
        {
            swap(idx, left);
            max_heapify(left);
        }
    }

};

void heapsort(vector<int>&v)
{
    Heap h(v);
    for(int i = 0 ; i<v.size() ; i++)
    {
        //extracting the maximum element removing from the heap
        v[i] = h.getMax();
        h.deleteKey();
    }
}
