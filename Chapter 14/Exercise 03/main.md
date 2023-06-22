class Student_info {
public:
    Student_info() { }
    Student_info(std::istream& is) { read(is); }
    // No need for copy, assignment, or destructor: they're no longer needed

    std::istream& read(std::istream&);

    std::string name() const {
        if (cp)
            return cp->name();
        else
            throw std::runtime_error("uninitialized Student");
    }

    double grade() const {
        if (cp)
            return cp->grade();
        else
            throw std::runtime_error("uninitialized Student");
    }

    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    }

private:
    Ptr<Core> cp;
};

std::istream& Student_info::read(std::istream& is) {
    char ch;
    is >> ch; // Get record type

    // Allocate a new object of the appropriate type
    // Use Ptr<T>(T*) to build a Ptr<Core> from the pointer to that object
    // Call Ptr<T>::operator= to assign the Ptr<Core> to the left-hand side
    if (ch == 'U')
        cp = new Core(is);
    else
        cp = new Grad(is);
    
    return is;
}