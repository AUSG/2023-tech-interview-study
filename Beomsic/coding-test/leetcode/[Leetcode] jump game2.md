## [leetcode] Jump Game2

[Jump Game2](https://leetcode.com/problems/jump-game-ii/)

### μ½λ

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

### πΒ ν΄κ²°λ°©λ²

`DP`
1. κ° μμΉμμ λ§μ§λ§ μΈλ±μ€κΉμ§ κ°λλ° νμν μ ν νμλ₯Ό μ μ₯ν  dp λ°°μ΄ μμ± ν μ΄κΈ°ν
2. λ§μ§λ§ μΈλ±μ€λΆν° λ°λ³΅λ¬Έμ λλ©΄μ μ΅μ μ ν νμλ₯Ό μ°Ύλλ€.
   - κΈ°μ μ¬λ‘ : λ²μλ₯Ό λμ΄κ°λ κ²½μ°(λ§μ§λ§ μΈλ±μ€ λ³΄λ€ ν° κ°μ λμ΄κ°λ€.)
