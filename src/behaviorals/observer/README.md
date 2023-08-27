# Wheather Monitoring System 

This repository solves the problem of having to notify multiples objects when a certain object state changes.

## The Problem:

"You are building a weather monitoring system that collects data from multiple weather stations and displays the weather information in real-time to users. The System needs to notify the display components whenever the weather data changes, so that they can update ther displays accordingly. You need to implement an Observer design pattern to establish a one-to-many relationship between the weather station (observable) and the display components (observers), allowing the display components to automatically receive updates from the weather stations and reflect the changes in their displays."

## The Solution:

We need to implement a WeatherSubscriber interface for each subscriber so every time that the Publisher state is changed, just calling the notify method in the publisher will fire the update for each subscriber registered to receive the update, this way we can separete the layers between a Publisher and many Subscribers, also the Publisher can be a subscriber to another publisher, this way we can funnel multiple weather station data to a single publisher and then notify the "users".

## Pros:
 
 ✅ Follow the Open Closed Principle guidelines.

 ✅ Allows extension and contraction to the subscriber list without breaking the code.

## Cons:

 ❌ The notifications is sequential, may not feed the users in real time.


### **Reference:**

 🔗 [Refactoring Guru (Observer)](https://refactoring.guru/design-patterns/observer)
