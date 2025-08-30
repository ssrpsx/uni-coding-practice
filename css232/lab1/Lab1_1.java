import java.util.Scanner;

public class Lab1_1 {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();

            if(n % 2 == 0)
            {
              System.out.print("Even");
            }
            else
            {
              System.out.print(("Odd"));
            }
        }
    }

}
