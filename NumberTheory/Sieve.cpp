const int N = 1000000;
vector<bool> is_prime(N + 1, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; (long long)(i * i) <= N; i++) {
        if (is_prime[i]) {
            for (int j = (long long)(i * i); j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}