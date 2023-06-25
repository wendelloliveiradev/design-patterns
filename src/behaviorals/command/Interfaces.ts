// Defines the main contract for the objects that encapsulate the actions to be executed.
export interface Command {
    execute(): void;
}

// Defines the objects that sends the specific command aka Controller.
export interface CommandInvoker {
    execute(command: Command): void;
}

// The objects that are going to have its internal state changed by the commands.
export interface CommandReceiver {
    action(): void;
}
