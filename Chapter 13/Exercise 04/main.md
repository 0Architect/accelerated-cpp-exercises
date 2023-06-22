class Core {
public:
    // ...

    // Map a numeric grade to a letter grade
    virtual std::string getLetterGrade() const {
        if (grade() >= 90)
            return "A";
        else if (grade() >= 80)
            return "B";
        else if (grade() >= 70)
            return "C";
        else if (grade() >= 60)
            return "D";
        else
            return "F";
    }

    // ...
};

class Grad : public Core {
public:
    // ...

    // Override the getLetterGrade function for Grad class
    std::string getLetterGrade() const override {
        // Add additional conditions specific to Grad class if needed
        if (grade() >= 90)
            return "High Pass";
        else if (grade() >= 80)
            return "Pass";
        else
            return "Fail";
    }

    // ...
};
