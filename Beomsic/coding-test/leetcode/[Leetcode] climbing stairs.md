## [leetcode] Climbing stairs

[Climbing stairs](https://leetcode.com/problems/climbing-stairs/)

### ์ฝ๋

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

### ๐ย ํด๊ฒฐ๋ฐฉ๋ฒ

`DP`

1. ๊ฐ ์ธต์ ์ค๋ฅด๋ ๋ฐฉ๋ฒ์ 1์นธ์ฉ ์ด๋, 2์นธ์ฉ ์ด๋ํ๋ ๋ฐฉ๋ฒ
2. ์ ํ์ : dp[i] = dp[i - 1] + dp[i - 2];