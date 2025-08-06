#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid)
                update(index, value, 2 * node + 1, start, mid);
            else
                update(index, value, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateIndex(int index, int value) {
        update(index, value, 0, 0, n - 1);
    }

    void print() {
        for (int i = 0; i < 4 * n; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    st.print(); // Original segment tree

    st.updateIndex(2, 10); // Update index 2 with value 10 (was 5)
    
    st.print(); // Updated segment tree
    return 0;
}
