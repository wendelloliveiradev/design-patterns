# Character Attack Command

This repository solves a problem of multiples similar action code inside a single class with strategies.

## The Problem:

"You are developing a game that involves different characters with different abilities, such as warriors, archers, and mages. Each character has a specific attack strategiy that determines how they engage in combat.

The game currently has a `Character` class that represents the characters in the game, but the problem is that the attack strategy is hardcoded within the `Character` class."

## The Solution:

Based on the context `Character`. We created an interface that provide a contract for each type of stategies and then we encapsulated the commom algorithms inside a specific strategy, so each strategy can be changed in the runtime and switched between each type of `Character`.

## Pros:
 
 ✔️ Possibility to change the type of algorithm in runtime.

 ✔️ Isolates the details of an algorithm implementation.

 ✔️ Follow the Liskov Substitution Principle guidelines.

 ✔️ Follow the Open Closed Principle guidelines.

## Cons:

 ❌ May greatly increase the code complexity for simpler implemantations.

 ❌ Needs good documentation for each strategy, the client must be well informed about it.

 ❌ In functional programming languages may be used anonymous function for a similar result with easier implementation.


### **Resource:**

 🔗 [Refactoring Guru (Strategy)](https://refactoring.guru/design-patterns/strategy)
