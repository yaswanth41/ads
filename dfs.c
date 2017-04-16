#include<stdio.h>
#include<conio.h>
int a[10][10],st[10],visited[10],n,i,j,top=-1;
void dfs(int v)
{
  while(1)
  {
   printf("%d ",v);
   visited[v]=1;
    for(i=n;i>=0;i--)
    {
     if(a[v][i]==1&&visited[i]==0)
           push(i);
    }
    v=pop();
    if(v==-1)
      return;
   }
}
push(int x)
{
 if(top==9)
  printf("Stack is Full");
 else
  st[++top]=x;
}
int pop()
{
 if(top==-1)
  return -1;
 else
  return(st[top--]);
}
void main()
{
 int v;
 printf("\nEnter the number of vertices:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
   visited[i]=0;
 printf("\n Enter graph data in matrix form:\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   scanf("%d",&a[i][j]);
 printf("\n Enter the starting vertex:");
 scanf("%d",&v);
 dfs(v);
 getch();
}

