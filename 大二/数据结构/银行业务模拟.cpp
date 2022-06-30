#include<stdio.h>

int subt = 0;
int *subtime = &subt;

typedef struct customer {
	int money;
	int waittime = 0;
	int reachtime = 0;
}c;

typedef struct queue {
	c a[1000];
	int front=0;
	int rear=0; 
	int length = 0;
}q; 

int in(c n,q *s) {
	if(s->rear == 1000) s->rear = 0;
	s->a[s->rear].money = n.money;
	s->a[s->rear].waittime = n.waittime;
	s->a[s->rear].reachtime = n.reachtime;
	s->rear++;
	s->length++;
}

int out(q *s) {
	int n=s->a[s->front].waittime;
	s->front++;
	if(s->front == 1000) s->rear = 0;
	s->length--;
	return n;
}

void queue2(q *s,int time,int *subtime,int *m,int dealtime,int *sumt) {
	if(*subtime < time && s->length > 0){
		int i,t;
		for(i = 0;i < s->length;i++) {
			if((s->a[s->front].money + *m) >= 0) {
				*subtime -= dealtime;
				if(*subtime < 0) return;
				s->a[s->front].waittime += dealtime;
				*m += s->a[s->front].money;
				t = out(s);
				*subtime += t;
				*sumt += t;
			}
			else {
				in(s->a[s->front],s);
				out(s);	
			}
		}
	}
	if(*subtime >= time && s->length > 0) {
		int i,t;
		for(i = s->front;i < s->rear;i++) s->a[i].waittime = s->a[s->front].reachtime - time;
		*subtime = time;
		for(i = 0;i < s->length;i++) {
			if((s->a[s->front].money + *m) >= 0) {
				*subtime -= dealtime;
				if(*subtime < 0) return;
				s->a[s->front].waittime += dealtime;
				*m += s->a[s->front].money;
				t = out(s);
				*subtime += t;
				*sumt += t;
			}
			else{
				in(s->a[s->front],s);
				out(s);	
			}
		}
	}
}

void queue1(q *p,q *s,int dealtime,int nexttime,int *m,int time,int dealmoney,int *sumt) {
	int t = nexttime;
	c n;
	n.money = dealmoney;
	n.waittime = 0;
	in(n,p);
	while(nexttime > 0 && p->length > 0) {
		if((p->a[p->front].money + *m) >= 0 && p->a[p->front].waittime + nexttime >= dealtime) {
			*m += p->a[p->front].money;
			nexttime -= (dealtime - p->a[p->front].waittime);  
			if(p->a[p->front].money > 0) queue2(s,time+nexttime-t,subtime,m,dealtime,sumt);
			out(p);       
			*sumt += dealtime;
		}
		if((p->a[p->front].money + *m) < 0) {
			in(p->a[p->front],s);
			s->a[s->front].reachtime = time+nexttime-t;
			out(p);
		}
		else if(p->a[p->front].waittime + nexttime < dealtime) {
			p->a[p->front].waittime += nexttime;
			nexttime = 0;
		}      
	}
}

int main() {
	int dealtime,nexttime,money,time,dealmoney;
	int sumtime = 0,sumc = 0,*sumt = &sumtime;
	int *m = &money;
	q a,b,*s = &a,*p = &b;
	printf("请输入银行持有钱数（元）："); 
	scanf("%d",&money);
	printf("请输入营业时间（分钟）："); 
	scanf("%d",&time);
	printf("请输入客户入行间隔时间（分钟）："); 
	scanf("%d",&nexttime);
	printf("请输入银行业务处理时间（分钟）："); 
	scanf("%d",&dealtime);
	subt = time;
	while(time > 0) {
		sumc++;
		printf("请输入客户账户额度变化，存款与还钱为正，取款与借钱为负：");
		scanf("%d",&dealmoney);
		queue1(s,p,dealtime,nexttime,m,time,dealmoney,sumt);
		time -= nexttime;
	}
	while(p->length) sumtime+=out(p);
	while(s->length) sumtime+=out(s) + subt;
	printf("银行所剩余额为：%d（元）\n客户平均滞留时间为：%.2f分钟）",*m,*sumt*1.0 / sumc);
	
	return 0;
}
