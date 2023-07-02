import { VendingMachineState } from "./Interfaces";

class Idle implements VendingMachineState {
    public behaviour(): void {
        console.log("The vending machine is in Idle State");
    }
}

class HasCoin implements VendingMachineState {
    public behaviour(): void {
        console.log("The vending machine is in HasCoin State");
    }
}

class Dispensing implements VendingMachineState {
    public behaviour(): void {
        console.log("The vending machine is in Dispensing State");
    }
}

class OutOfStock implements VendingMachineState {
    public behaviour(): void {
        console.log("The vending machine is in OutOfStock State");
    }
}

class VendingMachineContext {
    private state: VendingMachineState;

    constructor() {
        this.state = new Idle();
    }

    public setState(state: VendingMachineState): void {
        this.state = state;
    }

    public action(): void {
        // this Context could be passed as an argument to the State
        // so that the State could change the Context's state or
        // get the Context's data
        this.state.behaviour();
    }
}

//Client Code

// How it state is changed only when user performs an action
// there is no need to change the state in chain
const vending_machine = new VendingMachineContext();
vending_machine.action(); // The vending machine is in Idle State
vending_machine.setState(new HasCoin());
vending_machine.action(); // The vending machine is in HasCoin State
vending_machine.setState(new Dispensing());
vending_machine.action(); // The vending machine is in Dispensing State
vending_machine.setState(new OutOfStock());
vending_machine.action(); // The vending machine is in OutOfStock State
