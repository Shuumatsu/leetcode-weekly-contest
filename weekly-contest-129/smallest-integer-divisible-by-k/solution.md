Obviously if $K$ is the multiple of 2 or multiple of 5, return -1.

Considering the time complexity and overflow, we cannot just check every n.
For every n not divisible by K, it must has the form $n = mk+h$. The next will be $n_{next}=10 n+1=10 m k+10 h+1$ is divisible iff $10h + 1$ is divisible. So we just need to check the remainder and hence the dividend is gurrented not greater than $10 (k - 1)$.

And then we should decide when to stop our checking process. The answer is the first $k$ $n$ must at least have one divisible.

Use counterevidence here. Assume all of the first k are not divisible. Then the remainder of them must be within [1, k-1], so at least two have same remainder $h$. Let's denote them as $n_i = ak + h$ and $n_j = bk + h$ ($i < j$.

$n_{j-i} \times 10^i = n_j - n_i = (b-a)k$ which is divisible. So $n_{j-i}$ is divisible, here leads a contradiction.

```
class Solution {
  public:
    int smallestRepunitDivByK(int k) {
        auto length = 1;
        auto n = 1;
        while (length <= k) {
            auto h = n % k;
            if (h == 0) {
                return length;
            }
            length += 1;
            n = 10 * h + 1;
        }

        return -1;
    }
};
```
