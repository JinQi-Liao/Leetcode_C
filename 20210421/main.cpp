

// 20210421宋金根机考题

#include <iostream>>
#include <vector>

using namespace std;
typedef struct {
    int A;
    int L;
    int C;
} Client;
int main() {
    vector<int>res(24, 0);
    vector<Client> table;
    int N, M;
    cin >> N >> M;
    int size = N;
    while (N)
    {
        Client temp;
        cin >> temp.A >> temp.L >> temp.C;
        table.push_back(temp);
        N--;
    }
    
    // 开始判断
    for (int i = 0; i < size; i++) {
        Client a = table[i];
        if (a.C <= M) {
            for (int i = a.A; i <a.L; i++) {
                if (res[i] + a.C <= M) {
                    res[i] += a.C;
                }
            }
        }
    }

    // 开始输出
    for (int i = 0; i < 24; i++) {
        cout << res[i]<<" ";
    }

    return 0;
}