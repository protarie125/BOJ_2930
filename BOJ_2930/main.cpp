#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int r;
string s;
int n;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> r >> s >> n;
	auto vs = vector<string>(n);
	for (auto&& x : vs) {
		cin >> x;
	}

	auto ans1 = int{ 0 };
	auto ans2 = int{ 0 };

	for (auto i = 0; i < r; ++i) {
		auto ps = vi(3, 0);

		for (auto j = 0; j < n; ++j) {
			if ('R' == vs[j][i]) {
				ps[0] += 1;
				ps[1] += 2;
			}
			else if ('P' == vs[j][i]) {
				ps[1] += 1;
				ps[2] += 2;
			}
			else if ('S' == vs[j][i]) {
				ps[2] += 1;
				ps[0] += 2;
			}
		}

		if ('R' == s[i]) {
			ans1 += ps[0];
		}
		else if ('P' == s[i]) {
			ans1 += ps[1];
		}
		else if ('S' == s[i]) {
			ans1 += ps[2];
		}

		ans2 += *max_element(ps.begin(), ps.end());
	}

	cout << ans1 << '\n' << ans2;

	return 0;
}