## [leetcode] Coin Change

[Coin Change](https://leetcode.com/problems/coin-change/)

### 코드

```java
import java.util.Arrays;

// https://leetcode.com/problems/coin-change/
public class CoinChange {
  public int coinChange(int[] coins, int amount) {

    if(amount == 0) return 0;

    int[] dp = new int[amount + 1];

    for(int i = 1; i <= amount; i++) {
      dp[i] = 987654321;
    }

    for(int i = 0; i < coins.length; i++) {
      if(coins[i] > amount) continue;
      dp[coins[i]] = 1;
    }

    Arrays.sort(coins);

    for(int target = coins[0]; target <= amount; target++) {
      for(int i = 0; i < coins.length; i++) {
        if(coins[i] > target) break;
        dp[target] = Math.min(dp[target], dp[target - coins[i]] + 1);
      }
    }

    return dp[amount] == 987654321 ? -1 : dp[amount];

  }
}
```

### 📖 해결방법
