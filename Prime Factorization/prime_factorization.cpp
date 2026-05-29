// 360 = 2 x 2 x 2 x 3 x 3 x 5
// 360 = pow(2, 3) x pow(3, 2) x pow(5, 1)
// to build a valid devisor of 360, we will choose primes and multiply them together
// Total Number of possible Divisors = (3 + 1) x (2 + 1) x (1 + 1) = 4 * 3 * 2 = 24
// from the first number (2) we can choose 0 or 1 or 2 or 3 = 4 choices = 3 + 1 = power + 1

map<long long, long long> prime_power;
void factorize(long long n) {
    prime_power.clear(); // Clear old data if running multiple testcases

    for (long long i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            count += 1;
            n /= i;
        }
        if (count > 0) {
            prime_power[i] = count;
        }
    }

    if (n > 1) {
        prime_power[n] = 1;
    }
}
