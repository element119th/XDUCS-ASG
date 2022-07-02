import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;


public class MyCalendarOutput {
    public static int Days(int year, int month) {
        int days = 0;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            days = 31;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days = 30;
        } else if (month == 2) {
            if (year % 4 == 0 || year % 400 == 0 && year % 100 != 0) {
                days = 29;
            } else {
                days = 28;
            }
        }
        return days;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DateFormat dateformat = new SimpleDateFormat("yyy-MM-dd");
        boolean flag = true;
        Date date = null;
        System.out.println("菜单：\n1.查询某天日期\n2.查询某年日历\n请选择序号:");
        int choice = scanner.nextInt();
        if (choice == 1) {
            while (flag) {
                System.out.println("请输入日期：（格式：年-月-日）");
                String datetime = scanner.next();
                try {
                    date = dateformat.parse(datetime);
                    flag = false;
                } catch (ParseException e) {
                    System.out.println("日期格式错误，请重新输入");
                }
            }
            Calendar c = new GregorianCalendar();
            c.setTime(date);
            int week = c.get(Calendar.DAY_OF_WEEK);
            switch (week) {
                case 1 -> System.out.print("星期日\n");
                case 2 -> System.out.print("星期一\n");
                case 3 -> System.out.print("星期二\n");
                case 4 -> System.out.print("星期三\n");
                case 5 -> System.out.print("星期四\n");
                case 6 -> System.out.print("星期五\n");
                case 7 -> System.out.print("星期六\n");
            }
        } else if (choice == 2) {
            System.out.println("请输入年份：\n");
            int year = scanner.nextInt();
            for (int i = 0; i < 12; i++) {
                System.out.println("------------------------" + (i + 1) + "-------------------------");
                int days = Days(year, i + 1);
                Calendar calendar = Calendar.getInstance();
                calendar.set(year, i, 1);
                int week = calendar.get(Calendar.DAY_OF_WEEK) - 1;
                int[] dated = new int[40];
                for (int j = 0; j < days; j++) {
                    dated[week] = j + 1;
                    week++;
                }
                System.out.println("日\t一\t二\t三\t四\t五\t六");
                for (int j = 0; j < week; j++) {
                    if (dated[j] != 0) {
                        System.out.print(dated[j] + "\t");
                        if ((j + 1) % 7 == 0) {
                            System.out.print("\n");
                        }
                    } else {
                        System.out.print(" \t");
                    }
                }
                System.out.println("\n");

            }
        } else {
            System.out.println("没有该选项！");
        }
        scanner.close();
    }
}