# Character Attack Strategy 

This repository solves a problem of .

## The Problem:

""

## The Solution:

We created an intermediate interface that inherites the interface known by the Client. And then we compose it with the unknown interface, that could be a strange interface for payment, an external library or legacy code, so when the known methods are called for the adapter payment class, it will "translate" to the corresponding methods.

## Pros:
 
 - Follow the Sigle Resposability Principle guideline.
 - Respects the Open Closed Principle guideline.

## Cons:

 - May greatly increase the code complexity.


### **Resource:**

 - [Refactoring Guru (Strategy)](https://refactoring.guru/pt-br/design-patterns/strategy)
