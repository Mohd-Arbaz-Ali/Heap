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
    return h->count;
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
int kthMax(heap* h,int k){
	heap* aux=new heap(k);
	int kthElement;
	insert(aux,getMax(h));
	while(1){
		kthElement=aux->arr[deleteMax(aux)];
		if(++aux->count==k)
			return kthElement;
		else
		{
			insert(aux,h->arr[2*kthElement+1]);
			insert(aux,h->arr[2*kthElement+2]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[]={3,10,8,16,12,13,20};
    heap *h1=new heap(7);
    BuildHeap(h1,arr,7);
    for (int i = 0; i < h1->count; ++i)
	{
		cout<<h1->arr[i]<<" ";
	}
	cout<<endl;

    cout<<kthMax(h1,4)<<endl;

	return 0;
}
