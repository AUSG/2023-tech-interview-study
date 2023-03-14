## [leetcode] Jump Game

[Jump Game](https://leetcode.com/problems/jump-game/)

### 코드

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

### 📖 해결방법

`DP`

-  마지막 인덱스 전 부터 반복문을 돌면서 해당 인덱스에서 점프해서 마지막 인덱스로 갈 수 있는 곳으로 점프를 할 수 있는지 확인
-  점프를 해도 해당 장소로 가지 못한다면 isArrive 변수를 false로 하고 점프해야하는 거리를 더 늘린다.(count+=1)
