## [leetcode] Multiply Strings

[Multiply Strings](https://leetcode.com/problems/multiply-strings)

### 코드

```java
// https://leetcode.com/problems/multiply-strings/
public class MultiplyStrings {

   // BigDecimal 이용한 풀이
   // 시간 - 8ms
   public String multiply(String num1, String num2) {

      BigDecimal number1 = new BigDecimal(num1);
      BigDecimal number2 = new BigDecimal(num2);

      BigDecimal result = number1.multiply(number2);

      return result.toString();
   }


   // string 조작하여 풀이
   // 시간 - 3ms
   public String multiply2(String num1, String num2) {
      int length1 = num1.length();
      int length2 = num2.length();

      int[] result = new int[length1 + length2];

      // 뒤자리부터 곱
      for (int i = length1 - 1; i >= 0; i--) {
         for (int j = length2 - 1; j >= 0; j--) {
            int value1 = num1.charAt(i) - '0';
            int value2 = num2.charAt(j) - '0';
            result[i + j + 1] += value1 * value2;
         }
      }

      // 올릴 수
      int carry = 0;

      for (int i = result.length - 1; i >= 0; i--) {
         // 곱하고 남은 일의 자리
         int tmp = (result[i] + carry) % 10;

         // 다음 자리로 올릴 수
         carry = (result[i] + carry) / 10;
         result[i] = tmp;
      }

      StringBuilder sb = new StringBuilder();

      for (int num : result) sb.append(num);

      // 맨 앞 자리가 0으로 시작하는 경우 삭제.
      // 0이 아니라면 반복문 끝
      while (sb.length() != 0 && sb.charAt(0) == '0') sb.deleteCharAt(0);

      return sb.length() == 0 ? "0" : sb.toString();
   }
}
```

### 📖 해결방법

`simulation`

두 가지 방법으로 풀이
1. BigDecimal class 사용
2. 직접 String을 조작
   - 두 String의 뒷자리 숫자부터 곱해 int 배열에 저장
   - 저장한 int 배열을 돌면서 올려야 하는 숫자를 계산
   - 마지막에 0으로 시작하는지 체크

  
BigDecimal 클래스를 사용시 매우 짧게 코드를 작성할 수 있었음.  
하지만, 시간이 2배가 걸림.  
* BigDecimal 객체 생성을 하는데 시간이 오래걸린것 같다.