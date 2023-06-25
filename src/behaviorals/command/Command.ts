import { Command, CommandInvoker, CommandReceiver } from "./Interfaces";

// The end layer that has its internal state changed by the commands.
class Lights implements CommandReceiver {
    private is_on: boolean = false;

    public on(): void {
        this.is_on = true;
        console.log('Lights are on');
    }

    public off(): void {
        this.is_on = false;
        console.log('Lights are off');
    }

    public action(): void {
        if (this.is_on)
            this.off();
         else
            this.on();
    }
}

class Thermostat implements CommandReceiver {
    private temperature: number = 20;

    public action(): void {
        this.temperature = this.temperature === 20 ? 25 : 20;
        console.log(`Temperature is ${this.temperature} degrees`);
    }
}

class SecuritySystem implements CommandReceiver {
    private isArmed: boolean = false;

    public action(): void {
        if (this.isArmed)
            this.disarm();
        else
            this.arm();
    }

    public arm(): void {
        this.isArmed = true;
        console.log('Security system is armed');
    }

    public disarm(): void {
        this.isArmed = false;
        console.log('Security system is disarmed');
    }
}

// The objects that encapsulate the actions to be executed.
class TurnLightsOnCommand implements Command {
    constructor(private receiver: CommandReceiver) {}

    public execute(): void {
        this.receiver.action();
    }
}

class TurnLightsOffCommand implements Command {
    constructor(private receiver: CommandReceiver) {}

    public execute(): void {
        this.receiver.action();
    }
}

class SetThermostatCommand implements Command {
    constructor(private receiver: CommandReceiver) {}

    public execute(): void {
        this.receiver.action();
    }
}

class ArmSecuritySystemCommand implements Command {
    constructor(private receiver: CommandReceiver) {}

    public execute(): void {
        this.receiver.action();
    }

    public undo(): void {
        this.receiver.action();
    }
}

class DisarmSecuritySystemCommand implements Command {
    constructor(private receiver: CommandReceiver) {}

    public execute(): void {
        this.receiver.action();
    }
}

// The Controller that are going to manage the commands.
class Controller implements CommandInvoker {
    private commands: Command[] = [];

    public execute(command: Command): void {
        command.execute();
        this.commands.push(command);
    }
}


// Client code
const controller = new Controller();
const lights = new Lights();
const thermostat = new Thermostat();
const security_system = new SecuritySystem();

controller.execute(new TurnLightsOnCommand(lights));
controller.execute(new SetThermostatCommand(thermostat));
controller.execute(new ArmSecuritySystemCommand(security_system));
controller.execute(new DisarmSecuritySystemCommand(security_system));
controller.execute(new TurnLightsOffCommand(lights));