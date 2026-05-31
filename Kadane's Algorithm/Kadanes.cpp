long long maxSubarraySum(vector<int>& a) {
    long long best = a[0], cur = a[0];

    for (int i = 1; i < a.size(); i++) {
        cur = max((long long)a[i], cur + a[i]);
        best = max(best, cur);
    }
    return best;
}