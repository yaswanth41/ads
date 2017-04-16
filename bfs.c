#include<stdio.h>
#include<conio.h>
int a[20][20],q[20],visited[20],n,i,j,f=-1,r=-1;
void bfs(int v)
{
  printf("%d ",v);
  visited[v]=1;
  do
  {
   for(i=0;i<n;i++)
   {
    if(a[v][i]==1&&visited[i]==0)
    {
     q[++r]=i;
     printf("%d ",i);
     visited[i]=1;
    }
   }
   if(f==r)
    return;
   else
    v=q[f++];
  }while(1);
}
void main()
{
 int v;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }
 printf("\n Enter graph data in matrix form:\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   scanf("%d",&a[i][j]);
 printf("\n Enter the starting vertex:");
 scanf("%d",&v);
 bfs(v);
 getch();
}

