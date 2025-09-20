
abstract class Pet {

    String name;

    public Pet(String name) {
        this.name = name;
    }

    abstract void sound();
}

class Dog extends Pet {

    public Dog(String name) {
        super(name);
    }

    @Override
    void sound() {
        System.err.println(name + "says Woof");
    }
}

class Cat extends Pet {

    public Cat(String name) {
        super(name);
    }

    @Override
    void sound() {
        System.err.println(name + "says Meow");
    }
}

public class Lab3_2 {

    public static void main(String[] args) {
        Pet dog = new Dog("buddy ");
        Pet cat = new Cat("Kitty ");

        dog.sound();
        cat.sound();
    }
}
