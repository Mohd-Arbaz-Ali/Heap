// Max heap
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class heap{
public:
	int *arr;
	int capacity;
	int count;

	heap(int cap){
		capacity=cap;
		arr=new int[cap];
		count=0;
	}
};

int parent(int i){
    return (i-1)/2;
}
int leftChild(int i){
	return 2*i+1;
}
int rightChild(int i){
	return 2*i+2;
}

void insert(heap* h,int key){
	if(h->count==h->capacity){
		h->arr=(int*)realloc(h->arr,h->capacity*2);
		h->capacity*=2;
	}
	h->count++;
    int i=h->count-1;
	h->arr[i]=key;
    while(i>0 && h->arr[i]>h->arr[parent(i)]){
        swap(h->arr[i],h->arr[parent(i)]);
        i=parent(i);
    }
}

int getMax(heap *h){
	return h->arr[0];
}

void maxHeapify(heap *h,int i){
	if(i>=h->count)
		return;
    int left=leftChild(i);
    int right=rightChild(i);
    int largest=i;
    if(left<h->count && h->arr[i]<h->arr[left])
        largest=left;
    if(right<h->count && h->arr[largest]<h->arr[right])
        largest=right;
    if(largest!=i){
    	swap(h->arr[largest],h->arr[i]);
        maxHeapify(h,largest);
    }
}

int deleteMax(heap* h){
    if(h->count==0)
    	return -1;
    swap(h->arr[0],h->arr[--h->count]);
    maxHeapify(h,0);
    return h->arr[h->count];
}

void increaseKey(heap* h,int i,int new_key){
	if(i<0 && i>=h->count)
		return;
	h->arr[i]=new_key;
	while(i>=0 && h->arr[i]>h->arr[parent(i)]){
		swap(h->arr[i],h->arr[parent(i)]);
		i=parent(i);
	}
}

void deleteKey(heap* h,int i){
	if(i<0 && i>=h->count)
		return;
	increaseKey(h,i,INT_MAX);
	deleteMax(h);
}

void BuildHeap(heap* h,int a[],int n){
    if(!h)
    	return;
    if(n>h->capacity)
    	h->arr=(int*)realloc(h->arr,h->capacity*2);
    for(int i=0;i<n;i++){
    	h->arr[i]=a[i];
    }
    h->count=n;
    for(int i=(n-2)/2;i>=0;i--){
    	maxHeapify(h,i);
    }
}

int minElement(heap* h){
	int Min=INT_MAX;
	for(int i=(h->count+1)/2;i<h->count;i++){
		Min=min(h->arr[i],Min);
	}
	return Min;
}

int main(int argc, char const *argv[])
{
	heap *h=new heap(6);
	insert(h,3);
	insert(h,10);
	insert(h,8);
	insert(h,16);
	insert(h,12);
	insert(h,13);
	insert(h,20);
	for (int i = 0; i < h->count; ++i)
	{
		cout<<h->arr[i]<<" ";
	}
	cout<<endl;
	cout<<deleteMax(h)<<endl;
	increaseKey(h,2,25);
	deleteKey(h,3);
	cout<<getMax(h)<<endl;
	for (int i = 0; i < h->count; ++i)
	{
		cout<<h->arr[i]<<" ";
	}
	cout<<endl;

    int arr[]={3,10,8,16,12,13,20};
    heap *h1=new heap(7);
    BuildHeap(h1,arr,7);
    for (int i = 0; i < h1->count; ++i)
	{
		cout<<h1->arr[i]<<" ";
	}
	cout<<endl;

    cout<<minElement(h1)<<endl;

	return 0;
}