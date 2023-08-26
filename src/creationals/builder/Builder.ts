import { Computer, ComputerConfigurationBuilder, ComputerConfiguratorDirector } from "./Interfaces";

// The Concrete Computer Class represents the product created by the builder.
// Its field could be optional.
class ConcreteComputer implements Computer {
    cpu: string = '';
    motherboard: string = '';
    ram: string = '';
    hdd: string = '';
    gpu: string = '';
    power_supply: string = '';
    computer_case: string = '';
    cooling_system: string = '';
    monitor: string = '';
    keyboard: string = '';
    mouse: string = '';
}

// The Concrete Computer Configuration Builder Class implements the builder interface.
// It builds and assembles parts of the product by implementing the builder interface.
class ConcreteComputerConfigurationBuilder implements ComputerConfigurationBuilder {
    private computer: Computer;

    constructor() {
        this.computer = new ConcreteComputer();
    }

    setCPU(cpu: string): void {
        this.computer.cpu = cpu;
    }

    setMotherboard(motherboard: string): void {
        this.computer.motherboard = motherboard;
    }

    setRAM(ram: string): void {
        this.computer.ram = ram;
    }

    setHDD(hdd: string): void {
        this.computer.hdd = hdd;
    }

    setGPU(gpu: string): void {
        this.computer.gpu = gpu;
    }

    setPowerSupply(powerSupply: string): void {
        this.computer.power_supply = powerSupply;
    }

    setCase(computerCase: string): void {
        this.computer.computer_case = computerCase;
    }

    setCoolingSystem(coolingSystem: string): void {
        this.computer.cooling_system = coolingSystem;
    }

    setMonitor(monitor: string): void {
        this.computer.monitor = monitor;
    }

    setKeyboard(keyboard: string): void {
        this.computer.keyboard = keyboard;
    }

    setMouse(mouse: string): void {
        this.computer.mouse = mouse;
    }

    getComputer(): Computer {
        return this.computer;
    }
}

// The Director Class is responsible for calling the builder interface to build the product.
// It knows the interface and the steps to build the product.
class ConcreteComputerConfiguratorDirector implements ComputerConfiguratorDirector {
    constructGamingPC(builder: ComputerConfigurationBuilder): void {
        builder.setCPU('Intel Core i7-9700K');
        builder.setMotherboard('ASUS ROG Maximus XI Hero');
        builder.setRAM('Corsair Vengeance RGB Pro 32GB (4x8GB) DDR4 3200MHz');
        builder.setHDD('Samsung 970 EVO Plus 1TB');
        builder.setGPU('EVGA GeForce RTX 2080 Ti FTW3 Ultra Gaming');
        builder.setPowerSupply('Corsair RM850x 850W 80 Plus Gold');
        builder.setCase('NZXT H700i');
        builder.setCoolingSystem('NZXT Kraken X72');
        builder.setMonitor('ASUS ROG Swift PG27UQ');
        builder.setKeyboard('Corsair K95 RGB Platinum');
        builder.setMouse('Logitech G502 HERO');
    }

    constructOfficePC(builder: ComputerConfigurationBuilder): void {
        builder.setCPU('Intel Core i7-8700K');
        builder.setMotherboard('ASUS ROG Maximus XI Hero');
        builder.setRAM('Corsair Vengeance RGB Pro 32GB (4x8GB) DDR4 3200MHz');
        builder.setHDD('Samsung 970 EVO Plus 1TB');
        builder.setGPU('EVGA GeForce RTX 1080 Ti FTW3 Ultra Gaming');
        builder.setPowerSupply('Corsair RM550x 550W 80 Plus Gold');
        builder.setCase('NZ700i');
        builder.setCoolingSystem('NZ X72');
        builder.setMonitor('ASUS R PG27');
        builder.setKeyboard('Corsair K95');
        builder.setMouse('Logitech G500');
    }
}

// Client Code
const configurator_director = new ConcreteComputerConfiguratorDirector();
const gaming_pc_builder = new ConcreteComputerConfigurationBuilder();
const office_pc_builder = new ConcreteComputerConfigurationBuilder();

configurator_director.constructGamingPC(gaming_pc_builder);
configurator_director.constructOfficePC(office_pc_builder);

const gaming_pc: Computer = gaming_pc_builder.getComputer();
const office_pc: Computer = office_pc_builder.getComputer();

console.log(gaming_pc);
console.log(office_pc);