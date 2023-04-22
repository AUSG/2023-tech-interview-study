## [leetcode] Jump Game2

[Jump Game2](https://leetcode.com/problems/jump-game-ii/)

### 코드

```java
// https://leetcode.com/problems/jump-game-ii/
public class JumpGame2 {
   public int jump(int[] nums) {

      int[] dp = new int[nums.length];

      for(int i = 0; i < nums.length; i++) {
         dp[i] = 10001;
      }
      dp[nums.length - 1] = 0;

      for(int i = nums.length - 2; i >= 0; i--) {
         int jump = nums[i];

         for(int j = 1; j <= jump; j++) {
            if(i + j >= nums.length) continue;
            dp[i] = Math.min(dp[i], dp[i + j] + 1);
         }
      }
      return dp[0];
   }
}
```

### 📖 해결방법

`DP`
1. 각 위치에서 마지막 인덱스까지 가는데 필요한 점프 횟수를 저장할 dp 배열 생성 후 초기화
2. 마지막 인덱스부터 반복문을 돌면서 최소 점프 횟수를 찾는다.
   - 기저사례 : 범위를 넘어가는 경우(마지막 인덱스 보다 큰 값은 넘어간다.)
