## [leetcode] Generate Parentheses

[Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

### 코드

```java
import java.util.*;

// https://leetcode.com/problems/generate-parentheses/
public class GenerateParentheses {

   private static List<String> answer;

   public List<String> generateParenthesis(int n) {

      answer = new ArrayList<>();
      addParenthesis(n, n, new StringBuilder());

      return answer;
   }

   private void addParenthesis(int left, int right, StringBuilder sb) {

      if(left == 0 && right == 0) {
         answer.add(sb.toString());
         return;
      }

      // ')'' 괄호는 '(' 가 이미 사용된 후에만 사용이 가능하다.
      // 따라서 right 는 left 의 값이 right 보다 작을 때 사용가능.
      // left >= right 인 경우에는 무조건 left 사용

      if(left >= right) {
         sb.append("(");
         addParenthesis(left - 1, right, sb);
         sb.deleteCharAt(sb.length() - 1);
      }

      // 오른쪽 괄호도 사용가능 한 경우
      else {
         // 왼쪽 괄호를 사용
         if(left > 0) {
            sb.append("(");
            addParenthesis(left - 1, right, sb);
            sb.deleteCharAt(sb.length() - 1);
         }
         // 오른쪽 괄호를 사용
         sb.append(")");
         addParenthesis(left, right - 1, sb);
         sb.deleteCharAt(sb.length() - 1);
      }


   }


}
```

### 📖 해결방법

`dfs`