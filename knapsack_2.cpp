#include <iostream>
#include <vector>
 
long dp[101][100001];

const int INF = 1e9+7;
/*
 *	dp[i][j] = min total weight of items with value i
 */
 
long knap_value(int N, int V, int W, const std::vector<int>& w, const std::vector<int>& c)
{
	// dp[0][0] = no items, min weight with value equal to zero
	
	for (int j = 1; j <= V; j++)
		dp[0][j] = INF;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (j >= c[i])
				dp[i][j] = std::min(dp[i-1][j], w[i] + dp[i-1][j - c[i]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	long ans = 0;

	for (int i = V; i >= 0; i--)
	{
		if (dp[N][i] <= W)
		{
			ans = i;
			break;
		}
	}
	
	return ans;
}
 
int main() {
	int N, W; std::cin >> N >> W;
	
	std::vector<int> w(N+1), c(N+1);

	int value_sum = 0;
	
	for (int i = 1; i <= N; i++)
	{
		std::cin >> w[i] >> c[i];

		value_sum += c[i];
	}
	
	long ans = knap_value(N, value_sum, W, w, c);

	std::cout << ans << "\n";
}
