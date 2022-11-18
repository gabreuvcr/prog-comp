#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);
#define MOD6 1000000

using namespace std;

typedef unsigned long long int ull;
typedef vector<vector<ull>> matrix;

matrix mult_matrices(matrix A, matrix B) {
    if (A[0].size() != B.size()) throw runtime_error("Invalid matrix dimensions");

    matrix R(A.size(), vector<ull>(B[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < B.size(); k++) {
                R[i][j] += (A[i][k] % MOD6) * (B[k][j] % MOD6);
                R[i][j] = R[i][j] % MOD6;
            }
        }
    }
    return R;
}

matrix exp_matrix(matrix m, ull e) {
    if (e == 0) {
        return matrix{ 
            { 1, 0 }, 
            { 0, 1 }
        };
    }

    matrix ret = exp_matrix(m, e / 2);
    ret = mult_matrices(ret, ret);

    if (e % 2 == 1) {
        ret = mult_matrices(ret, m);
    }

    return ret;
}



int main() { _

    ull N, K, L;

    while (cin >> N >> K >> L) {
        N = (N / 5);
        K = K;
        L = L;
        

        matrix f_base = { 
            { 1, K }
        };

        matrix m {
            { 0, L },
            { 1, K }
        };

        matrix m_exp_n = exp_matrix(m, N);

        matrix result = mult_matrices(f_base, m_exp_n);

        int result_6 = result[0][0] % MOD6;
        
        cout << setw(6) << setfill('0') << result_6 << endl;
    }
    
    return 0;
}
