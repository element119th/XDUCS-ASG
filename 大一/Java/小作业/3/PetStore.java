import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


abstract  class Pet{
    private String name;
    public static int id = 1;
    public Pet(String name){
        this.name = name;
    }
    public String GetName(){
        return name;
    }
    public static String getspecies(Pet pet){
        if(pet instanceof Dog) {
            return "狗";
        }
        else if (pet instanceof Cat) {
            return "猫";
        }
        else if (pet instanceof Bird) {
            return "鸟";
        }else{
            return "其他";
        }
    }
    public abstract void feed();
    public abstract int getid();
}
class Dog extends Pet {
    int iD =id++;
    public Dog(String name){
        super(name);
    }
    @Override
    public int getid() {
        return iD;
    }
    @Override
    public void feed(){
        System.out.println("饲喂成功！");
    }
}
class Cat extends Pet {
    int iD =id++;
    public Cat(String name){
        super(name);
    }
    @Override
    public int getid() {
        return iD;
    }
    @Override
    public void feed(){
        System.out.println("饲喂成功！");
    }
}
class Bird extends Pet {
    int iD =id++;
    public Bird(String name){
        super(name);
    }
    @Override
    public int getid() {
        return iD;
    }
    @Override
    public void feed(){
        System.out.println("饲喂成功！");
    }
}
class Other extends Pet {
    int iD =id++;
    public Other(String name){
        super(name);
    }
    @Override
    public int getid() {
        return iD;
    }
    @Override
    public void feed(){
        System.out.println("饲喂成功！");
    }
}

public class PetStore {
    public static void main(String[] args) {
        List<Pet> petlist = new ArrayList<Pet>();
        while (true) {
            System.out.println("菜单：\n1.寄养宠物\n2.查询宠物信息\n3.查看前n个宠物信息\n4.饲喂宠物\n5.领走宠物\n6.退出\n请输入序号以继续：");
            Scanner sc = new Scanner(System.in);
            int choice = sc.nextInt();
            if (choice == 6) {
                break;
            }
            if (choice == 1) {
                System.out.println("1.寄养一只狗\n2.寄养一只猫\n3.寄养一只鸟\n4.寄养其他宠物\n5.返回上一步\n请输入序号以继续：");
                int choice2 = sc.nextInt();
                if (choice2 == 1) {
                    System.out.println("请输入宠物的名字：");
                    Pet dog = new Dog(sc.next());
                    petlist.add(dog);
                    System.out.println("您的小狗" + dog.GetName() + "成功寄养！");
                }
                if (choice2 == 2) {
                    System.out.println("请输入宠物的名字：");
                    Pet cat = new Cat(sc.next());
                    petlist.add(cat);
                    System.out.println("您的小猫" + cat.GetName() + "成功寄养！");
                }
                if (choice2 == 3) {
                    System.out.println("请输入宠物的名字：");
                    Pet bird = new Bird(sc.next());
                    petlist.add(bird);
                    System.out.println("您的小鸟" + bird.GetName() + "成功寄养！");
                }
                if (choice2 == 4) {
                    System.out.println("请输入宠物的名字：");
                    Pet other = new Other(sc.next());
                    petlist.add(other);
                    System.out.println("您的宠物" + other.GetName() + "成功寄养！");
                } else {
                    continue;
                }
            } else if (choice == 2) {
                int flag = 0;
                System.out.println("请输入宠物名字以继续：");
                String name = sc.next();
                for(int i=0;i<petlist.size();++i) {
                    if(petlist.get(i).GetName().equals(name)) {
                        System.out.println("类型："+Pet.getspecies(petlist.get(i))+" 序号："+petlist.get(i).getid());
                    }
                }
                if (flag == 0) {
                    System.out.println("没有查询到该宠物！");
                }
            } else if (choice == 3) {
                System.out.println("请输入序号：");
                int num = sc.nextInt();
                for (int i = 1; i < num; i++) {
                    for (int j = 0; j < petlist.size(); j++) {
                        System.out.println("ID：" + petlist.get(j).getid() + " 种类：" + Pet.getspecies(petlist.get(i)) + " 名字：" + petlist.get(j).GetName());
                    }
                }
            } else if (choice == 5) {
                int flag = 0;
                System.out.println("请输入宠物名字：");
                String name = sc.next();
                for (Pet pet : petlist) {
                    int i = 0;
                    if (pet.GetName().equals(name)) {
                        System.out.println("您的" + Pet.getspecies(pet) + pet.GetName() + " 序号：" + pet.getid() + "已经领走！");
                        flag = 1;
                        petlist.remove(i);
                        break;
                    }
                    i++;
                }
                if (flag == 0) {
                    System.out.println("没有查询到该宠物！");
                }
            } else if (choice == 4) {
                int flag=0;
                System.out.println("请输入您要饲喂的宠物名字：");
                String name = sc.next();
                for (Pet pet : petlist) {
                    int i = 0;
                    if (pet.GetName().equals(name)) {
                        System.out.println("您的" + pet.GetName() + "饲喂成功！");
                        flag = 1;
                        break;
                    }
                    i++;
                }
                if (flag == 0) {
                    System.out.println("没有查询到该宠物！");
                }
            }
        }
    }
}

