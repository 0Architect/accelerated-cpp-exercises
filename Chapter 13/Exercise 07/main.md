class AuditStudent : public Core {
public:
    // Constructors
    AuditStudent() : Core() {}
    AuditStudent(std::istream& is) : Core(is) {}

    // Override the grade function for auditing students
    double grade() const override {
        // Auditing students receive a grade of 0, regardless of their performance
        return 0.0;
    }
};
