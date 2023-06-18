// PaymentGatwayA is known by the client code
export interface PaymentGatwayA {
    authorizePayment(amount: number): void;
    processPayment(amount: number): void;
}

// PaymentGatwayB represents the incompatible interface
export interface PaymentGatwayB {
    requestAuthorization(amount: number): void;
    submitPayment(amount: number): void;
} 

export interface PaymentGatewayAdapter extends PaymentGatwayA {}