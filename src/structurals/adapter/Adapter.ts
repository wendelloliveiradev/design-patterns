import { PaymentGatwayA, PaymentGatwayB, PaymentGatewayAdapter } from './Interfaces';

// Assume this is a third party library, some external service or any strange implementation.
class PaymentGatwayBConcrete implements PaymentGatwayB {

    requestAuthorization(amount: number): void {
        console.log(`Requested authorization for the payment of: ${amount}`);
    }
    
    submitPayment(amount: number): void {
        console.log(`Submited payment of: ${amount}`);
    }
}

 /* This is the adapter, it implements the interface that the client knows,
 and makes the necessary translation for the strange payment gateway, work. */
 class PaymentGatewayAdapterConcrete implements PaymentGatewayAdapter {
    private extern_payment_gateway: PaymentGatwayB;

    constructor() {
        this.extern_payment_gateway = new PaymentGatwayBConcrete();
    }

    authorizePayment(amount: number): void {
        this.extern_payment_gateway.requestAuthorization(amount);
    }

    processPayment(amount: number): void {
        this.extern_payment_gateway.submitPayment(amount);
    }
}

// Here is a representation of the client, it knows the interface that the adapter implements.
function Client(payment: PaymentGatwayA): void {
    payment.authorizePayment(100);
    payment.processPayment(100);
}

const payment: PaymentGatwayA = new PaymentGatewayAdapterConcrete();
Client(payment);
