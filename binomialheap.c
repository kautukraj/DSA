#include<stdio.h>
#include<stdlib.h>
#define HEAP_SIZE 20

struct Heap{
    int *arr; // array equivalent of every heap
    int count; // number of elements in the heap
    int capacity; // total capacity of the heap
    int heap_type; // 0 for min heap , 1 for max heap
};
typedef struct Heap Heap; // making a datatype of the type Heap

Heap* CreateHeap(int capacity,int heap_type);
void insert(Heap* h, int key);
void print(Heap* h);
void heapify_bottom_top(Heap* h,int index);
void heapify_top_bottom(Heap* h, int i); 
int PopMin(Heap* h);
void swap(int*, int*);
void update(Heap* h, int index, int data);
void deleteany(Heap* h, int data);

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int i;
    Heap* heap = CreateHeap(HEAP_SIZE, 0); //Min Heap
    if( heap == NULL )
    {
        printf("Memory Issue\n");
        return -1;
    }

    for(i =9;i>0;i--) // inserting elements into heap
        insert(heap, i);

    print(heap);

    for(i=9;i>=0;i--)
    {
        printf(" Pop Minima : %d\n", PopMin(heap));
        print(heap);
    }

    
    return 0;
}

Heap* CreateHeap(int capacity,int heap_type)
{
    Heap* h = (Heap*) malloc(sizeof(Heap)); 

    //check if memory allocation is fails
    if(h == NULL)
    {
        printf("Memory Error!");
        return;
    }
    
    h->heap_type = heap_type;
    h->count=0; // number of elements initially is zero
    h->capacity = capacity;
    h->arr = (int*) malloc(capacity*sizeof(int)); //size in bytes

    //check if allocation succeed
    if ( h->arr == NULL)
    {
        printf("Memory Error!");
        return;
    }
    
    return h; 
}

void insert(Heap *h, int key)
{
    if( h->count < h->capacity) // if space is left
    {
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count); // h->count is the index
        h->count++;
    }
    else
        printf("Heap is full!\n");
}

void heapify_bottom_top(Heap* h, int index) 
{
    int temp;
    int parent_node = (index-1)/2;

    /*if(h->arr[parent_node] > h->arr[index]) // using recursion
    {
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h,parent_node);
    }*/
    
    while (parent_node>=0 && h->arr[parent_node] > h->arr[index])
    {
        swap(&(h->arr[parent_node]), &(h->arr[index]));
        index = parent_node;
        parent_node = (index-1)/2;
    }
}

void heapify_top_bottom(Heap *h, int i) 
{
    int left; int right; int min; int temp;

    /*if(left >= h->count || left <0) // recursion
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[i])
        min=left;
    else
        min=i;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != i)
    {
        temp = h->arr[min];
        h->arr[min] = h->arr[i];
        h->arr[i] = temp;

        // recursive  call
        heapify_top_bottom(h, min);
    }*/
    
    while (2*i+1 < h->count)
    {
        if (h->arr[2*i+1] < h->arr[2*i+2])
            left = 2*i + 1;
        else
            left = 2*i + 2;
        
        if (h->arr[i] > h->arr[left])
        {
            swap(&(h->arr[i]), &(h->arr[left]));
            i = left;
        }
        else
            break;
    }
    
    if (2*i+1 < h->count && h->arr[i] > h->arr[2*i+1])
        swap(&(h->arr[i]), &(h->arr[2*i+1]));
}

int PopMin(Heap *h)
{
    int pop;
    if(h->count==0)
    {
        printf("\nHeap is Empty\n");
        return -1;
    }
    // replace first node by last and delete last
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}

void update (Heap* h, int index, int data)
{
    if (h->arr[index] < data) // increase key
    {
        h->arr[index] = data;
        heapify_top_bottom(h, index);
    }
    else if ((h->arr[index] > data)) // decrease key
    {
        h->arr[index] = data;
        heapify_bottom_top(h, index);
    }
}

void deleteany (Heap* h, int data)
{
    update(h, data, h->arr[0]);
    int t = PopMin(h);
}


void print(Heap *h)
{
    int i;
    printf("Print Heap\n");
    for(i=0;i< h->count;i++)
    {
        printf("-> %d ",h->arr[i]);
    }
    printf("->__/\\__\n");
}
