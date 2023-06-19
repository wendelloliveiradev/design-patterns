import { Attributes, BaseAttibutes, Character, CharacterCreator } from "./Interfaces";

// Specialized Products Implementation
class CharacterWarrior implements Character {
    private warrior_attibutes: Attributes = BaseAttibutes;

    setCharacterAttributes(attributes?: Attributes): void {
        this.warrior_attibutes = attributes ?? BaseAttibutes;
    }

    attack(): void {
        console.log(`Warrior Performed an Attack of ${this.warrior_attibutes.attack}!`);
    }

    defend(): void {
        console.log(`Warrior Performed a Defense of ${this.warrior_attibutes.defense}!`);
    }
}

class CharacterMage implements Character {
    private mage_attibutes: Attributes = BaseAttibutes;

    setCharacterAttributes(attributes?: Attributes): void {
        this.mage_attibutes = attributes ?? BaseAttibutes;
    }

    attack(): void {
        console.log(`Mage Performed an Attack of ${this.mage_attibutes.attack}!`);
    }

    defend(): void {
        console.log(`Mage Performed a Defense of ${this.mage_attibutes.defense}!`);
    }
}

class CharacterArcher implements Character {
    private archer_attibutes: Attributes = BaseAttibutes;

    setCharacterAttributes(attributes: Attributes): void {
        this.archer_attibutes = attributes ?? BaseAttibutes;
    }

    attack(): void {
        console.log(`Archer Performed an Attack of ${this.archer_attibutes.attack}!`);
    }

    defend(): void {
        console.log(`Archer Performed a Defense of ${this.archer_attibutes.defense}!`);
    }
}

// Specialized Factories Implementation
class CharacterWarriorCreator extends CharacterCreator {
    factoryMethod(): Character {
        return new CharacterWarrior();
    }
}

class CharacterMageCreator extends CharacterCreator {
    factoryMethod(): Character {
        return new CharacterMage();
    }
}

class CharacterArcherCreator extends CharacterCreator {
    factoryMethod(): Character {
        return new CharacterArcher();
    }
}

// Client Code
function client(creator: CharacterCreator, attributes?: Attributes) {
    const new_char: Character = creator.create();
    new_char.setCharacterAttributes(attributes)

    creator.action(new_char);
}

/*  
    For creating a new character, we must to instantiate the Character Class Creator,
    then we pass it to the client, also if we want to set custom attributes, it can 
    be optianally passed to the client as well.
*/

// Creating a Warrior Factory
const warrior_creator: CharacterCreator = new CharacterWarriorCreator();

// With custom attributes
const new_warrior_attribute: Attributes = {
    attack: 150,
    defense: 80,
    attack_speed: 100,
    life: 200,
    mana: 77,
};

client(warrior_creator, new_warrior_attribute)

// Creating a Mage Factory, no custom attributes
const mage_creator: CharacterCreator = new CharacterMageCreator();
client(mage_creator)

// Creating a Archer Factory
const archer_creator: CharacterCreator = new CharacterArcherCreator();

// With custom attributes
const new_archer_attribute: Attributes = {
    attack: 170,
    defense: 60,
    attack_speed: 120,
    life: 150,
    mana: 100,
};

client(archer_creator, new_archer_attribute)