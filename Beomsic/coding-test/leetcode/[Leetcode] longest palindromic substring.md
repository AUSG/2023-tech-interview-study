## [leetcode] Longest Palindromic Substring

[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)

### 코드

```java
// https://leetcode.com/problems/longest-palindromic-substring/description/
public class LongestPalindromicSubstring {

  public String longestPalindrome(String s) {

    if(s.length() == 1) return s;

    String answer = "";

    // Si ~ Sj 까지 부분 string이 palindrome 인지 아닌지 boolean 배열로 확인
    boolean[][] palindrome = new boolean[s.length()][s.length()];

    palindrome[0][0] = true;
    if(s.charAt(0) == s.charAt(1)) palindrome[0][1] = true;
    palindrome[1][1] = true;

    for(int i = 0; i < s.length(); i++) {
      for(int j = 0; j <= i; j++) {

        if(j == i) palindrome[j][i] = true;
        else if(j == i - 1) palindrome[j][i] = (s.charAt(j) == s.charAt(i));
          // sj ~ si 부분 string 확인
        else palindrome[j][i] = (palindrome[j + 1][i - 1] && (s.charAt(j) == s.charAt(i)));
        if(palindrome[j][i] && i - j + 1 > answer.length()) {
          answer = s.substring(j, i + 1);
        }
      }
    }

    return answer;

  }

}
```

### 📖 해결방법

`DP`

1. dp 배열 (palindrome) 을 통해 i ~ j 까지의 문자열이 palindrome인지 아닌지를 체크한다.
2. i ~ j 문자열이 palindrome이기 위한 조건
   - (i + 1) ~ (j - 1) 문자열이 palindrome 이여야 하고
   - 주어진 문자열의 i 번째 문자와 j 번째 문자가 같아야 한다.
   - 점화식 : palindrome[i][j] = (palindrome[i + 1][j - 1] && s.charAt(i) == s.charAt(j));
3. palindrome 인경우 현재 구한 가장 긴 palindrome 문자와 길이를 비교하고 더 길다면 갱신한다.