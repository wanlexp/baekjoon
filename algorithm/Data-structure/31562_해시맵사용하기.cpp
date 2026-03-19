#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
	int song, n, trash;
	string sname;
	char sk;
	string skey = "";
	unordered_map<string, string> songlist;
	cin >> song >> n;
	for (int i = 0; i < song; i++) {
		skey = "";
		cin >> trash >> sname;
		cin >> sk; skey += sk; cin >> sk; skey += sk; cin >> sk; skey += sk;
		cin >> sk >> sk >> sk >> sk; //뒤에 쓰래기값 버리기
		if (!songlist.count(skey)) {
			songlist.insert({ skey, sname });
		}
		else {
			songlist[skey] = "?";
		}
	}
	for (int j = 0; j < n; j++) {
		skey = "";
		cin >> sk; skey += sk; cin >> sk; skey += sk; cin >> sk; skey += sk;
		if (songlist.count(skey)) {
			cout << songlist[skey] << '\n';
		}
		else {
			cout << "!" << '\n';
		}
	}
	return 0;
}