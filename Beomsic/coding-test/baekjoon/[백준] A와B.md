## A와B [12904번]

**Greedy**

[A와B](https://www.acmicpc.net/problem/12904)

### 코드
```java
// https://www.acmicpc.net/problem/12904
public class A와B {

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

      StringTokenizer st = new StringTokenizer(br.readLine());
      String source = st.nextToken();

      st = new StringTokenizer(br.readLine());
      String target = st.nextToken();

      // 만들어야하는 문자열의 마지막 문자부터 확인 (rightPointer 사용)
      // 문자가 'B'라면 그 앞의 문자들을 뒤집어서 생각해야 한다. -> isReverse를 반대로
      // 뒤집어서 생각하는 경우에는 문자열의 앞부터 확인한다. (leftPointer 사용)
      // 또 다시 뒤집히면 다시 뒤에서부터 확인한다.
      int rightPointer = target.length() - 1;
      int leftPointer = 0;
      boolean isReverse = false;
      int answer = 0;

      while(true) {

         // 주어진 만들기전 문자열의 길이만큼 확인했다면 해당 문자열이 지금 남은 문자열과 같은지 확인한다.
         if(rightPointer - leftPointer + 1 == source.length()) {
            String substring = target.substring(leftPointer, rightPointer + 1);

            if(isReverse) {
               StringBuffer sb = new StringBuffer(substring).reverse();
               substring = sb.toString();
            }
            if(source.equals(substring)) answer = 1;
            break;
         }

         // 뒤집혀 있는 경우
         if(isReverse) {
            char compare = target.charAt(leftPointer);
            if(compare == 'A') leftPointer++;
               // 뒤집어야 한다.
            else {
               leftPointer++;
               isReverse = false;
            }
         }

         else {
            char compare = target.charAt(rightPointer);
            if(compare == 'A') rightPointer--;
               // 뒤집어야 한다.
            else {
               rightPointer--;
               isReverse = true;
            }
         }
      }

      bw.write(String.valueOf(answer));
      bw.newLine();
      bw.flush();
      bw.close();
      br.close();
   }

}
```

### 📖 해결방법

`그리디`  

1. 만들어야 하는 문자열을 이용
2. 0번째 부터 시작하는 leftPointer, 마지막 원소부터 시작하는 rightPointer를 사용
3. 해당 문자열의 마지막 문자부터 확인 (rightPointer 사용)
   - `A` 라면 해당 문자 앞 부분을 뒤집어서 생각하지 않아도 된다.
   - `B` 라면 해당 문자 앞 부분을 뒤집어서 생각해야 한다, 이후 leftPointer 사용
   - rightPointer를 앞으로 땡긴다 (rightPointer--)
4. 문자열이 뒤집어진 경우에는 앞 부분 문자를 확인(leftPointer 사용)
   - 'A' 라면 그대로 leftPointer 를 사용
   - 'B' 라면 다시 뒤집는 경우로, 이후 rightPointer를 다시 사용
   - leftPointer++
5. rightPointer 와 leftPointer 의 차이가 처음 주어진 문자열의 길이과 같아질 때 까지 반복
   - 길이 가 같다면 지금 leftPointer ~ rightPointer 사이 문자열을 뒤집어서 생각하는 경우인지 확인
   - 뒤집어야 하는 경우, 뒤집었을 때 주어진 문자열과 같은지 확인
   - 뒤집어서 생각하지 않아도 되는 경우 해당 문자열이 주어진 문자열과 같은지 확인
   - 같다면 1, 아니라면 0
