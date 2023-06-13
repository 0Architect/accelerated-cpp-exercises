class Student_info {
private:
    static int created_count;
    static int copied_count;
    static int assigned_count;
    static int destroyed_count;

public:
    Student_info() {
        ++created_count;
    }

    Student_info(const Student_info& other) {
        ++copied_count;
    }

    Student_info& operator=(const Student_info& other) {
        ++assigned_count;
        if (this != &other) {
        }
        return *this;
    }

    ~Student_info() {
        ++destroyed_count;
    }

    static int getCreatedCount() { return created_count; }
    static int getCopiedCount() { return copied_count; }
    static int getAssignedCount() { return assigned_count; }
    static int getDestroyedCount() { return destroyed_count; }
};

int Student_info::created_count = 0;
int Student_info::copied_count = 0;
int Student_info::assigned_count = 0;
int Student_info::destroyed_count = 0;
