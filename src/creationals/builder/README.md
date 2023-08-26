# Custom Computer Configuration Store 

This repository solves the problem of needing to construct multiple different objects without having to extend the same class multiple times, but using the same or similar steps, completly or partialy equal.

## The Problem:

"You are building a system for creating customized computer configurations for a computer store. Customers can choose various components for their computers, such as CPU, RAM, storage, and graphics card, and they can also specify additional features, such as cooling system, lighting, and overclocking options. The system need to create computer configurations based on customer preferences, ensuring that the configuration are valid and complete. You need to implement a Builder design pattern to separate the construction of complex computer configurations from their representation, allowing for step-by-step construction of configurations and easy customization of different parts."

## The Solution:

We are going to use a common builder interface that defines the common methods, to all possible computers configurations, then we create the concrete builder for specifing the computer configuration, and we are going to use a director class to define and differentiate the types of computer for each config.

## Pros:
 
 ✅ You can construct objects step-by-step, defer construction steps or run steps recursively.

 ✅ You can reuse the same construction code when building various representations of products.
 
 ✅ Helps to follow the Single Responsibility Principle guidelines.

## Cons:

 ❌ Might increase the overall code complexity.


### **Reference:**

 🔗 [Refactoring Guru (Builder)](https://refactoring.guru/design-patterns/builder)
