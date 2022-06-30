clear;
clc;

jieshu=5;
% jieshu=8;
iniVector=zeros(1,jieshu); % 初始向量
iniVector(1,1)=10000;
trans = iniVector; % 当前迭代情况
preTrans=trans; % 前一轮迭代情况
generTimes=100; % 生成generTimes次一步转移矩阵
stage = jieshu; % 每个矩阵的阶数


lunshu=ones(1,generTimes);
secondMaxEigen=ones(1,generTimes);
i=1;
while i<=generTimes
    temp=ones(stage);
    for j=1:stage
        x=rand(1,stage);
        y=sum(x);
        r=x./y;
        temp(j,:)=r;
    end
    check=getSecondMaxEig(temp,stage);
    if check==1
        continue;
    end
        
    % 此处得到一个五阶的一步状态转移矩阵temp
    preTrans=iniVector;
    for j=1:100
        trans=preTrans*temp;
        if trans == preTrans
            lunshu(1,i)=j;
            secondMaxEigen(1,i)=getSecondMaxEig(temp,stage);
            break;
        end
        preTrans=trans;
        if j == 100
            i=i-1;
            break;
        end
    end
    i= i+1;
end

lunshu
secondMaxEigen

[sortedSecondMaxEigen,placeSME]=sort(secondMaxEigen,2);
sortedLunshuFollowingSME=lunshu(:,placeSME);

scatter(sortedSecondMaxEigen,sortedLunshuFollowingSME,'+','linewidth',1.5);
hold on
% grid()
axis([0,0.7,5,30])
pos = axis;
% title('一步转移矩阵次大特征值与收敛轮数关系','fontsize',14)
xlabel('\mid \lambda_{2} \mid','fontsize',16,'fontweight','bold')
ylabel('Convergence rounds','fontsize',16,'fontweight','bold')
legend('Relation scatter')
plot([sortedSecondMaxEigen(1) sortedSecondMaxEigen(1)],[0 , sortedLunshuFollowingSME(1)],'linestyle','--','linewidth',1.3)
hold on
plot([0 , sortedSecondMaxEigen(1)],[sortedLunshuFollowingSME(1) sortedLunshuFollowingSME(1)],'linestyle','--','linewidth',1.3)
hold on
plot([sortedSecondMaxEigen(size(sortedSecondMaxEigen,2)) sortedSecondMaxEigen(size(sortedSecondMaxEigen,2))],[0 , sortedLunshuFollowingSME(size(sortedLunshuFollowingSME,2))],'linestyle','--','linewidth',1.3)
hold on
plot([0 , sortedSecondMaxEigen(size(sortedSecondMaxEigen,2))],[sortedLunshuFollowingSME(size(sortedLunshuFollowingSME,2)) sortedLunshuFollowingSME(size(sortedLunshuFollowingSME,2))],'linestyle','--','linewidth',1.3)


text(sortedSecondMaxEigen(1),sortedLunshuFollowingSME(1)-0.5,['    (',num2str(sortedSecondMaxEigen(1)),',',num2str(sortedLunshuFollowingSME(1)),')'])

text(sortedSecondMaxEigen(size(sortedSecondMaxEigen,2)),sortedLunshuFollowingSME(size(sortedLunshuFollowingSME,2)),['    (',num2str(sortedSecondMaxEigen(size(sortedSecondMaxEigen,2))),',',num2str(sortedLunshuFollowingSME(size(sortedLunshuFollowingSME,2))),')'])
