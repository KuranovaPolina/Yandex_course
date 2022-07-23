#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ACs() {
	int t_room, t_cond;
	string mode;

	cin >> t_room >> t_cond >> mode;

	if (mode == "freeze") {
		cout << min(t_room, t_cond);
	}

	else if (mode == "heat") {
		cout << max(t_room, t_cond);
	}

	else if (mode == "auto") {
		cout << t_cond;
	}

	else if (mode == "fan") {
		cout << t_room;
	}
}

void Triangle() {
	int l1, l2, l3;

	cin >> l1 >> l2 >> l3;

	if ((l1 + l2) > l3 && (l1 + l3) > l2 && (l3 + l2) > l1) {
		cout << "YES";
	}

	else cout << "NO";
}

void Phone_numbers() {
	vector<char> new_line;

	char c;
	while (cin.get(c)) {
		if (c == '\n')
			break;
		else if (c != '+' && c != '(' && c != ')' && c != '-')
			new_line.push_back(c);
	}

	if (new_line.size() == 7) {
		new_line.insert(new_line.begin(), { '8', '4', '9', '5' });
	}
	else new_line[0] = '8';


	for (int i = 0; i < 3; i++) {
		vector<char> tmp;

		char c_tmp;
		while (cin.get(c_tmp)) {
			if (c_tmp == '\n')
				break;
			else if (c_tmp != '+' && c_tmp != '(' && c_tmp != ')' && c_tmp != '-')
				tmp.push_back(c_tmp);
		}

		if (tmp.size() == 7) {
			tmp.insert(tmp.begin(), { '8', '4', '9', '5' });
		}
		else tmp[0] = '8';

		if (tmp == new_line) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}

void Equation_with_root() {
	int a, b, c;

	cin >> a >> b >> c;

	if (c < 0) cout << "NO SOLUTION";
	else if ((a + b) == c * c && (2 * a + b) == c * c) cout << "MANY SOLUTIONS";
	else {
		if (a != 0 && (c * c - b) % a == 0) cout << (c * c - b) / a;
		else cout << "NO SOLUTION";
	}
}

void Ambulance() {

}

void Laptops_install() {
	int x, y, z, d;

	cin >> x >> y >> z >> d;

	int a = y + d, b = max(x, z), S = a * b;

	if ((x + d) * max(y, z) < S) {
		a = x + d;
		b = max(y, z);
		S = a * b;
	}

	if ((y + z) * max(x, d) < S) {
		a = y + z;
		b = max(x, d);
		S = a * b;
	}

	if ((x + z) * max(y, d) < S) {
		a = x + z;
		b = max(y, d);
	}

	cout << a << " " << b;
}

void Details() {
	int N, K, M, count = 0;
	cin >> N >> K >> M;

	if (K >= M) {
		while (N >= K) {
			count += (N / K) * (K / M);
			N = (N % K) + (K % M) * (N / K);
		}
	}

	cout << count;
}

void Metro() {
	int a, b, n, m, min0, max0;
	cin >> a >> b >> n >> m;

	min0 = max((n - 1) * a + n, (m - 1) * b + m);
	max0 = min((n + 1) * a + n, (m + 1) * b + m);

	if (min0 <= max0) cout << min0 << " " << max0;
	else cout << -1;
}

void IF_prisoner() {
	int A, B, C, D, E;

	cin >> A >> B >> C >> D >> E;

	if (A <= D && B <= E || A <= E && B <= D) cout << "YES";
	else if (C <= D && B <= E || C <= E && B <= D) cout << "YES";
	else if (C <= D && A <= E || C <= E && A <= D) cout << "YES";
	else cout << "NO";
}

void SLE() {
	float a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
		cout << 5;
	}

	else if ((a * d == b * c && a * f != c * e) ||
		(a == 0 && b == 0 && e != 0) ||
		(c == 0 && d == 0 && f != 0) ||
		(a == 0 && c == 0 && b * f != d * e) ||
		(b == 0 && d == 0 && a * f != c * e)) {
		cout << 0;
	}

	else if (a * d == b * c && a * f == c * e) {
		if (b == 0 && d == 0) {
			if (a != 0) cout << 3 << " " << e / a;
			else if (c != 0) cout << 3 << " " << f / c;
		}

		else if (a == 0 && c == 0) {
			if (b != 0) cout << 4 << " " << e / b;
			else if (d != 0) cout << 4 << " " << f / d;
		}

		else if (b != 0) cout << 1 << " " << -a / b << " " << e / b;
		else cout << 1 << " " << -c / d << " " << f / d;
	}

	else {
		float x = (e * d - b * f) / (a * d - b * c);
		float y = (a * f - e * c) / (a * d - b * c);
		cout << 2 << " " << x << " " << y;
	}
}