class PassFailStudent : public Core {
public:
    // Constructors
    PassFailStudent() : Core() {}
    PassFailStudent(std::istream& is) : Core(is) {}

    // Override the grade function for pass/fail credit
    double grade() const override {
        if (!homework.empty()) {
            // Calculate the grade using the normal formula
            return Core::grade();
        } else {
            // If no homework is done, average the midterm and final grades
            return (midterm + final) / 2.0;
        }
    }
};
