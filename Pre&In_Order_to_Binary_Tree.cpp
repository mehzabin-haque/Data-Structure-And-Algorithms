#include<bits/stdc++.h>
using namespace std;

int j=99,k=0,inorder[100], s[100], preorder[100], n;

void root_sub_tree(int pos,int start,int end)
{

    if(start>end)
        return ;
     
	int t=start;
    k++;
    while(inorder[t]!=preorder[k])
       t++;
      s[pos]=inorder[t];

        root_sub_tree(pos*2+1,start,t-1);
        root_sub_tree(pos*2+2,t+1,end);
}


void div_sub_tree(int root)
{
    int i=0,pos=0;
    while(inorder[i]!=root)
        i++;

    root_sub_tree(pos*2+1,0,i-1);
    root_sub_tree(pos*2+2,i+1,n-1);
 
}


int main()
{
    int i;

    printf("Enter the number of elements :\n");
    scanf("%d",&n);

    printf("Enter the elements in PreOrder :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }

    printf("Enter the elements in InOrder format:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
    }

    int root = preorder[0];
    s[0] = preorder[0];
    
    div_sub_tree(root);
    
    while(s[j]=='\0')
    j--;
    
    for(i=0;i<=j;i++)
    	printf("%d ",s[i]);
}
