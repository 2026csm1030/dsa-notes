# Alog | Mtech

0/1 Knapsack

```cpp
int f(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        } 
        else
        {
            return 0;
        }
    }
    
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    
    // not take
    int not_taken = 0 + f(i - 1, W, val, wt, dp);
    
    int taken = 0;
    
    if (wt[i] <= W)
    {
        taken = val[i] + f(i - 1, W - wt[i], val, wt, dp);
    }
    
    dp[i][W] = max(not_taken, taken);
    return dp[i][W];
}

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        return f(n - 1, W, val, wt, dp);
    }
};
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: First item
    for (int w = wt[0]; w <= W; w++)
    {
        dp[0][w] = val[0];
    }

    // Build DP table
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // Not take
            int not_taken = dp[i - 1][w];

            // Take
            int taken = 0;

            if (wt[i] <= w)
            {
                taken = val[i] + dp[i - 1][w - wt[i]];
            }

            dp[i][w] = max(not_taken, taken);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};

    int W = 6;

    cout << knapsack(W, val, wt) << endl;

    return 0;
}
```

---

Matrix Chain Multiplication

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int f(int i, int j, vector<int> &p)
{
    // Base case
    if (i == j)
        return 0;

    int mini = INT_MAX;

    // Try every partition
    for (int k = i; k < j; k++)
    {
        int steps = (p[i - 1] * p[k] * p[j])
                    + f(i, k, p)
                    + f(k + 1, j, p);

        mini = min(mini, steps);
    }

    return mini;
}

int main()
{
    vector<int> p = {10, 20, 30, 40};

    int n = p.size() - 1;

    cout << f(1, n, p) << endl;

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int matrixChain(vector<int> &p)
{
    int n = p.size() - 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int mini = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int steps = (p[i - 1] * p[k] * p[j])
                            + dp[i][k]
                            + dp[k + 1][j];

                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n];
}

int main()
{
    vector<int> p = {10, 20, 30, 40};

    cout << matrixChain(p) << endl;

    return 0;
}
```

---

Rod Cutting

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int f(int i, vector<int> &prices, int N)
{
  if (i == 0)
  {
    return N * prices[0];
  }

  int not_take = 0 + f(i - 1, prices, N);
  int take = 0;

  int rod_length = i + 1;

  if (rod_length <= N)
  {
    take = prices[i] + f(i, prices, -rod_length);
  }

  return max(not_take, take);
}

int main()
{

  vector<int> prices = {1, 2, 3, 4};
  int N = 4;

  int n = prices.size();

  int res = f(n, prices, N);
  cout << res << endl;

  return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rodCutting(vector<int> &price, int N)
{
    int n = price.size();

    vector<vector<int>> dp(n, vector<int>(N + 1, 0));

    // Base case
    for (int len = 0; len <= N; len++)
    {
        dp[0][len] = len * price[0];
    }

    // Build DP table
    for (int i = 1; i < n; i++)
    {
        for (int len = 0; len <= N; len++)
        {
            // Not take
            int not_taken = dp[i - 1][len];

            // Take
            int taken = 0;

            int rodLength = i + 1;

            if (rodLength <= len)
            {
                taken = price[i] + dp[i][len - rodLength];
            }

            dp[i][len] = max(not_taken, taken);
        }
    }

    return dp[n - 1][N];
}

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};

    int N = price.size();

    cout << rodCutting(price, N) << endl;

    return 0;
}
```

---

Longest Common Subsequence

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int f(int i1, int i2, string s1, string s2, vector<vector<int>> &dp)
{

  if (i1 == 0 || i2 == 0)
  {
    return 0;
  }

  if (dp[i1][i2] != -1)
  {
    return dp[i1][i2];
  }

  if (s1[i1] == s2[i2])
  {
    return 1 + f(i1 - 1, i2 - 1, s1, s2, dp);
  }

  dp[i1][i2] = max(f(i1 - 1, i2, s1, s2, dp), f(i1, i2 - 1, s1, s2, dp));
  return dp[i1][i2];
}

int bottom_f(int i1, int i2, string s1, string s2)
{
  vector<vector<int>> dp(i1 + 1, vector<int>(i2 + 1, 0));

  for (int i = 0; i < i1; i++)
    dp[i][0] = 0;

  for (int j = 0; j < i2; j++)
    dp[0][j] = 0;

  for (int i = 1; i <= i1; i++)
  {
    for (int j = 1; j <= i2; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[i1][i2];
}

int main()
{
  // s1 = "ABCDGH", s2 = "AEDFHR"

  string s1 = "ABCDGH";
  string s2 = "AEDFHR";

  int i1 = s1.size();
  int i2 = s2.size();

  // vector<vector<int>> dp(i1 + 1, vector<int>(i2 + 1, -1));

  // int res = f(i1, i2, s1, s2, dp);
  // cout << res << endl;

  int res = bottom_f(i1, i2, s1, s2);
  cout << res << endl;

  return 0;
}

```

---

Print Longest Common Subsequence

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string printLCS(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // Build DP table
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // Backtracking to print LCS
  int i = n;
  int j = m;

  string ans = "";

  while (i > 0 && j > 0)
  {
    if (s1[i - 1] == s2[j - 1])
    {
      ans += s1[i - 1];

      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }

  reverse(ans.begin(), ans.end());

  return ans;
}

int main()
{
  string s1 = "abcde";
  string s2 = "ace";

  cout << printLCS(s1, s2) << endl;

  return 0;
}
```

---

Longest Common Substring

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestCommonSubstring(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];

        ans = max(ans, dp[i][j]);
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }

  return ans;
}

int main()
{
  string s1 = "abcde";
  string s2 = "abfde";

  cout << longestCommonSubstring(s1, s2) << endl;

  return 0;
}
```

---

Subset Sum Equals to K

```cpp
bool f(int i, int target, vector<int> &arr,
       vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (i == 0)
        return arr[0] == target;

    if (dp[i][target] != -1)
        return dp[i][target];

    bool not_taken = f(i - 1, target, arr, dp);

    bool taken = false;

    if (arr[i] <= target)
    {
        taken = f(i - 1, target - arr[i], arr, dp);
    }

    return dp[i][target] = taken || not_taken;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 6;

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    bool ans = f(n - 1, k, arr, dp);

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: Target 0 is always possible
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // Base case: First element
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }

    // Build DP table
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            // Not take
            bool not_taken = dp[i - 1][target];

            // Take
            bool taken = false;

            if (arr[i] <= target)
            {
                taken = dp[i - 1][target - arr[i]];
            }

            dp[i][target] = taken || not_taken;
        }
    }

    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 6;

    bool ans = subsetSum(arr, k);

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
```