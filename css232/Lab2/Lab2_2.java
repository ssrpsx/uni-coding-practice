
import java.util.Scanner;

public class Lab2_2 {

    static class BankAccount {

        private String owner;
        private double balance;

        public BankAccount(String owner, double balance) {
            this.owner = owner;
            this.balance = balance;
        }

        public BankAccount(String owner) {
            this.owner = owner;
        }

        public BankAccount() {
            this.owner = "";
            balance = 0;
        }

        void show_balance() {
            System.out.print(balance);
        }

        void deposit(double amount) {
            System.out.println("Deposit: " + amount);
            balance += amount;
        }

        void withdraw(double amount) {
            if (balance > 0 && amount <= balance) {
                System.out.println("Withdraw: " + amount);
                balance -= amount;
            } else {
                System.out.println("Insufficient funds");
            }
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter your Name: ");
            String name = sc.next();
            System.out.print("Enter your balace: ");
            double balace = sc.nextInt();

            BankAccount ba = new BankAccount(name, balace);

            System.out.print("Deposit: ");
            double deposit = sc.nextInt();

            System.out.print("withdraw: ");
            double withdraw = sc.nextInt();

            System.out.println();
            System.out.println("Owner: " + ba.owner);
            ba.deposit(deposit);
            
            ba.withdraw(withdraw);

            System.out.print("Final Balance: ");
            ba.show_balance();
            sc.close();
        }
    }
}
