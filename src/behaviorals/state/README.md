# Vending Machine State

This repository solves the problem of having to perform multple actions depending on the internal class state.

## The Problem:

"You are working on a vending machine application that allows users to purchase items using coins. The vending machine has different behaviours based on its current state, such as 'Idle', 'HasCoin', 'Dispensing', and 'OutOfStock'. The vending machine has buttons for selecting items, inserting coins and dispersing items.

The behaviour of the vending machine depends on its current state. For example, if the vending machine is in the 'Idle' state, it should display a welcome message and wait for the user to insert a coin. If the vending machine is in the 'HasCoin' state, it should display the selected item and wait for the user to press the 'Dispense' button. If the vending machine is in the 'Dispensing' state, it should dispense the item and return any change to the user. If the vending machine is in the 'OutOfStock' state, it should display an 'Out of Stock' message and wait for the user to press the 'Return Coin' button"

## The Solution:

For this problem the solution implementation ends being quite simple, we just need to create an interface so all the states is conformed to a contract, and encapsulate the states inside the concrete class for this interface, so the context (vending machine) can change its behavuior based on the state it is agregated with.

## Pros:
 
 ✅ Follows the Single Resposability principle guideline.

 ✅ Follows the Open Closed principle guideline.

 ✅ Makes massive conditional classes easier to deal with.

 ✅ Helps decoupling high nested conditional.


## Cons:

 ❌ Not much useful for small number of states or changes.


### **Resource:**

 🔗 [Refactoring Guru (State)](https://refactoring.guru/design-patterns/state)
