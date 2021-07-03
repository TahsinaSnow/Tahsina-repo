#include<stdio.h>
void BFS(int);
int G[10][10],visited[10]={0},n;
int main()
{
	int i,k,j,start;
	printf("Enter number of edges:");
	scanf("%d",&n);
	printf("\nEnter edges of the graph:\n");
	for(k = 0; k < n; k++){
        scanf("%d%d",&i,&j);
        G[i][j] = 1;
        G[j][i] = 1;
    }
    printf("Enter start node:");
    scanf("%d",&start);
	BFS(start);
}
void BFS(int i)
{
	int j;
	printf("\n%d",i);
	visited[i]=1;
	for(j=0;j<n;j++)
	if(visited[j]==0&&G[i][j]==1)
	BFS(j);
}
