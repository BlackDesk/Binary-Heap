#include <vector>
#include <iostream>

class Heap {
private:

    void sift_down(const int i) {
        if (left(i) >= size()) {
            return;
        }
        int min_index;
        if (left(i) == size()) {
            min_index = left(i);
        } else if (data[left(i)] <= data[right(i)]) {
            min_index = left(i);
        } else {
            min_index = right(i);
        }
        if (data[min_index] < data[i]) {
            int tmp = data[min_index];
            data[min_index] = data[i];
            data[i] = tmp;
            sift_down(min_index);
        }
    }

    void sift_up(const int i) {
        if (i == 0) {
            return;
        }
        if (data[i] < data[parent(i)]) {
            int tmp = data[i];
            data[i] = data[parent(i)];
            data[parent(i)] = tmp;
            sift_up(parent(i));
        }
    }

    std::vector<int> data;
public:
    [[nodiscard]] int parent(const int index) const {
        return (index - 1) / 2;
    }

    [[nodiscard]] int left(const int index) const {
        return index * 2 + 1;
    }

    [[nodiscard]] int right(const int index) const {
        return index * 2 + 2;
    }

    [[nodiscard]] const int &root() const {
        return data[0];
    }

    int &root() {
        return data[0];
    }

    void solve() {
        for (size_t i = 0; i < size(); ++i) {
            sift_up(i);
        }
    }

    [[nodiscard]] const int &last() const {
        return data[data.size() - 1];
    }

    [[nodiscard]] size_t size() const {
        return data.size();
    }

    void insert(const int value) {
        data.push_back(value);
        sift_up(size() - 1);
    }

    int extract() {
        int result = root();
        root() = last();
        data.pop_back();
        sift_down(0);
        return result;
    }
};


int main() {
    Heap heap;
    int n, curr;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> curr;
        heap.insert(curr);
    }
    heap.solve();
    for (size_t i = 0; i < n; ++i) {
        std::cout << heap.extract() << "\n";
    }
}