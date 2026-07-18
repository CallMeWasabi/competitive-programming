#include <iostream>

const long long MOD = 1e9 + 7; // 1000000007

// Fast binary exponentiation: (base^exp) % MOD
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % MOD; // __int128 prevents overflow during multiplication
        base = (__int128)base * base % MOD;
        exp /= 2;
    }
    return res;
}

// Modular inverse using Fermat's Little Theorem
long long modInverse(long long b) {
    return power(b, MOD - 2);
}

// Final function: (a / b) % MOD
long long modFraction(long long a, long long b) {
    // 1. Bring 'a' into the safe [0, MOD-1] range
    a = (a % MOD + MOD) % MOD;

    // 2. Safely fetch the inverse of the denominator
    long long inv = modInverse(b);

    // 3. Return the modular multiplication
    return (__int128)a * inv % MOD;
}

int main() {
    long long numerator = -1;
    long long denominator = 3;

    // Calculates (-1 / 3) % (1e9 + 7)
    std::cout << "Result: " << modFraction(numerator, denominator) << std::endl;
    return 0;
}
