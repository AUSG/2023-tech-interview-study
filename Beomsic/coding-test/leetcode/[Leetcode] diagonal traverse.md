## [leetcode] Diagonal Traverse

[Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/description)

### 코드

```java
// https://leetcode.com/problems/diagonal-traverse/description/
public class DiagonalTraverse {

   private static final int UP = 0;
   private static final int DOWN = 1;

   public int[] findDiagonalOrder(int[][] mat) {

      int m = mat.length;
      int n = mat[0].length;

      int[] answer = new int[m * n];

      int row = 0;
      int col = 0;
      for(int i = 0; i < m * n; i++) {

         answer[i] = mat[row][col];

         // up
         if((row + col) % 2 == 0) {
            if(col == n - 1) row += 1;
            else if(row == 0) col += 1;
            else {
               row -= 1;
               col += 1;
            }
         }

         // down
         else {
            if(row == m - 1) col += 1;
            else if(col == 0) row += 1;
            else {
               row += 1;
               col -= 1;
            }
         }

      }

      return answer;
   }

}
```

### 📖 해결방법

`simulation`
