template<class T>
class Ptr {
public:
    // ...

    // Equality operator (==)
    bool operator==(const Ptr& other) const {
        return (*p) == (*other.p);
    }

    // Inequality operator (!=)
    bool operator!=(const Ptr& other) const {
        return (*p) != (*other.p);
    }

    // Less than operator (<)
    bool operator<(const Ptr& other) const {
        return (*p) < (*other.p);
    }

    // Greater than operator (>)
    bool operator>(const Ptr& other) const {
        return (*p) > (*other.p);
    }

    // Less than or equal to operator (<=)
    bool operator<=(const Ptr& other) const {
        return (*p) <= (*other.p);
    }

    // Greater than or equal to operator (>=)
    bool operator>=(const Ptr& other) const {
        return (*p) >= (*other.p);
    }

    // ...
};