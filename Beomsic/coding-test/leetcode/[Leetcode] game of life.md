## [leetcode] Game of Life

[Game of Life](https://leetcode.com/problems/game-of-life)

### 코드

```java
// https://leetcode.com/problems/game-of-life
public class GameOfLife {

  private static final int ALIVE = 1;
  private static final int DIE = 0;

  private static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  private static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  private static int row;
  private static int col;

  public void gameOfLife(int[][] board) {

    List<Cell> alive = new ArrayList<>();
    List<Cell> die = new ArrayList<>();

    row = board.length;
    col = board[0].length;

    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        if(board[i][j] == ALIVE && isDie(i, j, board)) die.add(new Cell(i, j));
        else if(board[i][j] == DIE && isAlive(i, j, board)) alive.add(new Cell(i, j));
      }
    }

    for(Cell cell : alive) {
      board[cell.x][cell.y] = ALIVE;
    }

    for(Cell cell : die) {
      board[cell.x][cell.y] = DIE;
    }
  }

  private boolean isDie(int x, int y, int[][] board) {

    int aliveCell = 0;
    for(int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isWithinBounds(nx, ny) && board[nx][ny] == ALIVE) aliveCell++;
    }

    if(aliveCell < 2 || aliveCell > 3) return true;
    return false;
  }

  private boolean isAlive(int x, int y, int[][] board) {

    int aliveCell = 0;
    for(int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(isWithinBounds(nx, ny) && board[nx][ny] == ALIVE) aliveCell++;
    }
    if(aliveCell == 3) return true;
    return false;
  }

  private boolean isWithinBounds (int x, int y) {
    if(x < 0 || x >= row || y < 0 || y >= col) return false;
    return true;
  }

  private class Cell {
    int x, y;
    Cell(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }
}

```

### 📖 해결방법
