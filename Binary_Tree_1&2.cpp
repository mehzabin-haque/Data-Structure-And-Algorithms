#include<stdio.h>
#include<stdlib.h>
const int N = 10000;

int arr [N];

int pre_order[N];
int pre_idx = 1;

int in_order[N];
int in_idx = 1;

int post_order[N];
int post_idx = 1;

void preOrder(int start, int maxId){
	
	if (start > maxId ) return;

	//printf("%d %d\n", pre_idx, arr[start]);
	
	
	if( arr[start] == -1 ){
		return;
	} 
	else 
	{
		//process
		pre_order[pre_idx++] = arr[start];
		//left child e jabe
		preOrder(2*start, maxId);
		//right child e jabe
		preOrder(2*start + 1, maxId);
	}
	
}

void postOrder(int start, int maxId){
	
	if (start > maxId ) return;

	//printf("%d %d\n", post_idx, arr[start]);
	
	
	if( arr[start] == -1 )
	{
		return;
	} 
	else 
	{
		//left child e jabe
		postOrder(2*start, maxId);
		//right child e jabe
		postOrder(2*start + 1, maxId);
		//process
		post_order[post_idx++] = arr[start];
	}
	
}

void inOrder(int start, int maxId){
	
	if (start > maxId ) return;

	//printf("%d %d\n", in_idx, arr[start]);
	
	
	if( arr[start] == -1 )
	{
		return;
	} 
	else
	{
		//left child e jabe
		inOrder(2*start, maxId);
		//process
		in_order[in_idx++] = arr[start];
		//right child e jabe
		inOrder(2*start + 1, maxId);
	}
	
}

int main (){
	
	int n;
	printf("Enter the max input number : \n");
	scanf("%d",&n);
	
	printf("Enter the numbers : \n");
	
	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]);	
	}
	
	preOrder(1,n);
	printf("Pre order: ");
	for (int i=1;i<pre_idx;i++) printf("%d ", pre_order[i]);
	puts("\n");
	
	postOrder(1,n);
	printf("Post order: ");
	for (int i=1;i<post_idx;i++) printf("%d ", post_order[i]);
	puts("\n");
	
	inOrder(1,n);
	printf("In order: ");
	for (int i=1;i<in_idx;i++) printf("%d ", in_order[i]);
	puts("\n");
}
