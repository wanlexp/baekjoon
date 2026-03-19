#include <iostream>
#include<vector>
using namespace std;

class CircularQueue {
    vector<int> data;
    int head, sz, cap;

    // 왼쪽으로 한 칸: 맨 앞 원소를 맨 뒤로 복사하고 head 증가
    void rotateLeft() {
        int tailIndex = (head + sz) % cap;
        data[tailIndex] = data[head];
        head = (head + 1) % cap;
    }

    // 오른쪽으로 한 칸: 논리적 마지막을 맨 앞으로 복사하고 head를 그 위치로
    void rotateRight() {
        int lastIndex = (head + sz - 1) % cap;
        int newHead = (head + cap - 1) % cap;
        data[newHead] = data[lastIndex];
        head = newHead;
    }

    int indexOf(int x) const {
        for (int i = 0; i < sz; ++i) {
            int phys = (head + i) % cap;
            if (data[phys] == x) return i;
        }
        return -1;
    }

public:
    CircularQueue(int n) : data(n), head(0), sz(n), cap(n) {
        for (int i = 0; i < n; ++i) data[i] = i + 1;
    }

    int extract(int x) {
        int idx = indexOf(x);
        if (idx == -1) return 0; 

        int cnt = 0;
        if (idx == 0) {
            popFront();
            return 0;
        }

        if (idx <= sz / 2) {
            for (int i = 0; i < idx; ++i) { rotateLeft(); ++cnt; }
        }
        else {
            int k = sz - idx;
            for (int i = 0; i < k; ++i) { rotateRight(); ++cnt; }
        }
        popFront();
        return cnt;
    }

    int front() const { return data[head]; }

private:
    void popFront() {
        head = (head + 1) % cap;
        --sz;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    CircularQueue q(n);
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        res += q.extract(k);
    }
    cout << res << '\n';
    return 0;
}
