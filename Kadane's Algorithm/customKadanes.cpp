// a custom version for getting the subarray l and r too!

tuple<int,int,int> maxSubarraySum(vector<int> &arr) {
    int n = arr.size();

    int maxEnding = arr[0];
    int res = arr[0];

    int cur_l = 0;
    int best_l = 0, best_r = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxEnding + arr[i]) {
            maxEnding = arr[i];
            cur_l = i;
        } else {
            maxEnding += arr[i];
        }

        if (maxEnding > res) {
            res = maxEnding;
            best_l = cur_l;
            best_r = i;
        }
    }

    return {res, best_l, best_r};
}