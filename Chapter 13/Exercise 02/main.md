#Solution
---
p1->grade();
This will call the Core::grade() function because p1 is a pointer to a Core object.

p1->name();
This will call the Core::name() function because p1 is a pointer to a Core object.

p2->grade();
This will call the Grad::grade() function. Since p2 is a pointer to a Grad object, the derived class's function will be called due to dynamic binding.

p2->name();
This will call the Core::name() function because the name() function is not overridden in the Grad class. Therefore, the function from the base class, Core, will be called.

s1.grade();
This will call the Core::grade() function because s1 is an instance of the Core class.

s1.name();
This will call the Core::name() function because s1 is an instance of the Core class.

s2.name();
This will call the Core::name() function because the name() function is not overridden in the Grad class. Therefore, the function from the base class, Core, will be called.

s2.grade();
This will call the Grad::grade() function because s2 is an instance of the Grad class, and the derived class's function will be called.