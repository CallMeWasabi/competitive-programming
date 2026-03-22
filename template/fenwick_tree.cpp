#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
    vector<int> tr;
    vector<int> nums;

    FenwickTree(vector<int> v) {
        nums = v;
        tr.assign(v.size() + 1, 0);
        for (int i = 0; i < v.size(); i++) add(i + 1, nums[i]);
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tr[i];
            i -= i & (-i);
        }
        return sum;
    }

    void add(int i, int delta) {
        while (i < tr.size()) {
            tr[i] += delta;
            i += i & (-i);
        }
    }

    void update(int i, int to) { // i is base-1 index
        int base0 = i - 1;
        int delta = to - nums[base0];
        nums[base0] = to;
        add(i, delta);
    }
};

int main() {
    FenwickTree ft({1, 2, 3, 4, 5});

    cout << "Query 1: " << ft.query(1) << endl; // 1
    cout << "Query 2: " << ft.query(2) << endl; // 1+2 = 3
    cout << "Query 3: " << ft.query(3) << endl; // 1+2+3 = 6

    cout << "Updating index 3 to value 1..." << endl;
    ft.update(3, 1);

    cout << "Query 3: " << ft.query(3) << endl; // 1+2+1 = 4
    return 0;
}
