#pragma once



template<typename T>
struct DinamicMassiv {


    T* data = nullptr;
    int size = 0;


    T& operator [](int index) {
        return data[index];
    }

    // ����������� ������ ��������� ��������������
    const T& operator[](int index) const {
        return data[index];
    }

    // ��������� ��� range-based for
    T* begin() { return data; }
    T* end() { return data + size; }
    const T* begin() const { return data; }
    const T* end() const { return data + size; }



    void Create(int s) {
        size = s;
        data = new T[size];
    }

    void Remove() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
            size = 0;
        }
    }

    void Resize(int newSize) {
        if (newSize == size) return;

        if (newSize <= 0) {
            Remove();
            return;
        }

        T* newData = new T[newSize];  // ����� ������

        // �������� ������ ��������
        int elementsToCopy = (newSize < size) ? newSize : size;
        for (int i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }

        // �������������� ����� �������� (���� ������ ����������)
        if (newSize > size) {
            for (int i = size; i < newSize; ++i) {
                newData[i] = T{};  // ����� ������������� ����/��������� �� ���������
            }
        }

        Remove();  // ������� ������ ������
        data = newData;
        size = newSize;
    }

    ~DinamicMassiv() {
        Remove();
    }
};
