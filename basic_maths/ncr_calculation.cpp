typedef long long ll;

const ll MOD = 1e9 + 7; // Define the modulus
const int MAX = 1e6; // Define the maximum value of n

vector<ll> fact(MAX + 1), inv_fact(MAX + 1);

void factorials() {
    fact[0] = 1;
    for (ll i = 1; i <= MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[MAX] = bin_pow(fact[MAX], MOD - 2, MOD); // Using Fermat's Little Theorem for modular inversion
    for (ll i = MAX - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Binary exponentiation
ll bin_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// nCr calculation using precomputed factorials
ll ncr(int n, int k) {
    if (k > n) return 0;
    return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
}


//call factorials() are preprocess before taking test_cases as input
