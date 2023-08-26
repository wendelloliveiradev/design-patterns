# Coffee Ordering System with Decorators

This repository solves the problem of needing to add or remove layers of behaviours to an existing object in runtime, without changing the basic structure of it. It also allows to easily create or delete layers of behaviours in the future.

## The Problem:

"You are building a coffee ordering system that allows users to costumize their coffee orders with various topping, such as whipped cream, caramel, and hazelnut syrup. The system should allow users to dynamically add or remove toppings from their coffee orders, and calculate the total cost of the orders based on the base coffee and the selected toppings. You need to implementa Decorator design pattern to allow for flexible customization of coffee orders with different topping, without modifying the base coffee class or the code that calculates the total cost of the order."

## The Solution:

We just need to implement an abstract class, that extends the common interface of coffee, because we want our decorator to implement this abstract class, and we want the decorator concrete implementation to be able to inject the past decorator inside a wrapper coffe decorator, then our client just deals with the last layer of the decorator.

## Pros:
 
 ✅ You can extend an object’s behavior without making a new subclass.

 ✅ You can add or remove responsibilities from an object at runtime.
 
 ✅ You can combine several behaviors by wrapping an object into multiple decorators.
 
 ✅ Follows the Single Resposability Principle guidelines.

## Cons:

 ❌ It’s hard to remove a specific wrapper from the wrappers stack.
 
 ❌ It’s hard to implement a decorator in such a way that its behavior doesn’t depend on the order in the decorators stack.

### **Reference:**

 🔗 [Refactoring Guru (Decorator)](https://refactoring.guru/design-patterns/decorator)
