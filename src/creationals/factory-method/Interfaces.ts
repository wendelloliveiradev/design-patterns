export type Attributes = {
    attack: number;
    defense: number;
    attack_speed: number;
    life: number;
    mana: number;
}

export const BaseAttibutes: Attributes = {
    attack: 100,
    defense: 100,
    attack_speed: 100,
    life: 100,
    mana: 100,
}

// Each Character can be seen as a product in the Factory Method structure
export interface Character {
    setCharacterAttributes(attributes?: Attributes): void;
    attack(): void;
    defend(): void;
};

// Each Character Creator can be seen as a factory in the Factory Method structure
export abstract class CharacterCreator {
    abstract factoryMethod(): Character;

    create(): Character {
        return this.factoryMethod();
    }

    action(character: Character): void {
        character.attack();
        character.defend();
    }
}