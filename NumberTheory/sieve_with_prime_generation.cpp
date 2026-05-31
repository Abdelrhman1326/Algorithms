const int N = 1000000;
vector<bool> is_prime(N + 1, true);
vector<int> prime_numbers;
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime_numbers.push_back(i);

            if (1LL * i * i <= N) {
                for (int j = i * i; j <= N; j += i)
                    is_prime[j] = false;
            }
        }
    }
}