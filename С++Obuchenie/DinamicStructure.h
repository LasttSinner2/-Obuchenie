#pragma once



template<typename T>
struct DinamicMassiv {


    T* data = nullptr;
    int size = 0;


    T& operator [](int index) {
        return data[index];
    }

    // Константная версия оператора индексирования
    const T& operator[](int index) const {
        return data[index];
    }

    // Итераторы для range-based for
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

        T* newData = new T[newSize];  // Новый массив

        // Копируем старые элементы
        int elementsToCopy = (newSize < size) ? newSize : size;
        for (int i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }

        // Инициализируем новые элементы (если размер увеличился)
        if (newSize > size) {
            for (int i = size; i < newSize; ++i) {
                newData[i] = T{};  // Явная инициализация нулём/значением по умолчанию
            }
        }

        Remove();  // Удаляем старый массив
        data = newData;
        size = newSize;
    }

    ~DinamicMassiv() {
        Remove();
    }
};
