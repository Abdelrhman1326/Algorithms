### Problem link: https://codeforces.com/contest/1692/problem/H

---

## H. Gambling
**Time limit per test:** 2 seconds  
**Memory limit per test:** 256 megabytes

---

## Problem Statement

Marian is at a casino. The game works as follows:

Before each round, the player selects a number `a` between `1` and `10^9`. After that, a dice with `10^9` faces is rolled, producing a random number between `1` and `10^9`.

- If the player guesses the number correctly, their total money is **doubled**.
- Otherwise, their total money is **halved**.

Marian knows the future outcomes of the dice rolls:
`z1, z2, ..., zn`.

He chooses integers `l` and `r` such that `1 ≤ l ≤ r ≤ n`, and plays rounds from `l` to `r` inclusive.

In each of these rounds, he guesses the same number `a`.

At the start (before round `l`), he has **1 dollar**.

---

## Task

Determine the integers `l`, `r`, and `a` such that Marian ends with the **maximum possible amount of money** after playing the chosen segment.

If there are multiple optimal answers, you may output any of them.

---

## Notes

- During the game, the money is always of the form:
  \[
  2^k \quad \text{for some integer } k
  \]
- No floating-point precision issues exist.

---

## Input

- The first line contains an integer `t` (`1 ≤ t ≤ 100`) — number of test cases.
- For each test case:
    - First line: integer `n` (`1 ≤ n ≤ 2 × 10^5`)
    - Second line: `n` integers `z1, z2, ..., zn` (`1 ≤ zi ≤ 10^9`)

It is guaranteed that the sum of `n` over all test cases does not exceed `2 × 10^5`.

---

## Output

For each test case, output three integers:

`l r a`

---

## Example

### Input
```
4
5
4 4 3 4 4
5
11 1 11 1 11
1
1000000000
10
8 8 8 9 9 6 6 9 6 6
```
### Output
```
4 1 5
1 2 2
1000000000 1 1
6 6 10
```

## Solution:
``` c++
#include <bits/stdc++.h>
using namespace std;

#define AbdElrhmanMO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    int best_l = 0, best_r = 0, best_num = arr[0];
    int best_res = INT_MIN;

    for (auto& [num, vec] : mp) {
        vector<int> the_full_vector(n, -1);

        for (int idx : vec)
            the_full_vector[idx] = 1;

        auto [res, l, r] = maxSubarraySum(the_full_vector);

        if (res > best_res) {
            best_res = res;
            best_num = num;
            best_l = l;
            best_r = r;
        }
    }

    cout << best_num << ' ' << best_l + 1 << ' ' << best_r + 1 << '\n';
}

int main() {
    AbdElrhmanMO
    int t;
    cin >> t;
    while (t--) solve();
}
```



## More Optimal Solution:

``````c++
#include <bits/stdc++.h>
using namespace std;

#define AbdElrhmanMO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

tuple<int,int,int> maxSubarraySum(vector<int> &arr) {
    int n = arr.size();

    int maxEnding = 1;
    int res = 1;

    int cur_l = arr[0];
    int best_l = arr[0], best_r = arr[0];

    for (int i = 1; i < n; i++) {
        int gap = arr[i] - arr[i - 1] - 1;
        int delta = +1 - gap; // the score increases by one and decreases by the gap size * -1 = -gap

        if (1 > maxEnding + delta) {
            maxEnding = 1;
            cur_l = arr[i];
        } else {
            maxEnding += delta;
        }

        if (maxEnding > res) {
            res = maxEnding;
            best_l = cur_l;
            best_r = arr[i];
        }
    }

    return {res, best_l, best_r};
}

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    int best_l = 0, best_r = 0, best_num = arr[0];
    int best_res = INT_MIN;

    for (auto& [num, vec] : mp) {
        auto [res, l, r] = maxSubarraySum(vec);

        if (res > best_res) {
            best_res = res;
            best_num = num;
            best_l = l;
            best_r = r;
        }
    }

    cout << best_num << ' ' << best_l + 1 << ' ' << best_r + 1 << '\n';
}

int main() {
    AbdElrhmanMO
    int t;
    cin >> t;
    while (t--) solve();
}

``````

