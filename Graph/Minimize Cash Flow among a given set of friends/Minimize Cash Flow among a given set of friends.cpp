/* Given a number of friends who have to give or take some amount of money from one another. Design an algorithm by 
which the total cash flow among all the friends is minimized. */

#include <iostream>
#include <algorithm>
#include <set>
#include <utility>

#define N 3

// Method 1. Recursive
/*
void minCashFlowRecur(int amount[])
{
	// amount[maxCreditIndex] indicates the maximum amount to be given (or credited) to any person .
	// And amount[maxDebitIndex] indicates the maximum amount to be taken (or debited) from any person.
	int maxCreditIndex = std::distance(amount, std::max_element(amount, amount + N));
	int maxDebitIndex = std::distance(amount, std::min_element(amount, amount + N));

	// If both amounts are 0, then all amounts are settled
	if (amount[maxCreditIndex] == 0 && amount[maxDebitIndex] == 0)
	{
		return;
	}

	int min = std::min(abs(amount[maxDebitIndex]), amount[maxCreditIndex]);
	amount[maxCreditIndex] -= min;
	amount[maxDebitIndex] += min;

	std::cout << "Person " << maxDebitIndex << " pays " << min << " to " << "Person " << maxCreditIndex << std::endl;
	minCashFlowRecur(amount);

}

void minCashFlow(int graph[][N])
{
	int amount[N] = { 0 };

	// Calculate the net amount to be paid to person 'p', and
	// stores it in amount[p]. The value of amount[p] can be
	// calculated by subtracting debts of 'p' from credits of 'p'
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			amount[i] += (graph[j][i] - graph[i][j]);
		}
	}
	minCashFlowRecur(amount);
} */

// Method 2. Iterative using multiset
void minCashFlow(int graph[][N])
{
	int amount[N] = { 0 };

	// Calculate the net amount to be paid to person 'p', and
	// stores it in amount[p]. The value of amount[p] can be
	// calculated by subtracting debts of 'p' from credits of 'p'
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			amount[i] += (graph[j][i] - graph[i][j]);
		}
	}

	std::multiset<std::pair<int, int>> S;
	for (int i = 0; i < N; i++)
		if (amount[i] != 0) 
			S.insert({ amount[i], i });

	while (!S.empty())
	{
		auto maxDebit = *S.begin(); S.erase(S.begin());
		auto maxCredit = *S.rbegin(); S.erase(prev(S.end()));

		int min = std::min(abs(maxDebit.first), maxCredit.first);

		std::cout << "Person " << maxDebit.second << " pays " << min << " to " << "Person " << maxCredit.second << std::endl;
		maxDebit.first += min;
		maxCredit.first -= min;

		if (maxDebit.first)
			S.insert(maxDebit);
		if (maxCredit.first)
			S.insert(maxCredit);
	}
}

int main()
{
    // graph[i][j] indicates the amount that person i needs to pay person j
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0,    5000},
                        {0, 0,    0}, };

    minCashFlow(graph);
    return 0;
}


