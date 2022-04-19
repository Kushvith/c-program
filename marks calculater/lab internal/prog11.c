#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int a[10][10], i, j, n, m, source, b[10], s[10], visited[10];
void create()
{
    printf("enter the number of veryices of graph\n");
    scanf("%d", &n);
    printf("enter the adjaceny matrix to the graph\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void bfs()
{
    int rear = -1, front = 0, q[10], u;
    printf("enter the source of the vertex\n");
    scanf("%d", &source);
    q[++rear] = source;
    visited[source] = 1;
    while (front <= rear)
    {
        u = q[front++];
        for (i = 0; i < n; i++)
        {
            if (a[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++rear] = i;
                printf("%d", i);
            }
        }
    }
}
void dfs(int source)
{
    int v, top = -1;
    s[++top] = source;
    b[source] = 1;
    for (v = 0; v < n; v++)
    {
        if (a[source][v] == 1 && b[v] == 0)
        {
            printf("%d->%d\n", source, v);
            dfs(v);
        }
    }
}
void main()
{
    int ch;
    while (ch != 4)
    {
        printf("\nenter the choice 1. create 2. bfs 3. dfs 4 . exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            bfs();
            for (i = 0; i < n; i++)
                if (visited[i] == 0)
                    printf("%d vertex visited is not reachable\n", i);
            break;

            break;
        case 3:
            printf("enter the source vertex\n");
            scanf("%d", &source);
            dfs(source);
            m = 1;
            for (i = 0; i < n; i++)
                if (b[i] == 0)
                    m = 0;
            if (m == 0)
            {
                printf("graph is not connected\n");
            }
            else
            {
                printf("graph is connected\n");
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}