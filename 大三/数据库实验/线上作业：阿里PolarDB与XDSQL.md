# 						 线上作业：阿里PolarDB与XDSQL



## 实验一 数据库远程连接实验

### 一、实验目的

​	熟悉PolarDB for MySQL使用方式，了解阿里云dms实验平台，并学会使用Python或Java语言实现对数据库的远程连接操作

 

### 二、实验步骤

1. 登录阿里云dms控制台，dms控制台网址为https://dmslab.aliyun.com/

   <img src="https://ucc.alicdn.com/pic/developer-ecology/d80ad95b372e46f3b14d1aeeb6531972.png" style="zoom:80%;" />

   

2. 开通PolarDB for MySQL数据库，开通后系统会默认生成三个数据表，分别是courses、students、student_course表

   ![](https://ucc.alicdn.com/pic/developer-ecology/c817c79828a24471976782f8e40e10cb.png)

   ![](https://ucc.alicdn.com/pic/developer-ecology/19a4cdfad0474037960ba1b8224097b6.png)

   

3. 右键点击侧边栏中PolarDB for MySQL，在弹出的菜单栏中点击开通应用程序访问，获取连接信息

   ![](https://ucc.alicdn.com/pic/developer-ecology/ab147ed4a4934d90a64182f39bc80775.jpeg)

   

4. 根据连接信息提示，使用Python或Java实现对数据库的远程访访问

   ![image-20220102220909935](C:\Users\wddws\AppData\Roaming\Typora\typora-user-images\image-20220102220909935.png)

 

## 三、Python 连接数据库

1. 安装Python，版本3.6.5以上即可

2. ![image-20220102095619341](D:\OneDrive - stu.xidian.edu.cn\XDU\实验报告\微机原理实验\图片1.png)

   ​                                        

2. 在命令行中输入以下语句，安装pymysql模块                              

```python
 pip install pymysql
```

3. 当X或Y值为0\~9H时，需要加上调整值30H；当X或Y值为A\~FH时，需要加上调整值37H。 据此，则可将其进行转换为ASCII码值。

   ![image-20220102095619341](D:\OneDrive - stu.xidian.edu.cn\XDU\实验报告\微机原理实验\图片3.png)

   

4. 程序员开始，使用系统调用功能输出自己的学号姓名信息

   ```assembly
   START:
   		mov   ax,data
   		mov   ds,ax
   		mov   ah,09h
   		mov   dx,offset buffer
   		int   21h
   		mov   si,offset buffer2
   ```

5. 实验一的核心内容是进行 ASCII 码的转换与显示，因此，我设计了 `showascii` 子程序。调用子程序，便可将 AX 寄存器中存放的 ASCII 码值显示到屏幕上，先显示高四位，再显示低四位

   ```assembly
   showascii:
   		cmp   byte ptr [si],'$'
   		je    showinputasc
   		
   		mov   ah,09h
   		mov   dx,offset showch
   		int   21h
   		mov   al,ds:[si]
   		mov   dl,al
   		mov   ah,02h
   		int   21h
   		
   		mov   ah,09h
   		mov   dx,offset space
   		int   21h
   		
   		mov   ah,09h
   		mov   dx,offset showasc
   		int   21h
   		
   		mov   al,ds:[si]
   		mov   dl,al
   		and   al,0f0h
   		mov   cl,4
   		shr   al,cl
   		cmp   al,0ah
   		jb    showhigh
   		add   al,07h
   showhigh:
   		add   al,30h
   		mov   dl,al
   		mov   ah,02h
   		int   21h
   		mov   al,ds:[si]
   		and   al,0fh
   		cmp   al,0ah
   		jb    showlow
   		add   al,07h
   showlow:
   		add   al,30h
   		mov   dl,al
   		mov   ah,02h
   		int   21h
   		
   		mov   ah,09h
   		mov   dx,offset endl
   		int   21h
   		
   		add   si,1
   		jmp   showascii
   ```

6. 在基础实验的要求上，我又设计实现了对对应字符的 ascii 码转换，使用 `showinputasc` 函数检测输入并调用 ascii 码表输出子程序，通过循环操作对 ASCII 码表进行输出

   ````assembly
   showinputasc:
   		mov   ah,09h
   		mov   dx,offset endl
   		int   21h
   		
   		mov   ah,09h
   		mov   dx,offset showinput
   		int   21h
   		
   		mov   ah,01h
   		int   21h
   		
   		cmp   al,'q'
   		je    proend
   		cmp   al,'q'
   		je    proend
   		mov   bl,al
   		
   		mov   ah,09h
   		mov   dx,offset endl
   		int   21h
   		mov   ah,09h
   		mov   dx,offset showasc
   		int   21h
   		
   		mov   al,bl
   		and   al,0f0h
   		mov   cl,4
   		shr   al,cl
   		cmp   al,0ah
   		jb    showhigh1
   		add   al,07h
   showhigh1:
   		add   al,30h
   		mov   dl,al
   		mov   ah,02h
   		int   21h
   		mov   al,bl
   		and   al,0ah
   		jb    showlow1
   		add   al,07h
   showlow1:
   		add   al,30h
   		mov   dl,al
   		mov   ah,02h
   		int   21h
   		jmp   showinputasc
   ````



## 五、完整源代码

### 完整源代码：

```asm
STACK1 SEGMENT STACK
STACK1 ENDS

DATA SEGMENT
	buffer     DB '19160100027 WANGSHIZHENG',0ah,0dh,'$'
	buffer2    DB '114514','$'
	showch     DB 'The character is: ','$'
	showasc    DB 'The ascii is: ','$'
	showinput  DB 'Your input is: ','$'
	endl       DB 0ah,0dh,'$'
	space      DB 20h,'$'
DATA ENDS

CODE SEGMENT
		assume ss:stack1,cs:code,ds:data
	START:
		mov   ax,data
		mov   ds,ax
		mov   ah,09h
		mov   dx,offset buffer
		int   21h
		mov   si,offset buffer2
	showascii:
		cmp   byte ptr [si],'$'
		je    showinputasc
		
		mov   ah,09h
		mov   dx,offset showch
		int   21h
		mov   al,ds:[si]
		mov   dl,al
		mov   ah,02h
		int   21h
		
		mov   ah,09h
		mov   dx,offset space
		int   21h
		
		mov   ah,09h
		mov   dx,offset showasc
		int   21h
		
		mov   al,ds:[si]
		mov   dl,al
		and   al,0f0h
		mov   cl,4
		shr   al,cl
		cmp   al,0ah
		jb    showhigh
		add   al,07h
	showhigh:
		add   al,30h
		mov   dl,al
		mov   ah,02h
		int   21h
		mov   al,ds:[si]
		and   al,0fh
		cmp   al,0ah
		jb    showlow
		add   al,07h
	showlow:
		add   al,30h
		mov   dl,al
		mov   ah,02h
		int   21h
		
		mov   ah,09h
		mov   dx,offset endl
		int   21h
		
		add   si,1
		jmp   showascii
	showinputasc:
		mov   ah,09h
		mov   dx,offset endl
		int   21h
		
		mov   ah,09h
		mov   dx,offset showinput
		int   21h
		
		mov   ah,01h
		int   21h
		
		cmp   al,'q'
		je    proend
		cmp   al,'q'
		je    proend
		mov   bl,al
		
		mov   ah,09h
		mov   dx,offset endl
		int   21h
		mov   ah,09h
		mov   dx,offset showasc
		int   21h
		
		mov   al,bl
		and   al,0f0h
		mov   cl,4
		shr   al,cl
		cmp   al,0ah
		jb    showhigh1
		add   al,07h
	showhigh1:
		add   al,30h
		mov   dl,al
		mov   ah,02h
		int   21h
		mov   al,bl
		and   al,0ah
		jb    showlow1
		add   al,07h
	showlow1:
		add   al,30h
		mov   dl,al
		mov   ah,02h
		int   21h
		jmp   showinputasc
	proend:
		mov   ah,4ch
		int   21h
		
CODE ENDS
END START
```



# 								  实验二 数码转换实验

## 一、实验目的

1. 掌握不同进制数及编码相互转换的程序设计方法。
2. 掌握运算类指令编程及调试方法。
3. 掌握循环程序的设计方法。

 

## 二、实验内容

1. 重复从键盘输入不超过5位的十进制数，按回车键结束输入；

2. 将该十进制数转换成二进制数；结果以2进制数的形式显示在屏幕上；

3. 如果输入非数字字符，则报告出错信息，重新输入；

4. 直到输入“Q”或‘q’时程序运行结束。
5. 键盘输入一字符串，以空格结束，统计其中数字字符的个数，在屏幕显示。

 

## 三、实验原理

十进制数可以表示为：  
$$
D_n*10^n+D_{n-1}*10^{n-1}+…+D_0*10^0 = \sum D_i*10^i
$$
其中 Di 代表十进制数 1、2、3、…、9、0。

上式可以转换为：   
$$
\sum D_i*10^i = (((D_{n}*10+D_{n-1})*10+D_{n-2})*10+...+D_1)*10+D_0
$$
由上式可归纳出十进制数转换为二进制数的方法：从十进制数的最高位Dn开始做乘10加次位的操作，依此类推，则可求出二进制数结果。

![image-20220102095619341](D:\OneDrive - stu.xidian.edu.cn\XDU\实验报告\微机原理实验\图片4.png)

​                 ![image-20220102095619341](D:\OneDrive - stu.xidian.edu.cn\XDU\实验报告\微机原理实验\图片5.png)                   



##  四、实验过程

1. 通过 int 21H 中断的 0AH 号功能实现字符串的读入。读入的内容会以 ASCII 码的形式存放在 dx 寄存器所指向的内存单元中。因此需要提前获取足够大小的空间来存放读入的字符串

   ```assembly
   mov dx, offset INPUT
   mov ah, 0AH
   int 21H
   mov bx,offset INPUT+1
   mov cx,[bx]      
   mov ch,0
   mov dx, offset INPUT+2
   ```

   这样操作后，cx 寄存器存放了读取的字符串长度，dx 寄存器存放了字符串的起始地址

2. 编写十进制转二进制子程序，根据实验原理，通过移位和乘法运算，实现到二进制的转换

   ```assembly
   Binary proc
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
   ;  10 进制转二进制子程序
   ;   ax: 返回的8位二进制数
   ;   dx：ASCII 形式的 10 进制字符串位置
   ;   cx: 10 进制字符串长度
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
       push bx
       push cx
       push dx ;保护现场
       push si
       push dx
   
       mov bx,0
       mov si,dx
       mov ah, 0
       mov al,[si]
       sub ax,30H
       cmp cx,1H
       je  BinEnd
       mov dx,10
       dec cx
   Binlop:
       inc si
       mov dx,10
       mul dx
       mov bl,[si]
       sub bl,30H
       cmp bl,9
       ja  BinErr
       add ax,bx
       loop Binlop
       jmp BinEnd
   BinErr:
       mov dx, offset ERRINF
       call newlne
       pop dx
       call CNTNUM
       call newlne
       mov ah, 09H
       int 21H
   BinEnd:
       pop si
       pop dx
       pop cx
       pop bx
   
       ret
   Binary endp
   ```

3. 编写二进制显示子程序。

   通过二进制转换子程序，转换得到的二进制存放在 ax 寄存器中，通过移位运算，检查溢出标志位，判断是否溢出，来确定输出 0 或 1

   ```assembly
   DispB proc   
   ;;;;;;;;;;;;;;;;;;;;;;;
   ;   二进制显示子程序
   ;   ax: 待显示的二进制数据
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;  
   	push ax
       push bx
       push cx
       push dx
       mov bx,ax
       mov cx,16
   s:	mov dl,'0'
   	rol bx,1
   	jnc s1
   	mov dl,'1'
   s1:	mov ah,02h
   	int 21h
   	loop s
   
       call newlne
       pop dx
       pop cx
       pop bx
       pop ax
   	ret
   DispB endp
   ```

4. 编写异常处理程序，当输入非数字型字符时，给出异常信息提示，并统计字符串中数字的数量

   ```assembly
   CNTNUM proc
       push ax
       push bx
       push cx
       push dx
   
       mov si, dx
       mov ax,0
   CHECK:
       mov bl,[si]
       inc si
       cmp bl,30H
       jb  NOTNUM
       cmp bl,39H
       ja  NOTNUM
       inc ax
   NOTNUM:
       loop CHECK
   
       add ax,30H
       mov dx,ax
       mov ah,02H
       int 21h
   
       pop dx
       pop cx
       pop bx
       pop ax
   
       ret    
   CNTNUM endp
   ```



## 五、完整源代码

```assembly
ASSUME SS:_STACK,DS:_DATA,CS:_CODE

_STACK SEGMENT STACK
DW 500 DUP(?)
_STACK ENDS

_DATA SEGMENT
BUFFER   DB 30 DUP(0)
ERROR_TEXT      DB 0DH,0AH,'The input form is wrong!',0DH,0AH,'$'
TEXT     DB  0DH,0AH,'$'
PLEASE    DB  0DH,0AH,'please input:',0DH,0AH,'$'
EXIT      DB  0DH,0AH,'You have exit successful!',0DH,0AH,'$'
_DATA ENDS 

_CODE SEGMENT
error:
MOV AH,09H
MOV DX,OFFSET ERROR_TEXT
INT 21H
jmp WELCOME

kongge:
PUSH DX
PUSH AX
MOV DL,20H
MOV AH,02H
INT 21h
POP AX
POP DX
RET

HUICHE:
PUSH DX
PUSH AX
MOV AH,09H
MOV DX,OFFSET TEXT
INT 21H
POP AX
POP DX
RET

start:
MOV AX,_DATA 
MOV DS,AX

WELCOME:
MOV AH,09H
MOV DX,OFFSET PLEASE
INT 21H
MOV DI,OFFSET BUFFER
INC DI
MOV CX,0H

input:
MOV AH,01H
INT 21H

CMP AL,0DH
JE TRANSFORM
CMP AL,'Q'
JE FINAL
CMP AL,'q'
JE FINAL
CMP AL,'0'
JB ERROR
CMP AL,'9'
JA ERROR
CMP CX,5
JAE ERROR

MOV DS:[DI],AL
INC DI
INC CX
JMP INPUT

OU:
DEC CX
MOV DI,OFFSET BUFFER
INC DI
JMP NEXT

JI:
MOV DI,OFFSET BUFFER
MOV AX,30H
MOV DS:[DI],AX
JMP NEXT

TRANSFORM:
CMP CX,0
JE ERROR
CALL HUICHE
MOV AX,CX
AND AL,1
CMP AL,0
JE OU
JNE JI

NEXT:
MOV AX,DS:[DI]
SUB AX,30H

LEAP:
mov bl,10
MUL BL

DEC CX
INC DI
ADD AX,DS:[DI]
SUB AX,30H

MOV DL,AL
MOV AH,02H
INT 21h

CMP CX,0H
je WELCOME
JNE LEAP


FINAL:
MOV AH,09H
MOV DX,OFFSET exit
INT 21H
_CODE ENDS
END START
```



# 实验三 基本IO拓展实验

## 一、实验目的

1. 了解 TTL 芯片扩展简单 I/O 口的方法。

2. 掌握数据输入输出程序编制的方法。

 

## 二、实验内容说明

 本实验要求用74LS244作为输入口，读取开关状态，并将此状态通过74LS273连到发光二极管显示。具体实验内容如下：

1. 开关Yi为低电平时对应的发光二极管亮，Yi为高电平时对应的发光二极管灭。

2. 当开关Yi全为高电平时，发光二极管Qi从左至右轮流点亮。

3. 当开关Yi全为低电平时，发光二极管Qi从右至左轮流点亮。

4. 主设计控制及显示模式，完成编程调试，演示实验结果。

 

## 三、实验原理

 **74LS244**是一种三态输出的8总线缓冲驱动器，无锁存功能，当G为低电平，Ai信号传送到Yi，当为高电平时，Yi处于禁止高阻状态;

 **74LS273**是一种带清除功能的8D触发器， 1D～8D为数据输入端，1Q～8Q为数据输出端，正脉冲触发，低电平清除，常用作8位地址锁存器。                                                       

 

## 四、实验步骤

1.  按照实验连线图连接：
    - 244的CS接到ISA总线接口模块的0000H，Y7—Y0——开关K1—K8。
    - 273的CS接到ISA总线接口模块的0020H，Q7—Q0——发光二极管L1—L8。
    - 该模块的WR、RD分别连到ISA总线接口模块的IOWR、IORD。
    - 该模块的数据（AD0～AD7）连到ISA总线接口模块的数据（LD0～LD7）。

2.  编写实验程序，编译链接，运行程序
3.  拨动开关，观察发光二极管的变化。

 

## 五、实验结果及完整源码

编译链接项目后，改变开关Yi可观察到

开关Yi为低电平时对应的发光二极管亮，Yi为高电平时对应的发光二极管灭。

当开关Yi全为高电平时，发光二极管Qi从左至右轮流点亮。

当开关Yi全为低电平时，发光二极管Qi从右至左轮流点亮。

###  完整源代码：

![1641114001919.jpg](D:\Tecent QQ\2778278573\FileRecv\1641114001919.jpg.jpg)

![1641114780711.jpg](D:\Tecent QQ\2778278573\FileRecv\1641114780711.jpg.jpg)

![1641115124013.jpg](D:\Tecent QQ\2778278573\FileRecv\1641115124013.jpg.jpg)



# 实验四 可编程并行接口实验

## 一、实验目的

1. 了解可编程并行接口8255的内部结构

2. 掌握8255的工作方式、初始化编程及应用。

 

## 二、实验内容

1. 流水灯实验：利用8255的A口、B口循环点亮发光二极管。
2. 交通灯实验：利用8255的A口模拟交通信号灯。
3. I/O输入输出实验：利用8255的A口读取开关状态，8255的B口把状态送发光二极管显示。
4. 在完成(1)基础上，增加通过读取开关控制流水灯的循环方向和循环方式。
5. 在完成(2)基础上，增加通过读取开关控制交通红绿灯的亮灭时间。

 

## 三、实验原理

 8255是一个通用可编程并行接口电路。它具有A、B、C三个8位并行口。其中C口也可用作A、B口的联络信号及中断申请信号。通过编程，它可以被设置为基本输入输出、选通输入输出以及双向传送方式。对于C口还具有按位置0、1的功能。

​                                                 

## 四、实验步骤

- 模块的WR、RD分别连到ISA总线接口模块的IOWR、IORD。

- 模块的数据（AD0～AD7）、地址线（A0～A7）分别连到ISA总线接口模块的数据（LD0～LD7）、地址线（LA0～LA7）。

- 8255模块选通线CE连到ISA总线接口模块的0000H。

- 8255的PA0～PA7连到发光二极管的L0～L7；8255的PB0～PB7连到发光二极管的L8～L15。
- 编写 8255 驱动程序

- 运行程序，观察发光二极管。

 

## 五、完整源代码

```assembly
MY_STACK	SEGMENT	PARA 'STACK' 
			DB		100 DUP(?)
MY_STACK	ENDS

MY_DATA 	SEGMENT	PARA 'DATA'
IO_9054base_address DB 4 DUP(0)						;PCI卡9054芯片I/O基地址暂存空间
IO_base_address     DB 4 DUP(0)						;PCI卡I/O基地址暂存空间
pcicardnotfind		DB 0DH,0AH,'pci card not find or address/interrupt error !!!',0DH,0AH,'$'
GOOD				DB 0DH,0AH,'The Program is Executing !',0DH,0AH,'$'
LS244    	DW  	00000H  		
LS273    	DW  	00020H
LS8255      DW      00000H
LS8255W   DW      00003H
RA          DB      ?
LB          DB      ?
;
;
DELAY_SET	EQU	 	0FFFH							;延时常数

MY_DATA 	ENDs

MY_CODE 	SEGMENT PARA 'CODE'

MY_PROC		PROC	FAR		
			ASSUME 	CS:MY_CODE,	DS:MY_DATA,	SS:MY_STACK			
MAIN:		
.386	;386模式编译
			MOV		AX,MY_DATA
			MOV		DS,AX
			MOV		ES,AX
			MOV		AX,MY_STACK
			MOV		SS,AX
			CALL	FINDPCI					;自动查找PCI卡资源及IO口基址
			MOV		CX,word ptr IO_base_address	
;			MOV		CX,0E800H				;直接加入(E800:本机PCI卡IO口基址)
			
        						;PCI卡IO基址+偏移
   
			ADD     LS8255,CX
			ADD     LS8255W,CX
; 插入功能实现代码
MOV		RA,7FH
MOV 	LB,0FEH

READ1:MOV AX,80H
	MOV	DX,LS8255W
	OUT DX,AX
	MOV	DX,LS8255
	MOV	AL,0E7H
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV AL,0DBH
	MOV DX,LS8255
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV AL,0BDH
	MOV DX,LS8255
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV AL,07EH
	MOV DX,LS8255
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV	DX,LS8255W
	OUT DX,AX
	MOV	DX,LS8255
	MOV	AL,0E7H
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV AL,0DBH
	MOV DX,LS8255
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV AL,0BDH
	MOV DX,LS8255
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	MOV AL,07EH
	MOV DX,LS8255
	OUT DX,AL
	CALL DELAY
	CALL BREAK
	JMP  READ1
	
	
MY_PROC  ENDp

BREAK		PROC   NEAR
PUSHF
PUSH  AX
PUSH  DX
MOV  AH,06H
MOV  DL,0FFH
INT 21H
JE  RETURN 
MOV AX,4C00H
INT 21H
RETURN:
	POP  DX
	POP  AX
	POPF
	RET
	BREAK  ENDP
	DELAY		PROC  NEAR

DELAY 		PROC  	NEAR					;延时程序
			PUSHF
			PUSH	DX
			PUSH	CX
			MOV 	DX,DELAY_SET
D1: 	   	MOV 	CX,-1
D2:    		DEC 	CX
       		JNZ 	D2
       		DEC		DX
       		JNZ		D1
       		POP		CX
       		POP		DX
       		POPF
       		RET
DELAY  		ENDp
;FUNCTION CODE
IO_port_addre		EQU 0CF8H					;32位配置地址端口
IO_port_data		EQU	0CFCH					;32位配置数据端口
IO_PLX_ID			EQU	200810B5H				;PCI卡设备及厂商ID
BADR0				=	10H						;基地址寄存器0
BADR1				=	14H						;基地址寄存器1
BADR2				=	18H						;基地址寄存器2
BADR3				=	1CH						;基地址寄存器3

FINDPCI 	PROC	NEAR						;查找PCI卡资源并显示
			PUSHAD
			PUSHFD
			MOV		EBX,080000000H
FINDPCI_next:
			ADD		EBX,100H
			CMP 	EBX,081000000H
			JNZ 	findpci_continue
			MOV 	DX,offset pcicardnotfind	;显示未找到PCI卡提示信息
			MOV 	AH,09H
			INT 	21H
			MOV 	AH,4CH
			INT 	21H							;退出
findpci_continue:
			MOV 	DX,IO_port_addre
			MOV 	EAX,EBX
			OUT 	DX,EAX						;写地址口
			MOV 	DX,IO_port_data
			IN  	EAX,DX						;读数据口
			CMP 	EAX,IO_PLX_ID
			JNZ 	findpci_next				;检查是否发现PCI卡

			MOV 	DX,IO_port_addre
			MOV 	EAX,EBX
       		ADD 	EAX,BADR1
			OUT 	DX,EAX									;写地址口
			MOV 	DX,IO_port_data
			IN  	EAX,DX									;读数据口
			MOV 	dword ptr IO_9054base_address,EAX
			AND 	EAX,1
			JZ 		findPCI_next							;检查是否为i/o基址信息
       		MOV 	EAX,dword ptr IO_9054base_address
			AND 	EAX,0fffffffeh
        	MOV 	dword ptr IO_9054base_address,EAX		;去除i/o指示位并保存

			MOV 	DX,IO_port_addre
			MOV 	EAX,EBX
			ADD 	EAX,BADR2
			OUT 	DX,EAX									;写地址口
			MOV 	DX,IO_port_data
			IN  	EAX,DX									;读数据口
			MOV 	dword ptr IO_base_address,EAX
			AND 	EAX,1
			JZ 		findPCI_next							;检查是否为i/o基址信息
			MOV 	EAX,dword ptr IO_base_address
			AND 	EAX,0fffffffeh
			MOV 	dword ptr IO_base_address,EAX			;去除i/o指示位并保存
			MOV 	DX,offset good							;显示开始执行程序信息
			MOV 	AH,09H
			INT 	21H
			POPfd
			POPad
			RET
findPCI		ENDP


MY_CODE   	ENDS

			END    	MAIN	
```



## 实验心得

《微机原理与系统设计》这门课程是计算机科学与技术专业的专业核心课程。这学期的微机原理实验，更是让我对微机原理知识有了亲自的应用和体验，通过自己的亲自操作让我对计算机的基本组成与结构原理有了更加深入的了解。虽然因为疫情的限制，未能完全体会最后一次实验的精髓，但通过两次汇编程序设计实验，极大的提高了我汇编语言代码的编写能力，两次软硬件结合的接口实验，让我对嵌入式系统的工作方式有了进一步的了解和认识。

通过这次的微机原理实验，我详细的了解了 74LS244、74LS273、可编程并行接口8255的电路设计，驱动程序的编写方式，并通过自己的亲自实践，使用编写的代码完成了对 LED 发光二极管的控制。

这四次实验机会宝贵，使我对微机原理课程的相关知识有了更深的印象和认识。通过这次实验，我不仅加深了对理论知识的理解，提高了实践能力，更是扩展学习了许多汇编语言与硬件接口相关的嵌入式系统设计知识，对于今后的学习和工作，无疑具有巨大的意义。



