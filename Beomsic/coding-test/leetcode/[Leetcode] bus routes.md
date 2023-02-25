## [leetcode] Bus Routes

[Bus Routes](https://leetcode.com/problems/bus-routes/description)

### 코드

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

// https://leetcode.com/problems/bus-routes/description/

public class BusRoute {

  public int numBusesToDestination(int[][] routes, int source, int target) {

    if(source == target) return 0;


    // 정류장을 지나가는 버스 리스트
    // key - 버스 정류장
    // value - 정류장을 지나가는 버스 리스트
    Map<Integer, List<Integer>> busList = new HashMap<>();

    for(int i = 0; i < routes.length; i++) {
      for(int stop : routes[i]) {
        busList.putIfAbsent(stop, new ArrayList<>());
        busList.get(stop).add(i);
      }
    }

    // 위치하고 있는 버스 정류장 큐
    Queue<Integer> busStopQueue = new LinkedList<>();
    // 해당 버스를 탄지 확인
    Set<Integer> visited = new HashSet<>();

    busStopQueue.add(source);

    int busCount = 0;
    while(!busStopQueue.isEmpty()) {
      // 현재 도착한 버스 정류장 개수
      int queueSize = busStopQueue.size();

      for(int i = 0; i < queueSize; i++) {
        // 정류장을 지나는 버스들
        List<Integer> buses = busList.get(busStopQueue.poll());
        for(int bus : buses) {
          // 이미 탄 버스인지 확인
          if(visited.contains(bus)) continue;
          visited.add(bus);
          // 해당 버스에 서는 버스 정류장 확인
          for(int stop : routes[bus]) {
            if(stop == target) return busCount + 1;
            busStopQueue.add(stop);
          }
        }
      }
      busCount++;
    }
    return -1;
  }

}
```

### 📖 해결방법

`BFS`

1. 각 버스 정류장을 지나가는 버스들을 Map을 통해 저장  
2. 현재 도착한 정류장의 번호를 Queue에 저장  
3. Queue에서 정류장 번호를 가져와 해당 정류장을 지나가는 버스들 조사
4. 버스의 route에서 가려고 하는 정류장 번호가 있다면 break
5. Queue에 아무 원소도 없을 때까지 반복