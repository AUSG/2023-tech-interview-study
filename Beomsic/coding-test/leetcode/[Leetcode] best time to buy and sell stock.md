## [leetcode] Best time to buy and sell stock

[Best time to buy and sell stock]( https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### 코드

```java
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
public class BestTimeToBuyAndSellStock {

  public int maxProfit(int[] prices) {
    int[] maxPrice = new int[prices.length];
    int answer = 0;

    maxPrice[prices.length - 1] = prices[prices.length - 1];

    for(int i = prices.length - 2; i >= 0; i--) {
      int price = prices[i];
      int profit = maxPrice[i + 1] - price;
      maxPrice[i] = Math.max(maxPrice[i + 1], price);
      answer = Math.max(answer, profit);
    }

    return answer;
  }

}
```

### 📖 해결방법

`DP`

1. 마지막 인덱스부터 반복문을 돌며 비싸게 팔 수 있는 max 값을 구한다. 
   - maxPrice[i] = Math.max(maxPrice[i + 1], price);
2. 반복문에서 해당 인덱스에서 주식을 샀을 때 팔 수 있는 이익과 지금껏 구한 최대 이익을 비교한다.
   - answer = Math.max(answer, profit);