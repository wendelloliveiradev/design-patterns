# Payment Gateway Adapter

This repository solves a problem of incompatible interface using an adapter implementation that allows seamless integration between two different interfaces of payment system. The adapter provides a unified interface, enabling easy switching between the two gateways without altering the core logic of the system.

## The Problem:

"You are working on a project that involves integrating two different payment gateways, PaymentGatewayA and PaymentGatewayB, into your system. However, they have different interfaces and methods for processing payments. PaymentGatewayA has methods `authorizePayment(amout)` and `processPayment(amount)`, while PaymentGatewayB has methods `requestAuthorization(amount)` and `submitPayment(amount)`.

Your task is to implement an adapter that allows your system to work seamlessly with both payment gateways using an unified interface, so that you can switch between them easily without changing the core logic of your payment processing system. The adapter should implement a common interface, `PaymentGatewayAdapter`, with methods `authorizePayments(amount)` and `processPayment(amount)` that internally use the appropriate methods of PaymentGatewayA or PaymentGatewayB based on the specif adapter being used.

The adapter should internally utilize the appropriate methods of PaymentGatewayA or PaymentGatewayB based on the specific adapter being used."

## The Solution:

We created an intermediate interface that inherites the interface known by the Client. And then we compose it with the unknown interface, that could be a strange interface for payment, an external library or legacy code, so when the known methods are called for the adapter payment class, it will "translate" to the corresponding methods.



## Pros:
 
 ✅ Follow the Sigle Resposability Principle guideline.

 ✅ Follow the Open Closed Principle guideline.

## Cons:

 ❌ May greatly increase the code complexity.


### **Reference:**

 🔗 [Refactoring Guru (Adapter)](https://refactoring.guru/design-patterns/adapter)
