# Smart Home Controller Device

This repository solves the problem of encapsulating action calls (operations), into objects, so they can be managed as part of the code, making easier to manipulating actions, for example, queueing operations, delay and undo/redo them.

## The Problem:

"You are building a home automation system that allows users to control various smart devices in their homes, such as lights, thermostats, and security systems. You need to implement a Command design pattern to encapsulate these commands into objects, allowing users to dynamically issue and manage commands, undo/redo commands, and schedule commands to be executed at a later time."

## The Solution:

We need three main components to solve this problem with the Command design pattern, they are, the class that defines what the command do, the class that defines how the object that are going to manage the commands behave aka 'Invoker/Sender', and the endpoint layer called 'Receiver', basically is the object that will have its intern state changed by a specific command.

## Pros:

 ✅ Follow the Single Responsability Principle guidelines.

 ✅ Follow the Open Closed Principle guidelines.
 
 ✅ Possibility to delaying the execution of a action call in runtime, among other operations.

 ✅ Makes possible to break down complex action calls into smaller and simpler ones.



## Cons:

 ❌ May greatly increase the code complexity given the implemantation of a new layer of objects.


### **Reference:**

 🔗 [Refactoring Guru (Command)](https://refactoring.guru/design-patterns/command)
