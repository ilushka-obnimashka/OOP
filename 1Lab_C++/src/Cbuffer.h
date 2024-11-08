#include <iostream>

template<typename T>
class CircularBuffer {
private:
    T* buffer; // указатель на массив элементов произвольного типа данных, хранит сами данные буффера.
    size_t capacity; // целое число без знака, хранит максимальное количество элементов, которое может быть записано в буфер.
    size_t size; // целое число без знака, хранит текущее количество элементов в буфере..
    size_t start; // целое число без знака, хранит позицию первого элемента.
public:
    // конструктор по умолчанию.
    explicit CircularBuffer(size_t initialCapacity)
    : capacity(initialCapacity), size(0), start(0){
        this->buffer = new T[this->capacity];
    }
    ~CircularBuffer() {
        delete[] this->buffer;
    }
    // конструктор копирования.
    CircularBuffer(const CircularBuffer &cb)
    : capacity(cb.capacity), size(cb.size), start(cb.start) {
        this->buffer  = new T[this->capacity];

        for (size_t i = 0; i < size; i++) {
            this->buffer[(i + this->start) % this->capacity] = cb.buffer[(i+cb.start) % cb.capacity];
        }
    }
    // Конструирует буфер заданной ёмкости, целиком заполняет его элементом elem.
    CircularBuffer(int capacity, const T & elem) : CircularBuffer(static_cast<size_t>(capacity)){
        for (size_t i = 0; i < capacity; i++) {
            this->buffer[i] = elem;
        }
        this->size = capacity; // количество записанных элементов равно емкость
        //start = 0 задано в конструкторе создания
    }

    CircularBuffer & operator=(const CircularBuffer & cb) { // Оператор присвавания
        if (this == &cb) {
            return *this;
        }

        delete [] this->buffer;

        this->capacity = cb.capacity;
        this->size = cb.size;
        this->start = cb.start;

        this->buffer = new T[this->capacity];

        for (size_t i = 0; i < this->capacity; ++i) {
            this->buffer[i] = cb.buffer[i];
        }

        return *this;

    }

    // вставляет элемент по индексу (индексация от start)
    void insert(int pos, const T & item = T()) {
        this->buffer [(start + pos) % capacity] = item;
    }
    //Обменивает содержимое буфера с буфером cb.
    void swap(CircularBuffer & cb) {
        std::swap(this->capacity, cb.capacity);
        std::swap(this->size, cb.size);
        std::swap(this->start, cb.start);
        std::swap(this->buffer, cb.buffer);
    }

    //Удаляет элементы из буфера в интервале [first, last).
    void erase(int first, int last) {
        if (first == last) return;

        if (first < 0 || last > size || first >= last) {
            throw std::out_of_range("Invalid range for erase operation");
        }

        T* temp = new T[this->capacity];

        int tempIdx = 0;
        for (size_t i = 0 ; i<this->capacity; i++) {
            if (i>=first && i<last) continue;
            else temp[tempIdx++] = this->buffer[(this->start + i)%capacity];
        }

        for (size_t i = 0; i<capacity; i++) {
            this->buffer[i] = temp[i];
        }

        this->start = 0;
        this->size = tempIdx;

        delete [] temp;
    }
    //Доступ по индексу. Не проверяют правильность индекса.
    // Индексация ведется от start (idTail = 0, idxHead = size | не связаны с индексацией буффера), т.к кольцевой буффер FIFO.
    // не рекомендуется использовать, так как не проверяется правильность индекса.
    T & operator[](int i){
        return this->buffer[(this->start + i) % this->capacity];
    }

    const T & operator[](int i) const{
        return this->buffer[(this->start + i) % this->capacity];
    }

    //Доступ по индексу. Методы бросают исключение в случае неверного индекса.
    // Индекс считается неверным если он превышает size (т.k индексация идет от 0 до size).
    T & at(int i) {
        if (i > this->size || i < 0) throw std::out_of_range("Index out of range");

        return this->buffer[(this->start + i) % this->capacity];
    }

    const T & at(int i) const {

        if (i > this->size || i < 0) throw std::out_of_range("Index out of range");

        return this->buffer[(this->start + i) % this->capacity];
    }

    T & front() //Ссылка на первый элемент.
    {
        if (empty())
            throw std::logic_error("Try to reach element from empty buffer");
        return this->buffer[this->start];
    }

    //Ссылка на последний элемент.
    T &  back() {
        if (empty())
            throw std::logic_error("Try to reach element from empty buffer");
        // head показывает индекс в массиве куда будет записан новый элемент
        return this->buffer[(this->start + this->size-1) % this->capacity];
    }

    const T & front() const{
        if (empty())
            throw std::logic_error("Try to reach element from empty buffer");
        return this->buffer[this->start];
    }

    const T back() const{
        if (empty())
            throw std::logic_error("Try to reach element from empty buffer");
        return this->buffer[(this->start + this->size-1) % this->capacity];
    }


    //Количество элементов, хранящихся в буфере.
    int getSize() const
    {
        return static_cast<int>(this->size);
    }


