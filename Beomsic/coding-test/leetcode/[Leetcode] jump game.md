## [leetcode] Jump Game

[Jump Game](https://leetcode.com/problems/jump-game/)

### ์ฝ๋

```java
// https://leetcode.com/problems/jump-game/
public class JumpGame {
   public boolean canJump(int[] nums) {
      int lastIndex = nums.length;

      boolean isArrive = true;
      int count = 1;

      for(int i = lastIndex - 2; i >= 0; i--) {

         if(nums[i] >= count) {
            isArrive = true;
            count = 1;
         }
         else {
            count++;
            isArrive = false;
         }

      }

      return isArrive;
   }
}

```

### ๐ย ํด๊ฒฐ๋ฐฉ๋ฒ

`DP`

-  ๋ง์ง๋ง ์ธ๋ฑ์ค ์  ๋ถํฐ ๋ฐ๋ณต๋ฌธ์ ๋๋ฉด์ ํด๋น ์ธ๋ฑ์ค์์ ์ ํํด์ ๋ง์ง๋ง ์ธ๋ฑ์ค๋ก ๊ฐ ์ ์๋ ๊ณณ์ผ๋ก ์ ํ๋ฅผ ํ  ์ ์๋์ง ํ์ธ
-  ์ ํ๋ฅผ ํด๋ ํด๋น ์ฅ์๋ก ๊ฐ์ง ๋ชปํ๋ค๋ฉด isArrive ๋ณ์๋ฅผ false๋ก ํ๊ณ  ์ ํํด์ผํ๋ ๊ฑฐ๋ฆฌ๋ฅผ ๋ ๋๋ฆฐ๋ค.(count+=1)
