import { AttackStrategy } from "./Interfaces";

// Concrete character melee attack type.
class MeleeAttack implements AttackStrategy {
    attack(): void {
        console.log("Melee Attack Performed!");
    }
}

// Concrete character magic attack type.
class MagicAttack implements AttackStrategy {
    attack(): void {
        console.log("Magic Attack Performed!");
    }
}

// Concrete character ranged attack type.
class RangedAttack implements AttackStrategy {
    attack(): void {
        console.log("Ranged Attack Performed!");
    }
}

// Context class.
class Character {
    private character_attack: AttackStrategy;

    constructor(character_attack: AttackStrategy) {
        this.character_attack = character_attack;
    }

    setAttackType(character_attack: AttackStrategy) {
        this.character_attack = character_attack;
    }

    attack(): void {
        this.character_attack.attack();
    }
}

// Client Code:
function client() {
    const character: Character = new Character(new MeleeAttack());

    // Calling Melee attack
    character.attack();

    // Switching attack to Magic
    character.setAttackType(new MagicAttack());

    // Calling Magic attack
    character.attack();
    
    // Switching attack to ranged
    character.setAttackType(new RangedAttack());

    // Calling Ranged attack
    character.attack();

    // Going back to Melee
    character.setAttackType(new MeleeAttack);
    character.attack();
}

client();