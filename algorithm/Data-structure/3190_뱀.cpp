#include<iostream>
#include<vector>
#include<deque>
/*구현 시뮬레이션 문제, 방향백터로 뱀의 방향을 조정하고, 뱀의 위치와 맵의 표시등 설정해야할 변수가 많음
* 또한 이런 문제에서 가장 중요한 점은 치밀한 조건만족과 세세하게 문제를 읽어 보는 것임.
* 가령 행렬이 0,0 시작인지 1,1시작인지 등등, 조건을 미리 정확하게 메모해두면 구현하는것 자체는
* 그리 어렵지 않음.
*/
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k, l,m,index=0;// n*n행렬 , k 사과 개수, l 행동 횟수
	int time = 0, row, col;
	char c; //명령
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n, 0));
	deque <pair<int, int>> snack; //뱀의 좌표를 저장
	vector<pair<int, char>> command;;
	snack.push_back({ 0,0 });
	int dx[] = {0,1,0,-1}; //방향 백터 
	int dy[] = {1,0,-1,0};
	int current_dir = 0;
	cin >> k;
	for (int i = 0; i < k; i++) { //사과를 맵에 저장
		cin >> row >> col;
		map[row-1][col-1] = 2; //사과는 2
	}
	cin >> l;
	for (int i = 0; i < l; i++) { //명령을 저장
		cin >> m >> c;
		command.push_back({ m,c });
	}
	 
	map[0][0] = 1; //뱀은 1;
	row = 0;
	col = 0;
	while (true) {
		++time;
		row += dx[current_dir]; col += dy[current_dir];
		snack.push_back({ row,col }); //뱀을 방향에 맞게 이동
		if ((row < 0 || col < 0) || (row >= n || col >= n) || map[row][col] == 1)// 이동한 곳이 벽 or 몸통
		{
			cout << time;
			return 0;

		}
		else if (map[row][col] == 2) { //이동한 곳에 사과가 있음
			map[row][col] = 1;
		}
		else { //이동한 곳이 아무 문제도 없고 사과도 없음
			map[row][col] = 1;
			map[snack.front().first][snack.front().second] = 0;
			snack.pop_front();
		}
		if ( index < l && time == command[index].first) {
			//이제 명령을 수행해야할 시간이 됨.
			if (command[index].second == 'L') { //왼쪽으로 방향전환
				current_dir = (current_dir + 3) % 4; 
				index++;

			}
			else if (command[index].second == 'D') { //오른쪽으로 방향전환
				current_dir = (current_dir + 1) % 4;
				index++;
			}
		}
	}
	return 0;
}