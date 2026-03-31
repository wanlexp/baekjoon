#include <iostream>
#include <vector>
#include <numeric> // iota 사용을 위해

using namespace std;

/*유니온 파인드는 트리구조로 되어있고 두 트리를 합칠 때 A의 루트와 B의 루트를 합치는 방식으로 진행된다
A와 B중 높이가 더 낮은 트리가 자식으로 들어가며, 이떄 높은 쪽 루트의 자식으로 들어간다
유니온 파인드는 이진트리가 아니므로 무한한 수의 자식을 가질 수 있고 트리의 병합도 이와같이 자식이 +1되는
형태로 진행되며 이떄 기존트리의 원소와 섞이거나 하는 것이 아닌 그대로 옆으로 커지는 모양이다.
FIND를 할때마다 해당 원소는 부모와의 연결을 끊고 루트와 직접연결되며 이것이 다음 탐색에서 단 한번의 연산으로
루트를 찾을 수 있게 하는 방법이 된다.
이론적으로는 rank라는 배열을 만들어서 높이를 비교해 더 낮은 쪽을 높은쪽의 자식으로 붙이는게 좋으나
find연산의 경로압축이 강력하여 거의 1~2의 높이로 트리가 유지되기 떄문에 큰 성능차이가 존재하지 않아
뺴고 사용하는 경우도 더러 존재한다.*/

vector<int> parent;

// Find 연산: 경로 압축 적용
int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

// Union 연산: 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) parent[b] = a; // b의 부모를 a로 설정
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0); // 각자 자기 자신을 부모로 초기화

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) { // 합집합
            unionParent(a, b);
        }
        else { // 같은 집합 확인
            if (findParent(a) == findParent(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}