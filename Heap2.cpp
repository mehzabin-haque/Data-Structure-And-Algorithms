#include <bits/stdc++.h>
using namespace std;
void min_heapify(int a[], int n, int i)
{
	int min = i;
	int l = 2*i;
	int r = 2*i + 1;
	   
	if (l <= n && a[l] < a[min])
	{
		min = l;
	}
	
	if (r <= n && a[r] < a[min])
	{
		min = r;
	}
	
	if (min != i)
	{
		swap(a[i] , a[min]) ;
		min_heapify(a,n,min) ;
	}
	
}

void displayArray(int a[], int n)
{
	for (int i=1; i<=n; ++i)
		cout << a[i] << " ";
	cout << "\n";
}
int main()
{
	int a[1000];
	int n,i=1,j;
	while(scanf("%d!",&n)!=EOF)
	{
	    a[j]=n;
	    j++;
	}
	    for (int i = j / 2; i >= 1; i--)
			min_heapify(a, j, i);
	   
	cout<<"Min heapify tree : \n";
	   
	displayArray(a, j);
	
	return 0;
}
