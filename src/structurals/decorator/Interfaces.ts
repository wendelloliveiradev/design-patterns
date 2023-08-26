// Coffee interface, will be implemented by the basic coffee and the decorators
export interface Coffee {
    getCost(): number;
    getDescription(): string;
}