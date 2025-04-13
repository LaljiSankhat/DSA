string num = to_string(n);
    int m = num.length();

    vector<vector<int>> dp(m + 1, vector<int>(2, -1)); // dp array to store results for memoization

    return solve(num, 0, 1, digits, dp) - 1;