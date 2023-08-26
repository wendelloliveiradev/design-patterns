// Computer Product
export interface Computer {
    cpu: string;
    motherboard: string;
    ram: string;
    hdd: string;
    gpu: string;
    power_supply: string;
    computer_case: string;
    cooling_system: string;
    monitor: string;
    keyboard: string;
    mouse: string;
}

// Computer Config Builder Interface
export interface ComputerConfigurationBuilder {
    setCPU(cpu: string): void;
    setMotherboard(motherboard: string): void;
    setRAM(ram: string): void;
    setHDD(hdd: string): void;
    setGPU(gpu: string): void;
    setPowerSupply(powerSupply: string): void;
    setCase(computerCase: string): void;
    setCoolingSystem(coolingSystem: string): void;
    setMonitor(monitor: string): void;
    setKeyboard(keyboard: string): void;
    setMouse(mouse: string): void;
}

// Builder Director Interface
export interface ComputerConfiguratorDirector {
    constructGamingPC(builder: ComputerConfigurationBuilder): void;
    constructOfficePC(builder: ComputerConfigurationBuilder): void;
}
