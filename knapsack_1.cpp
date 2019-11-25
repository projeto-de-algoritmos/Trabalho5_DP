#include <iostream>
#include <vector>
 
long dp[101][100001];
 
long knap(int N, int W, const std::vector<int>& w, const std::vector<int>& c)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (i == 0 or j == 0)
				dp[i][j] = 0;
			else if (j >= w[i])
				dp[i][j] = std::max(dp[i-1][j], c[i] + dp[i-1][j - w[i]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[N][W];
}
 
int main() {
	int N, W; std::cin >> N >> W;
	
	std::vector<int> w(N+1), c(N+1);
	
	for (int i = 1; i <= N; i++)
	{
		std::cin >> w[i] >> c[i];
	}
	
	long ans = knap(N, W, w, c);
	
	std::cout << ans << "\n";
}
