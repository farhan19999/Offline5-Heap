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
        this->maxSize = maxSize;
        this->tree = new int[maxSize];
    }

    void swap(int OldParentIndex, int OldChildIndex )
    {
        int temp = tree[OldParentIndex];
        tree[OldParentIndex] = tree[OldChildIndex];
        tree[OldChildIndex] = temp;
    }

    void insert(int elem)
    {
        tree[length++] = elem;
        int last = length-1;

        while(tree[last/2] < tree[last] && last != 0)
        {
            swap(last/2, last);
            last = last/2;
        }
    }

    int getMax()
    {
        return tree[0];
    }

    void deleteKey()
    {
        if(isEmpty())return;
        cout<<"deleting...."<<endl;
        tree[0] = tree[length-1];
        tree[length-1] = -1;
        length--;

        int last = 0 ;
        while((last*2)<length)
        {
            if(last*2 == length-1)
            {
                if(tree[last] < tree[last*2])
                {
                    swap(last, last*2);
                    last = last*2;
                }
                continue;
            }
            if(tree[last] > tree[last*2] && tree[last] > tree[last*2 + 1])break;

            if(tree[last*2] > tree[last*2+1] && tree[last*2] > tree[last])
            {
                swap(last, last*2);
                last = last*2;
            }
            else if(tree[last*2 +1] > tree[last*2] && tree[last*2 +1] > tree[last])
            {
                swap(last, last*2);
                last = last*2;
            }
            else break;
        }
    }
    int size()
    {
        return length;
    }
    bool isEmpty()
    {
        return length == 0;
    }

};
