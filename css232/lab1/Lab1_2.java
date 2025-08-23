
import java.util.Scanner;

public class Lab1_2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int result = 0;
        char op = sc.next().charAt(0);

        if (b == 0 && op == '/') {
            System.out.print("Division by zero");
        } 
        else {
            switch (op) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                default:
                    System.out.printf("No match!");
            }

            System.out.print(result);
            sc.close();
        }
    }
}
