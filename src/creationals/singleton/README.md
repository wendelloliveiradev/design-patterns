# Single Logging System Interface 

This repository solves the problem of needing only one instace of a particular object, blocking the creation of another object from the same class.

## The Problem:

"You are building a logging service for a large application that requires centralized logging of various events, such as errors, warnings, and informarion messages. The logging service needs to maintain a single instance throughout the lifetime of the application and provide a golbal access point for all components of the application to log events. The service should also ensure that only one instance of the logger is created, even if multiple components try to create it simultaneously. You need to implement a Singleton design pattern to ensure that the logging service is instantiated only once and provides a global access point for logging events."

## The Solution:

The solution to this problem is really easy to implement, we just need to make the constructor of our object private, the only way to intantiate the object is through a public function, that checks if the object is already instantiated, if true then we return the object saved in a private state in the same class, other ways we instantiate a new object.

## Pros:
 
 ✅ You can be sure that a class has only a single instance.

 ✅ You gain a global access point to that instance.

 ✅ The singleton object is initialized only when it’s requested for the first time.

## Cons:

 ❌ Violates the Single Responsibility Principle. The pattern solves two problems at the time.

 ❌ The Singleton pattern can mask bad design, for instance, when the components of the program know too much about each other.

 ❌ The pattern requires special treatment in a multithreaded environment so that multiple threads won’t create a singleton object several times.

 ❌ It may be difficult to unit test the client code of the Singleton because many test frameworks rely on inheritance when producing mock objects. Since the constructor of the singleton class is private and overriding static methods is impossible in most languages, you will need to think of a creative way to mock the singleton. Or just don’t write the tests. Or don’t use the Singleton pattern.


### **Reference:**

 🔗 [Refactoring Guru (Singleton)](https://refactoring.guru/design-patterns/singleton)
