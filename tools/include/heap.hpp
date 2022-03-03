#include <vector>

class Heap
{
    // TODO: implement to key-value, key is used to sort. There can be multiple values in one key
    std::vector<int> elements;
    std::vector<int> cnts;
    int last;

    int _getSize();
    void _adjustToUp(int pos);
    void _adjustToDown(int pos);
    int _findPos(int value);

    // TODO: Open it? inject lambda to replace the comparison?
    bool _isBetter(int lhs, int rhs);

public:

    Heap() : elements(1), cnts(1), last(0) {};
    void insert(int val);
    void removeTop();
    void removeValue(int value);
    int getValueCnt(int value);
    int* getTopPtr();
};