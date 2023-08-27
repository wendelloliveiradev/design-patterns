# Multiple Online Courses Platform 

This repository solves the problem of defining the sequence of steps the object need to run, so it can suit different use cases that vary slightly from each other, without having to duplicate the code every time.

## The Problem:

"You are developing a framework for building online courses. The framewok allows instructors to create different types of courses, such as videos courses, text-based courses, and interactive courses. Each course type has its own way of handling the content, layout, and interactions, but they share some common steps in the course creation process. You need to implement a Template Method design pattern to provide a reusable way of defining the course creation process with customizable steps for each course type.

The course creation process consists of several steps that are common across all course types, such as creating a new course, setting up course metadata, adding course content, and publishing the course. However, each course type may have its own way of handling these steps. For example, a video course may require uploading video files and setting up video playback options, while a text-based course may require creating and organizing text modules. Despite these differences, there are common steps that can be abstracted and defined as a template method."

## The Solution:

Template Mmethod is one of the easiest pattern to implement, we just need to create a base abstract class that contains the skeleton for some operation that may vary slightly to be used in others use cases, so for it specific use case we can create a class that extends this base class and overrides the needed operations.

## Pros:

 ✅ This pattern is an excellent way of implementing the DRY code preinciple.
 
 ✅ The algorithm creation process can be standardized to a common implementation.

## Cons:

 ❌ It can age badly because of inheritance and code complexity.

 ❌ You might violate the Liskov Substitution Principle.

### **Reference:**

 🔗 [Refactoring Guru (Template Method)](https://refactoring.guru/design-patterns/template-method)
