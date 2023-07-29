#include<bits/stdc++.h>
using namespace std ;

void max_heapify(int a[], int n, int i)
{
	int max = i;
	int l = 2*i ;
	int r = 2*i+1;
	if (l <= n && a[l] > a[max])
	{
		max = l;
	}
	
	if (r <= n && a[r] > a[max])
	{
		max = r;
	}
	
	if (max != i)
	{
		swap(a[max] , a[i]) ;
	    max_heapify(a, n, max);
    }
}

void heapsort(int a[] , int n)
{
	int i;
	// build max heap
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a, n, i);
	}
	
	// deletion
	for(i=n;i>=1;i--)
	{
		swap(a[1],a[i] ) ;
		max_heapify(a, n, 1);
	}
}

int main()
{
	int a[100] , n , i , j , temp , value ;
	
	cout << "Enter the number of elements : " << endl;
	cin >> n ;
	
	cout << "Enter the elements : " ;
	
	for(i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	
	max_heapify(a, n, i);
	heapsort(a,n);
	
	cout << "Sorted array is \n";
	
	for (i=1;i<=n;i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
