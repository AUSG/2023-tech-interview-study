## [leetcode] Swim in Rising Water

[Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/)

### ์ฝ๋

```java
import java.util.*;

class Solution {
  public int swimInWater(int[][] grid) {

    PriorityQueue<Place> places = new PriorityQueue<Place>();
    boolean[][] visited = new boolean[grid.length][grid[0].length];

    int time = grid[0][0];
    places.add(new Place(0, 0, grid[0][0]));
    visited[0][0] = true;

    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    while(!places.isEmpty()) {

      Place here = places.poll();
      int cx = here.x;
      int cy = here.y;
      int cheight = here.height;

      time = Math.max(time, cheight);

      if(cx == grid.length - 1 && cy == grid[0].length - 1) break;

      for(int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if(nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[0].length) continue;
        if(visited[nx][ny]) continue;

        visited[nx][ny] = true;
        places.add(new Place(nx, ny, grid[nx][ny]));
      }

    }

    return time;
  }

  private class Place implements Comparable<Place>{
    int x, y, height;
    Place (int x, int y, int height) {
      this.x = x;
      this.y = y;
      this.height = height;
    }

    @Override
    public int compareTo(Place o) {
      if(this.height < o.height) return -1;
      else return 1;
    }
  }
}
```

### ๐ย ํด๊ฒฐ๋ฐฉ๋ฒ

`BFS`

์ฐ์ ์์ ํ๋ฅผ ์ฌ์ฉํด ๊ฐ์ฅ ๊น์ด๊ฐ ๋ฎ์ ์นธ์ผ๋ก ์ด๋  
- ์ด๋ํ๋ฉด์ ํ์ฌ ์นธ์ ๊น์ด์ ์ง๊ธ๊น์ง ๊ฐ๋ ์นธ์ ๊ฐ์ฅ ๋์ ๊น์ด๋ฅผ ๋น๊ต 
- ๋์ฐฉํ๋ฉด break