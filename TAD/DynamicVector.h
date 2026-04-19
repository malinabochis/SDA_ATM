#ifndef SDA_ATM_DYNAMICVECTOR_H
#define SDA_ATM_DYNAMICVECTOR_H

template <typename T>
class DynamicVector {
private:
    T* elems;
    int capacity;
    int size;
    void resize();

public:
    DynamicVector();
    ~DynamicVector();
    void push_back(T elem);
    void erase(int index);
    [[nodiscard]] int getSize() const;
    T& operator[](int index);
};

#endif //SDA_ATM_DYNAMICVECTOR_H
