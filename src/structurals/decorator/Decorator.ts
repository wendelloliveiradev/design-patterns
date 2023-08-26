import { Coffee } from "./Interfaces";

// Concrete implementation of the coffee interface
class CupOfCoffee implements Coffee {
    private cost: number = 1.5;
    private description: string = 'Cup Of Coffee';

    getCost(): number {
        return this.cost;
    }
    getDescription(): string {
        return this.description;
    }
}

// Abstract decorator class, implements the coffee interface
// we need it, because we want to be able to inject the decorators
// into each other, so we need a common interface
abstract class AbstractCoffee implements Coffee {
    protected coffee: Coffee;

    constructor(coffee: Coffee) {
        this.coffee = coffee;
    }

    abstract getCost(): number;
    abstract getDescription(): string;
}

class WhippedCream extends AbstractCoffee {
    private cost: number = 0.5;
    private description: string = 'Whipped Cream';

    getCost(): number {
        return this.coffee.getCost() + this.cost;
    }

    getDescription(): string {
        return this.coffee.getDescription() + ', ' + this.description;
    }
}

// Concrete decorator classes
class Caramel extends AbstractCoffee {
    private cost: number = 0.7;
    private description: string = 'Caramel';

    getCost(): number {
        return this.coffee.getCost() + this.cost;
    }
    getDescription(): string {
        return this.coffee.getDescription() + ', ' + this.description;
    }
}

// Concrete decorator classes
class HazelnutSyrup extends AbstractCoffee {
    private cost: number = 0.6;
    private description: string = 'Hazelnut Syrup';

    getCost(): number {
        return this.coffee.getCost() + this.cost;
    }
    getDescription(): string {
        return this.coffee.getDescription() + ', ' + this.description;
    }
}

// Client Code
const coffee = new CupOfCoffee();
console.log(coffee.getDescription(), coffee.getCost());

const coffee_cream = new WhippedCream(coffee);
console.log(coffee_cream.getDescription(), coffee_cream.getCost());

const coffee_cream_caramel = new Caramel(coffee_cream);
console.log(coffee_cream_caramel.getDescription(), coffee_cream_caramel.getCost());

const coffee_cream_caramel_syrup = new HazelnutSyrup(coffee_cream_caramel);
console.log(coffee_cream_caramel_syrup.getDescription(), coffee_cream_caramel_syrup.getCost());
