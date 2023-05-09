## [leetcode] number of islands

[number of islands](https://leetcode.com/problems/number-of-islands/)

### 코드

```java
import java.util.Queue;
import java.util.LinkedList;

// https://leetcode.com/problems/number-of-islands/
public class NumberOfIslands {

  private static final Character ISLAND = '1';
  private static final Character WATER = '0';

  private static boolean[][] visited;
  private static int row, col;

  public int numIslands(char[][] grid) {

    int answer = 0;
    row = grid.length;
    col = grid[0].length;
    visited = new boolean[row][col];

    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        if(grid[i][j] == ISLAND && !visited[i][j]) {
          answer++;
          bfs(i, j, grid);
        }
      }
    }

    return answer;
  }

  private void bfs(int x, int y, char[][] grid) {
    visited[x][y] = true;
    Queue<Node> queue = new LinkedList<>();
    queue.add(new Node(x, y));

    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    while(!queue.isEmpty()) {
      Node node = queue.poll();
      int cx = node.x;
      int cy = node.y;

      for(int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(nx < 0 || nx >= row || ny < 0 || ny >= col || visited[nx][ny]) continue;
        if(grid[nx][ny] == WATER) continue;
        visited[nx][ny] = true;
        queue.add(new Node(nx, ny));
      }

    }

  }

  private class Node {
    int x, y;
    Node(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

}

```

### 📖 해결방법
