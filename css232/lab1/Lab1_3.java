import java.util.Scanner;

public class Lab1_3 {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    System.out.printf("%d\t", i * j);
                }
                System.out.print("\n");
            }
        }
    }
}
