class Core {
public:
    // ...

    // Check if the student met all the relevant requirements
    bool metRequirements() const {
        bool allHomeworkCompleted = !homework.empty();
        return allHomeworkCompleted;
    }

    // ...
};

class Grad : public Core {
public:
    // ...

    // Check if the graduate student met all the relevant requirements
    bool metRequirements() const {
        bool allHomeworkCompleted = Core::metRequirements();
        bool thesisWritten = thesis != 0;
        return allHomeworkCompleted && thesisWritten;
    }

    // ...
};
