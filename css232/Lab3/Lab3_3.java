
interface Playable {

    void play();
}

class Guiter implements Playable {

    @Override
    public void play() {
        System.err.println("Playing the Guitar");
    }
}

class Piano implements Playable {

    @Override
    public void play() {
        System.err.println("Playing the Piano");
    }
}

public class Lab3_3 {

    public static void main(String[] args) {
        Playable guitar = new Guiter();
        Playable piano = new Piano();

        guitar.play();
        piano.play();
    }
}
