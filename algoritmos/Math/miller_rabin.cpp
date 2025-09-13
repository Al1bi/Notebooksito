using u128 = __uint128_t;
typedef unsigned long long int ull; 

ull binpower(ull base, ull e, ull mod) {
  ull result = 1;
  base %= mod;
  while (e) {
    if (e & 1)
      result = (u128)result * base % mod;
      base = (u128)base * base % mod;
      e >>= 1;
  }
  return result;
}

bool check_composite(ull n, ull a, ull d, int s) {
	ull x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = (u128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
};

bool MillerRabin(ull n) { 
	if (n < 2)
		return false;

	int r = 0;
	ull d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}
	return true;
}