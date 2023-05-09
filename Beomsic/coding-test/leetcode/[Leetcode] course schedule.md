## [leetcode] Course Schedule

[Course Schedule](https://leetcode.com/problems/course-schedule/description/)

### 코드

```java
import java.util.*;

// https://leetcode.com/problems/course-schedule/description/
public class CourseSchedule {

   public boolean canFinish(int numCourses, int[][] prerequisites) {

      List<Integer>[] courses = new List[numCourses];
      // 해당 course를 하기위한 선행 course 개수
      int[] requiredCount = new int[numCourses];
      int count = 0;

      for(int i = 0; i < numCourses; i++) {
         courses[i] = new ArrayList<>();
      }

      for(int[] prerequisite : prerequisites) {
         int course = prerequisite[0];
         int preCourse = prerequisite[1];
         courses[course].add(preCourse);
         requiredCount[preCourse]++;
      }

      Queue<Integer> q = new LinkedList<>();

      for(int i = 0; i < numCourses; i++) {
         if(requiredCount[i] == 0) {
            count++;
            q.add(i);
         }
      }

      while(!q.isEmpty()) {
         int number = q.poll();

         for(int preNumber : courses[number]) {
            requiredCount[preNumber]--;
            if(requiredCount[preNumber] == 0) {
               count++;
               q.add(preNumber);
            }
         }
      }

      if(count == numCourses) return true;
      return false;
   }

}

```

### 📖 해결방법

