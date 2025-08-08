class Solution {
public:
    vector<int> segTree;
    int n;

    void buildTree(vector<int>& heights, int i, int l, int r) {
        if (l == r) {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(heights, 2 * i + 1, l, mid);
        buildTree(heights, 2 * i + 2, mid + 1, r);
        int left = segTree[2 * i + 1];
        int right = segTree[2 * i + 2];
        segTree[i] = (heights[left] > heights[right]) ? left : right;
    }

    int MQI(int s, int e, int l, int r, vector<int>& heights, int i) {
        if (l > e || r < s) return -1;
        if (l >= s && r <= e) return segTree[i];
        int mid = l + (r - l) / 2;
        int left = MQI(s, e, l, mid, heights, 2 * i + 1);
        int right = MQI(s, e, mid + 1, r, heights, 2 * i + 2);
        if (left == -1) return right;
        if (right == -1) return left;
        return (heights[left] > heights[right]) ? left : right;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        segTree.resize(4 * n);
        buildTree(heights, 0, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int mini = min(queries[i][0], queries[i][1]);
            int maxi = max(queries[i][0], queries[i][1]);

            if (mini == maxi) {
                ans.push_back(mini);
                continue;
            } else if (heights[maxi] > heights[mini]) {
                ans.push_back(maxi);
                continue;
            } else {
                int start = maxi + 1;
                int end = n - 1;
                int indexi = -1;

                while (start <= end) {
                    int mid = start + (end - start) / 2;
                    int idx = MQI(start, mid, 0, n - 1, heights, 0);
                    if (idx != -1 && heights[idx] > heights[mini]) {
                        indexi = idx;
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
                ans.push_back(indexi);
            }
        }
        return ans;
    }
};
