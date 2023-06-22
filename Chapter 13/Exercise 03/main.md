class Core {
public:
    // ...

    // Check if the object holds values for a student record
    virtual bool isValidRecord() const {
        return !name.empty(); // Check if the name is not empty
    }

    // ...
};

class Grad : public Core {
public:
    // ...

    // Override the isValidRecord function for Grad class
    bool isValidRecord() const override {
        // Add additional conditions specific to Grad class if needed
        // For example, you can check if the thesis is non-zero
        return Core::isValidRecord() && thesis != 0;
    }

    // ...
};
