import java.util.Calendar;
import java.util.Scanner;
/**
 * @author ryzhao
 */
public class CalendarOutput
{
	public static int Days(int year,int month)
	{
	    int days=0;
	    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	    {
	        days = 31;
	    }
	    else if(month==4||month==6||month==9||month==11)
	    {
	        days = 30;
	    }
	    else if(month==2)
	    {
	        if(year%4==0||year%400==0&&year%100!=0)
	        {
	            days = 29;
	        }
	        else
	        {
	           days = 28;
	        }
	     }
	    return days;
   }
	public static void main(String[] args)
	{
		int i=0,year=0,month=0,days=0,week=0,choice=0,j=0;
		Scanner sc  = new Scanner(System.in);
	    Calendar newc = Calendar.getInstance();
		while(true)
		{
			System.out.println("Menu:\n1.查询某天星期\n2.打印某年日历\n3.退出程序\n请输入数字进行选择");
			choice=sc.nextInt();
			if(choice==1)
			{
				System.out.println("请输入年份");
				year=sc.nextInt();
				System.out.println("请输入月份");
				month=sc.nextInt();
				System.out.println("请输入日期");
				days=sc.nextInt();
				newc.set(year,month-1,days);
				week = newc.get(Calendar.DAY_OF_WEEK);
				switch(week)
				{
					case 1:
						System.out.print("星期日\n");
						break;
					case 2:
						System.out.print("星期一\n");
						break;
					case 3:	
						System.out.print("星期二\n");
						break;
					case 4:	
						System.out.print("星期三\n");
						break;
					case 5:	
						System.out.print("星期四\n");
						break;
					case 6:	
						System.out.print("星期五\n");
						break;
					case 7:	
						System.out.print("星期六\n");
						break;
					
				}
			}
			else if(choice==2)
			{
				System.out.println("请输入年份");
				year = sc.nextInt();
				for(j=0;j<12;j++)
				{
					System.out.println("-------------"+(j+1)+"月------------");
					days = Days(year,j+1);
				    newc.set(year,j,1);
				    week = newc.get(Calendar.DAY_OF_WEEK)-1;
				    int[] date =new int[40];
				    for(i=1;i<=days;i++)
				    {
				        date[week]=i;
				        week++;
				    }
				    System.out.println("日\t一\t二\t三\t四\t五\t六");
				    for(i=0;i<week;i++)
				    {
				    	if(date[i]!= 0)
				        {
				    		System.out.print(date[i]+"\t");
				    		if((i+1)%7==0)
				    		{
				    			System.out.println("\n");
				            }
				        }
				    	else
				        {
				    		System.out.print(" "+"\t");
				        }

				    }
				    System.out.println("\n");
				}
		  
			}
			else if(choice==3) break;
		}
		sc.close();
	}
	
   
}