#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILE_PATH "./maze.data"

int maze[1004][1004];
int m, n;
int visited[1004][1004];
int DepthFirstSearch(int i,int j)
{
	if(maze[i][j]==0&&visited[i][j]==0&&i>=0&&i<m&&j>=0&&j<n&&visited[m-1][n-1]==0)
	{
		visited[i][j]=1;
		DepthFirstSearch(i,j+1);
		DepthFirstSearch(i,j-1);
		DepthFirstSearch(i-1,j);
		DepthFirstSearch(i+1,j);
	}
	return visited[m-1][n-1];
}
int haveExit() {
    int i=0,j=0;
	if(DepthFirstSearch(i,j))
		return 1;
	else
		return 0;
}

// 以下代码不允许修改
void read() {
    FILE *fp;
    memset(maze, -1, sizeof(maze));
    if ((fp = fopen(FILE_PATH, "r")) == NULL) {
        perror(FILE_PATH);
        exit(1);
    }
    fscanf(fp, "%d %d", &m, &n);
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
    fclose(fp);
}

int main() {
    read();
    if (haveExit()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}