class Solution {
public:
    int find(vector<int>& f, int x) {
        if (f[x] == x) {
            return x;
        }
        int fa = find(f, f[x]);
        f[x] = fa;
        return fa;
    }

    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x);
        int fy = find(f, y);
        f[fx] = fy;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> f(n * n * 4);
        for (int i = 0; i < n * n * 4; i++) {
            f[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                if (i < n - 1) {
                    int bottom = idx + n;
                    merge(f, idx * 4 + 2, bottom * 4);
                }
                if (j < n - 1) {
                    int right = idx + 1;
                    merge(f, idx * 4 + 1, right * 4 + 3);
                }
                if (grid[i][j] == '/') {
                    merge(f, idx * 4, idx * 4 + 3);
                    merge(f, idx * 4 + 1, idx * 4 + 2);
                } else if (grid[i][j] == '\\') {
                    merge(f, idx * 4, idx * 4 + 1);
                    merge(f, idx * 4 + 2, idx * 4 + 3);
                } else {
                    merge(f, idx * 4, idx * 4 + 1);
                    merge(f, idx * 4 + 1, idx * 4 + 2);
                    merge(f, idx * 4 + 2, idx * 4 + 3);
                }
            }
        }

        unordered_set<int> fathers;
        for (int i = 0; i < n * n * 4; i++) {
            int fa = find(f, i);
            fathers.insert(fa);
        }
        return fathers.size();
    }
};
