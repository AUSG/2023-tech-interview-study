## [leetcode] Best time to buy and sell stock

[Best time to buy and sell stock]( https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### μ½λ

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

### πΒ ν΄κ²°λ°©λ²

`DP`

1. λ§μ§λ§ μΈλ±μ€λΆν° λ°λ³΅λ¬Έμ λλ©° λΉμΈκ² ν μ μλ max κ°μ κ΅¬νλ€. 
   - maxPrice[i] = Math.max(maxPrice[i + 1], price);
2. λ°λ³΅λ¬Έμμ ν΄λΉ μΈλ±μ€μμ μ£Όμμ μμ λ ν μ μλ μ΄μ΅κ³Ό μ§κΈκ» κ΅¬ν μ΅λ μ΄μ΅μ λΉκ΅νλ€.
   - answer = Math.max(answer, profit);