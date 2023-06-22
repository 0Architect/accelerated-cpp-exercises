template <class T>
class RefCounter {
public:
    RefCounter() : count(new size_t(1)) {}
    void increment() { ++(*count); }
    void decrement() {
        if (--(*count) == 0) {
            delete count;
            count = nullptr;
        }
    }
    bool isUnique() const { return *count == 1; }
private:
    size_t* count;
};

template <class T>
class Ptr {
public:
    Ptr() : ptr(nullptr), refCounter(nullptr) {}
    Ptr(T* t) : ptr(t), refCounter(new RefCounter<T>()) {}
    Ptr(const Ptr& other) : ptr(other.ptr), refCounter(other.refCounter) {
        if (refCounter)
            refCounter->increment();
    }
    Ptr& operator=(const Ptr& rhs) {
        if (this != &rhs) {
            decrementRef();
            ptr = rhs.ptr;
            refCounter = rhs.refCounter;
            if (refCounter)
                refCounter->increment();
        }
        return *this;
    }
    ~Ptr() {
        decrementRef();
    }

    T* operator->() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

private:
    T* ptr;
    RefCounter<T>* refCounter;

    void decrementRef() {
        if (refCounter) {
            refCounter->decrement();
            if (!refCounter->isUnique()) {
                ptr = nullptr;
                refCounter = nullptr;
            }
        }
    }
};
