# Multiple Online Courses Platform 

This repository solves the problem of.

## The Problem:

"You are developing a framework for building online courses. The framewok allows instructors to create different types of courses, such as videos courses, text-based courses, and interactive courses. Each course type has its own way of handling the content, layout, and interactions, but they share some commom steps in the course creation process. You need to implement a Template Method design pattern to provide a reusable way of defining the course creation process with customizable steps for each course type.

The course creation process consists of several steps that are common across all course types, such as creating a new course, setting up course metadata, adding course content, and publishing the course. However, each course type may have its own way of handling these steps. For example, a video course may require uploading video files and setting up video playback options, while a text-based course may require creating and organizing text modules. Despite these differences, there are common steps that can be abstracted and defined as a template method."

## The Solution:

Based.

## Pros:
 
 ✅ You can let clients override only certain parts of a large algorithm, making them less affected by changes that happen to other parts of the algorithm.

 ✅ You can pull the duplicate code into a superclass.

## Cons:

 ❌ Some clients may be limited by the provided skeleton of an algorithm.

 ❌ You might violate the Liskov Substitution Principle by suppressing a default step implementation via a subclass.

 ❌ Template methods tend to be harder to maintain the more steps they have.


### **Resource:**

 🔗 [Refactoring Guru (Template Method)](https://refactoring.guru/design-patterns/template-method)
