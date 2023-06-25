# Game Elements Creation

This repository solves the problem of tightly coupled objects creation code, making it easier to extends and modifies new objects creation.

## The Problem:

"Your task is to implement the 'Factory Method' design pattern to refactor the character creation system. You should create an abstract class or interface called 'Character' that represents the common properties and behaviours of all characters. Then create concrete classes for each character class, such as 'Warriors', 'Archers' and 'Mage', that inherit from the 'Character' base class or implement the 'Character' interface. Each concrete class should have its own factory method, that encapsulates the creation logic for that specific class."

## The Solution:

We want to isolate the creation of new characters and allow for futher improvements without change the core structure of our project, we also want to make the code clean and scalable. For that we must to isolate each 'product' in our case each 'Character', so for everyone we had its own 'Creator' object where we can encapsulate the logic for each Character creation, and this is the basics of the Factory Method Design pattern. It is important to note that while our solution for this problem values simplicity over a real use case, we are constatly recreating objects which may not be the right way of implementing the pattern, it is totally fine to use cache or other methods for storing the objects, the main concept that must prevail is the isolation of the products and the way where it is created.

## Pros:
 
 ✅ Avoid coupling the Creator with the Products Code.

 ✅ Makes the code easier to grow and mantain.

 ✅ Follow the Single Resposability Principle guidelines.

 ✅ Follow the Open Closed Principle guidelines.

## Cons:

 ❌ May greatly increase the code complexity while creating all the necessary classes.


### **Resource:**

 🔗 [Refactoring Guru (Factory Method)](https://refactoring.guru/design-patterns/factory-method)
