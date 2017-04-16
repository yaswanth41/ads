#include<stdio.h>
#include<conio.h>
int a[10][10],n;
char v[10];

void main()
{

int i,j,t,ch;
char f,x,s,d;
printf("Enter no of vertices");
scanf("%d",&n);
printf("Enter the vertices names");
for(i=0;i<n;i++)
scanf(" %c",&v[i]);
printf("Enter the adjacent vertices(0/1)");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
do
{
printf("\n 1.Insert \n 2.Delete vertex \n 3.Find vertex \n 4.Add Edge \n 5.Delete Edge \n 6.Display\n 7.EXIT");
scanf("%d",&ch);
switch(ch)
{
 case 1: printf("Enter the vertex");
	 scanf(" %c",&x);
	 insert(x);
	 break;
 case 2: printf("Enter vertex to be deleted");
	 scanf(" %c",&x);
	 delete(x);
	 break;
 case 3: printf("Enter the vertex to be found");
	 scanf(" %c",&f);
	 t=find(f);
	 if(t==-1)
	  printf("Not Found");
	 else
	  printf("Found");
	 break;
 case 4: printf("enter the Edge");
	 scanf(" %c",&s);
	 scanf(" %c",&d);
	 addedge(s,d);
	 break;
 case 5: printf("enter the Edge");
	 scanf(" %c",&s);
	 scanf(" %c",&d);
	 deleteedge(s,d);
	 break;
 case 6: display();
	 break;
 case 7:exit(0);
}
}while(1);
}
insert(char x)
{
 int i;
 v[n]=x;
 n=n+1;
 v[n+1]='\0';
 for(i=0;i<n;i++)
  a[i][n-1]=0;
 for(i=0;i<n;i++)
  a[n-1][i]=0;
}
delete(char x)
{
 int i,j,r;
 r=find(x);
 if(r==-1)
  printf("vertex not found");
 else
 {
  for(i=r;i<n;i++)
     v[i]=v[i+1];
  v[i]='\0';
 for(i=0;i<n;i++)
  for(j=r;j<n;j++)
      a[i][j]=a[i][j+1];
 for(j=0;j<n;j++)
   for(i=r;i<n;i++)
     a[i][j]=a[i+1][j];
   n--;
  }
}
display()
{
 int i,j;
 printf("\nVertex Are:\n");
 for(i=0;i<n;i++)
   printf("%c ",v[i]);
 printf("\nAdjancy matrix is:\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   printf("%d ",a[i][j]);
   printf("\n");
 }
}
int find(char x)
{
 int i;
 for(i=0;i<n;i++)
 {
   if(v[i]==x)
    return i;
 }
 return -1;
}
addedge(char s,char d)
{
 int i,j;
 i=find(s);
 j=find(d);
 if(i!=-1&&j!=-1)
 {
  a[i][j]=1;
  a[j][i]=1;
 }
 else
  printf("Vertices u entered are invalid");
}
deleteedge(char s, char d)
{
 int i,j;
 i=find(s);
 j=find(d);
 if(i!=-1&&j!=-1&&a[i][j]==1)
 {
  a[i][j]=0;
  a[j][i]=0;
 }
 else
  printf("Vertices u entered are invalid");
}

