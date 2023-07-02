export interface VendingMachineContext {
    setState: (state: VendingMachineState) => void;
    action: () => void;
}

export interface VendingMachineState {
    behaviour(): void;
}
