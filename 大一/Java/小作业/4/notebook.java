import java.util.ArrayList;
import java.util.Scanner;


public class notebook {
    static ArrayList<String> notebook = new ArrayList<String>();

    public static void main(String[] args) {
        int choice, num;
        String str;
        Scanner input = new Scanner(System.in);
        System.out.println("记事本功能");
        // 菜单
        while (true) {
            System.out.println("---------------------------------");
            System.out.println("| 1 - 记录			            |");
            System.out.println("| 2 - 修改记录		            |");
            System.out.println("| 3 - 查询记录数目			    |");
            System.out.println("| 4 - 查询记录内容			    |");
            System.out.println("| 5 - 显示所有记录	            |");
            System.out.println("| 6 - 删除已有记录	            |");
            System.out.println("| 7 - 删除所有记录			    |");
            System.out.println("| 0 - 退出程序				    |");
            System.out.println("---------------------------------");
            System.out.println("请输入序号以执行对应功能:");

            choice = input.nextInt();

            // 菜单对应功能的实现
            switch (choice){
                case 0:{
                    System.out.println("程序已经退出！");
                    input.close();
                    System.exit(0);
                    break;
                }
                case 1 :{
                    System.out.println("请输入记录内容：");
                    input.nextLine();
                    str = input.nextLine();
                    notebook.add(str);
                    System.out.println("已记录！");
                    break;
                }
                case 2 : {
                    System.out.println("请输入需要修改的记录序号");
                    num = input.nextInt();
                    System.out.println("请输入修改后的内容：");
                    input.nextLine();
                    str = input.nextLine();
                    notebook.set(num-1, str);
                    System.out.println("修改成功！");
                    break;
                }
                case 3 :{
                    System.out.println("已记录数目为："+notebook.size()+"。");
                    break;
                }
                case 4 :{
                    System.out.println("请输入需要查看的记录序号");
                    num = input.nextInt();
                    showText(notebook,num);
                    break;
                }
                case 5 :{
                    showText(notebook,0);
                    break;
                }
                case 6 :{
                    System.out.println("请输入删除查看的记录序号");
                    num = input.nextInt();
                    deleteText(notebook,num);
                    break;
                }
                case 7 :{
                    deleteText(notebook,0);
                    break;
                }
                default:{
                    System.out.println("没有对应功能，请检查后重新输入！");
                    break;
                }
            }

        }
    }
    // 显示记录条目
    public static void showText(ArrayList<String> text,int n){
        if(text.isEmpty()){
            System.out.println("当前还没有记录。");
        }
        else {
            if (n == 0) {
                for (int i = 0; i < text.size(); i++) {
                    System.out.println((i+1)+":"+notebook.get(i));
                }
            }else if (n > 0 && n <= text.size()) {
                System.out.println(n+":"+notebook.get(n-1));
            }else {
                System.out.println("输入有误，请重新输入！");
            }
        }
    }
    // 删除记录条目
    public static void deleteText(ArrayList<String> text,int n){
        if (text.isEmpty()) {
            System.out.println("当前无记录");
        }else {
            if(n==0){
                text.clear();
                System.out.println("已经清除全部记录");
            }else if (n > 0 && n<= text.size()) {
                text.remove(n-1);
                System.out.println("已经清除第"+n+"条记录");
            }else {
                System.out.println("输入错误，请重新输入！");
            }
        }
    }
}
