import java.util.Scanner;

public class Num_Check {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);// Scanner object
        System.out.print("Enter your number to checked => ");
        int n = sc.nextInt();// User's values
        int copy = n;// Copying the original number
        System.out.print(
                "Enter 1 for Palindrome, 2 for Krishnamurthy Number & 3 for Armstrong number.\nWhat is your choice? =>");
        int ch = sc.nextInt();// Number checking choice
        switch (ch) {
            case 1: {
                System.out.print("Palindrome Number Checking:\n");
                int rev = 0, d = 0;
                while (copy > 0) {
                    d = copy % 10;// Digit extract
                    rev = (rev * 10) + d;// Reversing
                    copy /= 10;// updating
                }
                if (rev == n)// Reversed num == Original number??
                    System.out.println(n + " is a Palindrome Number.");
                else
                    System.out.println(n + " isn't a Palindrome Number.");
            }
                break;
            case 2: {
                System.out.print("Krishnamurthy Number Checking:\n");
                int d = 0, sum = 0, pro = 1;
                while (copy > 0) {
                    pro = 1;// Refreshing
                    d = copy % 10;// Digit extract
                    for (int i = d; i > 0; i--)
                        pro *= i;// Factorial making
                    sum += pro;
                    copy /= 10;// Updating
                    pro = 1;// Refreshing
                }
                if (sum == n)// sum of digit factorials==original number??
                    System.out.print(n + " is a Krishnamurthy Number.");
                else
                    System.out.print(n + " isn't a Krishnamurthy Number.");
            }
                break;
            case 3: {
                System.out.print("Armstrong Number Checking:\n");
                int d = 0, sum = 0;
                while (copy > 0) {
                    d = copy % 10;// Digit extract
                    sum += (d * d * d);// Cube sum
                    copy /= 10;// Updating

                }
                if (sum == n)// sum of digit factorials==original number??
                    System.out.print(n + " is a Armstrong Number.");
                else
                    System.out.print(n + " isn't a Armstrong Number.");
            }
        }

    }
}