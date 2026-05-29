// A x B = GCD(A, B) x LCM(A, B)
// LCM(A, B) = (A x B) / GCD(A, B)

long long lcm(long long a, long long b) {
    return (a / std::gcd(a, b)) * b;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
