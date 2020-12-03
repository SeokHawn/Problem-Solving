#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, e[500][500], sx, sy,res,dir_x[] = { -1,0,1,0 },
dir_y[] = { 0,1,0,-1 }; // 좌 하 우 상

bool isrange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

void cal(int x, int y, int dir) {

	int nx = x + dir_x[dir] * 2, // 5%
		ny = y + dir_y[dir] * 2;
	int sum = 0;
	int adder = e[y][x] / 20;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}

	nx = x + dir_x[dir] + dir_x[(dir + 4 - 1) % 4],	//이전 dir
		ny = y + dir_y[dir] + dir_y[(dir + 4 - 1) % 4];
	adder = e[y][x] / 10;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}

	nx = x + dir_x[dir] + dir_x[(dir + 1) % 4];
	ny = y + dir_y[dir] + dir_y[(dir + 1) % 4];
	adder = e[y][x] / 10;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}


	nx = x + dir_x[(dir + 4 - 1) % 4],
		ny = y + dir_y[(dir + 4 - 1) % 4];
	adder = e[y][x] * 7 / 100;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}

	nx = x + dir_x[(dir + 1) % 4],
		ny = y + dir_y[(dir + 1) % 4];
	adder = e[y][x] * 7 / 100;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}


	nx = x + dir_x[(dir + 4 - 1) % 4]*2,
		ny = y + dir_y[(dir + 4 - 1) % 4]*2;
	adder = e[y][x] / 50;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}

	nx = x + dir_x[(dir + 1) % 4]*2,
		ny = y + dir_y[(dir + 1) % 4]*2;
	adder = e[y][x]/ 50;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}

	nx = x + dir_x[(dir + 2) % 4] + dir_x[(dir + 1) % 4];
	ny = y + dir_y[(dir + 2) % 4] + dir_y[(dir + 1) % 4];
	adder = e[y][x] / 100;
	sum += adder;
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}
	nx = x + dir_x[(dir + 2) % 4] + dir_x[(dir + 4 - 1) % 4];
	ny = y + dir_y[(dir + 2) % 4] + dir_y[(dir + 4 - 1) % 4];
	adder = e[y][x] / 100;
	sum += adder; 
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}


	adder = e[y][x] - sum;
	nx = x + dir_x[dir],
		ny = y + dir_y[dir];
	if (isrange(nx, ny)) {
		e[ny][nx] += adder;
	}
	else {
		res += adder;
	}

}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	sx = sy = N / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> e[i][j];
		}
	}
	int d = 0,cnt =0, tmp=1;
	while (isrange(sx, sy)) {

		for (int i = 0; i < tmp; i++) {
			sx += dir_x[d],
			sy += dir_y[d];
			cal(sx, sy,d);
		}
		d = (d + 1) % 4;
		cnt++;
		if (tmp < N-1 && cnt == 2) {
			tmp++;
			cnt = 0;
		}
		if (!sx && !sy)
			break;
	}

	cout << res;

	return 0;
}