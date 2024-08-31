void radix_sort(vector<pair<pair<int, int>, int>> &arr) {
	// with radix sort, we actually have to sort by the second element first
	for (int i : vector<int>{2, 1}) {
		auto key = [&](const pair<pair<int, int>, int> &x) {
			return i == 1 ? x.first.first : x.first.second;
		};
		int max = 0;
		for (const auto &i : arr) { max = std::max(max, key(i)); }
		vector<int> occs(max + 1);
		for (const auto &i : arr) { occs[key(i)]++; }
		vector<int> start(max + 1);
		for (int i = 1; i <= max; i++) {
			start[i] = start[i - 1] + occs[i - 1];
		}

		vector<pair<pair<int, int>, int>> new_arr(arr.size());
		for (const auto &i : arr) {
			new_arr[start[key(i)]] = i;
			start[key(i)]++;
		}
		arr = new_arr;
	}
}

str += '$';
const int n = str.size();  // just a shorthand

vector<pair<pair<int, int>, int>> suffs(n);
for (int i = 0; i < n; i++) { suffs[i] = {{str[i], str[i]}, i}; }
std::sort(suffs.begin(), suffs.end());
vector<int> equiv(n);
for (int i = 1; i < n; i++) {
    auto [c_val, cs] = suffs[i];
    auto [p_val, ps] = suffs[i - 1];
    equiv[cs] = equiv[ps] + (c_val > p_val);
}

for (int cmp_amt = 1; cmp_amt < n; cmp_amt *= 2) {
    for (auto &[val, s] : suffs) {
        // the order numbers for the left half and right half respectively
        val = {equiv[s], equiv[(s + cmp_amt) % n]};
    }
    // without the radix sort optimization, we would use `std::sort`
    radix_sort(suffs);

    // assign numbers to the newly sorted suffixes
    for (int i = 1; i < n; i++) {
        auto [c_val, cs] = suffs[i];
        auto [p_val, ps] = suffs[i - 1];
        equiv[cs] = equiv[ps] + (c_val > p_val);
    }
}

for (int i = 1; i < n; i++) {
    cout << suffs[i].second << " \n"[i == n - 1];
}