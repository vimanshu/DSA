

#include <bits/stdc++.h>

using namespace std;
int
knapsack (int n, vector < int >&wt, vector < int >&pt,
	  vector < vector < int >>&dp, int kpwt)
{
  if (n == 0)
    {
      return 0;
    }
  else if (dp[n][kpwt] != -1)
    {
      return dp[n][kpwt];
    }
  else
    {
      if (wt[n - 1] <= kpwt)
	{
	  //accept and do not accept ka max
	  dp[n][kpwt] =
	    max (knapsack (n - 1, wt, pt, dp, kpwt - wt[n - 1]) + pt[n - 1],
		 knapsack (n - 1, wt, pt, dp, kpwt));
	  return dp[n][kpwt];
	}
      else
	dp[n][kpwt] = knapsack (n - 1, wt, pt, dp, kpwt);
      return dp[n][kpwt];
    }
}

int
main ()
{
  int t;
  cin >> t;
  int kpwt;
  cin >> kpwt;
  vector < int >wt;
  vector < int >pt;

  vector < vector < int >>dp (t + 1, vector < int >(kpwt + 1, -1));
  for (int i = 0; i < t; i++)
    {
      int x;
      int y;
      cin >> x;
      cin >> y;
      wt.push_back (x);

      pt.push_back (y);

    }

  cout << knapsack (t, wt, pt, dp, kpwt);
  return 0;
}
