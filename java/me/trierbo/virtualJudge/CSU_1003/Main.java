package me.trierbo.virtualJudge.CSU_1003;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        String status;
        for (int i = 0; i < num; i++) {
            int days = scanner.nextInt();
            status = scanner.next();
            int experience = 0;
            int flag = 0;
            for (int j = 0; j < days; j++) {
                if (status.length() > j && status.charAt(j) == '1') {
                    flag++;
                    if (flag > 5) {
                        flag -= 5;
                        experience += flag * 10;
                    } else
                        experience += flag * 10;
                } else
                    flag = 0;
            }
            if (experience >= 750)
                System.out.println(8);
            else
                System.out.println((experience + 50) / 100);
        }
    }
}
