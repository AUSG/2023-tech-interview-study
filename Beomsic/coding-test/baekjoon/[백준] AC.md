[백준] AC [5430번]

**문자열**

[AC](https://www.acmicpc.net/problem/5430)

### 코드
```java
// https://www.acmicpc.net/problem/5430
public class AC {

   private static final Character REVERSE = 'R';
   private static final Character DELETE = 'D';

   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      StringTokenizer st = new StringTokenizer(br.readLine());

      int T = Integer.parseInt(st.nextToken());

      for(int testcase = 0; testcase < T; testcase++) {

         st = new StringTokenizer(br.readLine());

         String commands = st.nextToken();

         st = new StringTokenizer(br.readLine());
         int size = Integer.parseInt(st.nextToken());

         st = new StringTokenizer(br.readLine());
         String inputStr = st.nextToken();
         String[] arrayStr = inputStr.substring(1, inputStr.length() - 1).split(",");

         boolean isError = false;
         boolean isReverse = false;
         int lPoint = 0;
         int rPoint = size - 1;
         int deleteCount = 0;

         for(int i = 0; i < commands.length(); i++) {

            char command = commands.charAt(i);

            if(command == REVERSE) isReverse = !isReverse;

            if(command == DELETE) {

               if(deleteCount == size) {
                  isError = true;
                  break;
               }
               if(!isReverse) lPoint++;
               else rPoint--;
               deleteCount++;
            }
         }

         if(isError) bw.write("error");

         else {
            StringBuilder sb = new StringBuilder();

            sb.append("[");

            if(lPoint <= rPoint) {
               if(!isReverse) {
                  for(int i = lPoint; i < rPoint; i++) {
                     sb.append(arrayStr[i]);
                     sb.append(",");
                  }
                  sb.append(arrayStr[rPoint]);
               }

               else {
                  for(int i = rPoint; i > lPoint; i--) {
                     sb.append(arrayStr[i]);
                     sb.append(",");
                  }
                  sb.append(arrayStr[lPoint]);
               }
            }
            sb.append("]");


            bw.write(sb.toString());
         }
         bw.newLine();
      }
      bw.flush();
      bw.close();
      br.close();

   }

}
```

### 📖 해결방법

`문자열`  

1. 명령 문자열의 길이만큼 반복문을 돈다.
2. 명령어가 R인 경우 현재 문자열이 뒤집혀있는지 확인하는 변수 isReverse 의 값을 반대로 바꿔준다.
3. 명령어가 D인경우 
   - isReverse 가 참일 때, 입력한 문자열의 뒷부분을 제거 (뒤집힌 경우)
   - isReverse 가 거짓일 때, 입력한 문자열의 앞부분을 제거 (원래 순서인 경우)
   - 제거하는 대신 Pointer를 사용해서 이동했음.
   - 제거를 할 문자가 없는 경우 -> error를 체크해주는 변수 갱신 + break
4. 남은 문자열 출력(에러인 경우 error 출력)