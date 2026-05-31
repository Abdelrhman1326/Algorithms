const int MAXN = 1e7;
vector<int> spf(MAXN + 1);
void gen_spf() {
    // Initialize every number as its own smallest prime factor
    for (int i = 0; i <= MAXN; ++i) {
        spf[i] = i;
    }

    // build spf using sieve:
    for (long long i = 2; i * i <= MAXN; ++i) {
        // if the current number is still prime (not converted by smaller number)
        // then mark all it's multiples as not primes
        // If spf[i] == i, then 'i' is a prime number
        if (spf[i] == i) {
            for (long long j = (i * i); j <= MAXN; j += i) {
                // make sure the spf was processed before
                if (spf[j] == j) {
                    spf[j] = i; // the spf of all multiples is their initial simplest number
                }
            }
        }
    }
}