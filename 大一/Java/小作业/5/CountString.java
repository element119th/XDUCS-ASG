import java.io.File;
import java.util.Scanner;
import java.util.regex.Pattern;


public class CountString {
    private static boolean isletter(char letter) {
        return (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z');
    }

    static int countletter(File file) throws Exception {
        Scanner input = new Scanner(file);
        int sum = 0;
        while (input.hasNext()) {
            String str = input.next();
            char[] a = str.toCharArray();
            for (char c : a) {
                if (isletter(c)) {
                    sum++;
                }
            }
        }
        input.close();
        return sum;
    }

    static int countstring(File file) throws Exception {
        Scanner input = new Scanner(file);
        int sum = 0;
        while (input.hasNext()) {
            input.next();
            sum++;
        }
        input.close();
        return sum;
    }

    public static void loop() throws Exception {
        Scanner in = new Scanner(System.in);
        System.out.println("待统计文本请与本java文件放于同一目录下！");
        System.out.println("请输入需要统计的文本文件名称：(不需要输入后缀)");
        String filename = in.nextLine();
        File file = new File("src/" + filename + ".txt");
        if (!file.exists()) {
            System.out.println("没有该文件，请检查输入！");
            System.exit(0);
        }
        Scanner in2 = new Scanner(System.in);
        System.out.println("菜单：\n1.统计英文字符数目；\n2.统计字符串数目；\n3.统计全部信息；\n4.退出。");
        System.out.println("已匹配到该文件，请输入菜单序号以继续：");
        int choice = in2.nextInt();
        switch (choice) {
            case 1: {
                System.out.println("文件中的英文字符个数为：" + CountString.countletter(file));
                break;
            }
            case 2: {
                System.out.println("文件中的字符串个数为：" + CountString.countstring(file));
                break;
            }
            case 3: {
                System.out.println("文件中的英文字符个数为：" + CountString.countletter(file));
                System.out.println("文件中的字符串个数为：" + CountString.countstring(file));
                break;
            }
            case 4: {
                System.out.println("程序已退出！");
                System.exit(0);
                break;
            }
            default: {
                System.out.println("没有该选项，请重新选择！");
                break;
            }
        }
        in.close();
        in2.close();
    }

    public static void main(String[] args) throws Exception {
        loop();
    }
}