    // Емкость буффера.
    int getCapacity() const
    {
        return static_cast<int>(this->capacity);
    }

    int getStart() const
    {
        return static_cast<int>(this->start);
    }

    T* getBuffer() const
    {
        return this->buffer;
    }


    //true, если size() == 0.
    bool empty () const {
        return this->size == 0;
    }


    //true, если size() == capacity.
    bool full () const {
        return this->size == this->capacity;
    }


    //Количество свободных ячеек в буфере.
    int reserve() const
    {
        return static_cast<int>(this->capacity - this->size);
    }

    /*Линеаризация - сдвинуть кольцевой буфер так, что его первый элемент
    переместится в начало аллоцированной памяти. Возвращает указатель
    на первый элемент */
    T * linearize(){
        T* temp = new T[this->size];

        for (size_t i = 0; i<size; i++) {
            temp[i] = this->buffer[(this->start + i)%capacity];
        }

        for (size_t i = 0; i<size; i++) {
            this->buffer[i] = temp[i];
        }
        this->start = 0;
        delete [] temp;

        return buffer;
    }

    //Проверяет, является ли буфер линеаризованным.
    bool is_linearized() const {
        return this->start == 0;
    }


    //Сдвигает буфер так, что по нулевому индексу окажется элемент
    //с индексом new_begin (индексация идет от start, (start = 0)).
    void rotate(int new_begin){
        T* temp = new T[this->capacity];

        for (size_t i = 0; i<this->capacity; i++) {
            temp[i] = this->buffer[(new_begin + i)%capacity];
        }

        for (size_t i = 0; i<capacity; i++) {
            this->buffer[i] = temp[i];
        }

        this->start = 0;
        delete [] temp;
    }

    void setCapacity(int new_capacity){ //Изменяет размер буфера., при этом старый start встает на buffer[0] , порядок start -...  сохраняется
        if (this->capacity == new_capacity) return;

        T *newBuffer = new T [new_capacity];
        for (size_t i = 0; i < this->size; ++i){
            newBuffer[i] = this->buffer[(i + this->start)%capacity];
        }

        this->capacity = new_capacity;
        delete [] buffer;
        buffer = newBuffer;

        start = 0;
    }

    //В случае расширения, новые элементы заполняются элементом item.
    void resize(int new_size, const T & item = T()) {
        if (new_size <= this->size) {
            this->size = new_size;
            return;
        }
        if (new_size > this->capacity) {
            setCapacity(new_size);
        }

        for (size_t i = this->size; i< new_size; i++) {
            this->buffer[i] = item;
        }
    }

    /*Добавляет элемент в конец буфера.
    Если текущий размер буфера равен его ёмкости, то переписывается
    первый элемент буфера (т.е., буфер закольцован). */
    void push_back(const T & item = T()) {
        if (this->size < this->capacity) {
            this->buffer[(this->start + this->size) % capacity] = item;
            this->size++;
        }
        else {
            this->buffer[start] = item;
            start++;
        }
    }

    //Добавляет новый элемент перед первым элементом буфера.
    //Аналогично push_back, может переписать последний элемент буфера.
    void push_front(const T & item = T()) {
        if (this->size < this->capacity) {
            if (this->start == 0) {
                this->start = this->capacity - 1;
            }
            else {
                this->start --;
            }
            buffer[this->start] = item;
            this->size++;
        }
        else {
            if (this->start == 0) {
                this->start = this->capacity - 1;
            }
            else {
                this->start --;
            }
            buffer[this->start] = item;
        }
    }

    //Удаляет последний элемент буфера.(head-1)
    void pop_back(){
        if (empty())
            throw std::logic_error("Try delete from empty buffer");
        this->buffer[(this->start + this->size - 1) % capacity] = 0;
        this->size--;
    }

    //Удаляет первый элемент буфера. (start)
    void pop_front() {
        if (empty())
            throw std::logic_error("Try delete from empty buffer");
        this->buffer[this->start] = 0;
        this->start = (this->start + 1)%this->capacity;
        this->size --;
    }

    //Очищает буфер.
    void clear() {
        this->size = 0;
        this->start = 0;
        delete [] this->buffer;
        this->buffer = nullptr;
    }



    friend std::ostream& operator << (std::ostream& out, const CircularBuffer& cb) {
        out << "Capacity: " << cb.capacity << " size: " << cb.size << " start: " << cb.start <<
                " reserve: " << cb.reserve() << std::endl;
        for (size_t i = 0; i < cb.size; i++) {
            out << cb.buffer[(cb.start + i) % cb.capacity] << " ";
        }
        return out;
    }

};

template<class T>
bool operator==(const CircularBuffer<T> &a, const CircularBuffer<T> &b) {
    if (a.getSize() != b.getSize())
        return false;

    for (size_t i = 0; i < a.getSize(); ++i)
        if (a[i] != b[i])
            return false;

    return true;
}

template<class T>
bool operator!=(const CircularBuffer<T> &a, const CircularBuffer<T> &b) {
    return !(a == b);
}