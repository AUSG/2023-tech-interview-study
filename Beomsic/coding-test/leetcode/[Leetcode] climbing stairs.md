## [leetcode] Climbing stairs

[Climbing stairs](https://leetcode.com/problems/climbing-stairs/)

### 코드

```java
// https://leetcode.com/problems/climbing-stairs/
public class ClimbingStairs {
  public int climbStairs(int n) {

    int[] stairs = new int[n + 1];
    stairs[0] = 0;
    stairs[1] = 1;

    for(int i = 2; i <= n; i++) {
      stairs[i] = stairs[i - 2] + stairs[i - 1];
    }

    return stairs[n];
  }
}
```

### 📖 해결방법

`DP`

1. 각 층을 오르는 방법은 1칸씩 이동, 2칸씩 이동하는 방법
2. 점화식 : dp[i] = dp[i - 1] + dp[i - 2];