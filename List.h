#pragma once
#include <iostream>

template<typename T>
class List {
    T *_data;
    int _capacity;
    int _size;
public:
    // --- Construction/Destruction & Copy/CopyAssign ---
    explicit List(int initialCapacity = 1);

    ~List();

    List(const List &otherObject);

    List &operator=(const List &rhs);

    // --- Accessors ---
    const int *GetData() const;

    unsigned int GetCapacity();

    unsigned int GetSize();

    // --- Mutators ---
    void Push(T newItem);

    void Clear();

    void Pop();

    // --- Behaviors ---
    void Print();
};


template<typename T>
List<T>::List(int initialCapacity) {
    _data = new T[_capacity];
    _capacity = initialCapacity;
    _size = 0;
}

template<typename T>
List<T>::~List() {
    delete[] _data;
}

template<typename T>
List<T>::List(const List &otherObject) {
    _size = otherObject._size;
    _capacity = otherObject._size;
    _data = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        _data[i] = otherObject._data[i];
    }
}

template<typename T>
List<T> &List<T>::operator=(const List &rhs) {
    delete[] _data;
    _size = rhs._size;
    _capacity = rhs._size;
    _data = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        _data[i] = rhs._data[i];
    }
    return *this;
}

template<typename T>
unsigned int List<T>::GetCapacity() {
    return _capacity;
}

template<typename T>
unsigned int List<T>::GetSize() {
    return _size;
}

template<typename T>
const int *List<T>::GetData() const {
    return _data;
}

template<typename T>
void List<T>::Push(T newItem) {
    _data[_size] = newItem;
    _size++;
}

template<typename T>
void List<T>::Pop() {
    int indexOfLastElem = _size - 1;
    _data[indexOfLastElem] = 0;
    _size--;
}

template<typename T>
void List<T>::Clear() {
    delete[] _data;
    _data = new T[_capacity];
    _capacity = 1;
    _size = 0;
}

template<typename T>
void List<T>::Print() {
    for (int i = 0; i < _size; i++) {
        std::cout << _data[i] << std::endl;
    }
}
