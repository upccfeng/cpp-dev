#include <vector>

class Heap
{
    std::vector<int> elements;
    int last;

    int _getSize();
    void _adjustToUp(int pos);
    void _adjustToDown(int pos);
    int _findPos(int value);

    // TODO: Open it and add test cases
    void _removeValue(int value);
    // TODO: Open it? inject lambda to replace the comparison?
    bool _isBetter(int lhs, int rhs);

public:

    Heap() : elements(1), last(0) {};
    void insert(int val);
    void removeTop();
    int* getTopPtr();
};