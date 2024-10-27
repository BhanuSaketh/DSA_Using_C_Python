void DFS(int g[V][V], int start) {
    int stack[V], top = -1;  
    int i, current;

    stack[++top] = start;
    visited[start] = 1;  

    while (top != -1) {
        current = stack[top--];
        printf("%d ", current);
      
        for (i = 0; i < V; i++) {
            if (g[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}
