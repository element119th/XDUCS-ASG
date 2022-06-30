clear,clc,close all
syms x1 x2 t
f = 2*x1^2+x2^2; 
g = [diff(f,x1),diff(f,x2)];
x10 = 1; x20 = 1;  %初始点（1,1）
v = [x1,x2]; %自变量
g0 = subs(g,v,[x10,x20]); %计算初始点梯度
x = [x10,x20]; 
n = 1;
fcontour(f,[-1,2,-1,2]);
hold on

while n<=10  %迭代十次
    d = -g0; %计算负梯度方向 
    fval = subs(f,v,x); 
    ft = subs(f,v,x+t*d);
    dft = diff(ft);
    s = double(solve(dft)); 
    plot([x(1) x(1)+s*d(1)],[x(2),x(2)+s*d(2)],'Color',rand(1,3));drawnow;pause(0.3);
    x = x+s*d; %求下一个迭代点
    fprintf('x%d的值为： [%s，%s]\n',n,x(1),x(2));
    g0 = subs(g,v,x); %更新梯度
    n = n+1;
end

fprintf('函数f在x处的值为： %s\n',fval); %f在v1处的最优值
