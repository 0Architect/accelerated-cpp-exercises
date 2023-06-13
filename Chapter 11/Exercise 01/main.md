# Answer
---
The Student_info structure did not define a copy constructor, assignment operator or destructor as there was no need.

All it's data members were either primitive types or standard-library defined classes that the compiler can already handle itself, or was handled by the default constructor.

No unique trait was needed for any of the operations.