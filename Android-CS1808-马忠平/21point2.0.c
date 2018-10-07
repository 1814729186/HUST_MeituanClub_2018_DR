 #include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void penter(void)
{
	printf("***press enter***\n");
	getchar();
}

void line(void)
{
	printf("**************************************************\n");
}

void sline(void) 
{
	printf("*********\n");
}

void dealer(int s)
{
	printf("ׯ�ҵĵ÷�Ϊ%d\n",s);
}
void gamer(int s)
{
	printf("��ҵĵ÷�Ϊ%d\n",s);
}


void main()
{
	
	int score_1=0,score_2=0;
	int b1,b2;
	int e;
	int d1=0,d2=0;
	
	
	
	
	srand(time(NULL)); 
	int RandNum, a[52] = {0};
	int i,  flag = 0, t=0;
	
	struct Decks
	{
	char symbol[8];
	char num[4];
	int worth;
	}poker[52] = {
		{"heart","A",11},   {"heart","2",2},   {"heart","3",3},   {"heart","4",4},   {"heart","5",5},   {"heart","6",6},   {"heart", "7",7},   {"heart","8",8},   {"heart","9",9},   {"heart","10",10},   {"heart","J",10},   {"heart","Q",10},   {"heart","K",10},//������
		{"diamond","A",11}, {"diamond","2",2}, {"diamond","3",3}, {"diamond","4",4}, {"diamond","5",5}, {"diamond","6",6}, {"diamond","7",7},  {"diamond","8",8}, {"diamond","9",9}, {"diamond","10",10}, {"diamond","J",10}, {"diamond","Q",10}, {"diamond","K",10},//��Ƭ��
		{"clud","A",11},    {"club","2",2},    {"club","3",3},    {"club","4",4},    {"club","5",5},    {"club","6",6},    {"club","7",7},     {"club","8",8},    {"club","9",9},    {"club","10",10},    {"club","J",10},    {"club","Q",10},    {"club","K",10},//÷����
		{"spade","A",11},   {"spade","2",2},   {"spade","3",3},   {"spade","4",4},   {"spade","5",5},   {"spade","6",6},   {"spade","7",7},    {"spade","8",8},   {"spade","9",9},   {"spade","10",10},   {"spade","J",10},   {"spade","Q",10},   {"spade","K",10}//������
	};
    struct Decks *p_1,*p_2;
    
    printf("****��ӭ�������Żʼ����϶ĳ�****\n������21��ר��\n");
    penter();
    printf("�뿪ʼ��Ŀ񻶣�����\n");
    penter();
    printf("���濪ʼϴ��\n");
	 penter();
    
	 while(1)
	{
	    flag = 0;
		if(t == 52)
				break;
				
				RandNum = (rand()%(53 - 0));
				for(i = 0; i < t; i++)
				{
					if(a[i] == RandNum)
							flag = 1;		}	
				if(flag != 1)
				{			
				        a[t] = RandNum;		
				        
						t++;	
				}	
	    }
	    
	    printf("��Ϸ��ʼ������\n���enter��ʼ��ׯ�Һ���ҵĵ�һ����\n");
	    getchar();
	    p_1 = &poker[a[0]];
	    p_2 = &poker[a[1]];
	    score_1 += p_1->worth;
	    score_2 += p_2->worth;
	    printf("ׯ�ҵĵ�һ����Ϊ%s,%s\n",p_1->symbol,p_1->num);
	    dealer(score_1);
	    printf("��ҵĵ�һ����Ϊ%s,%s\n",p_2->symbol,p_2->num);
	    gamer(score_2);
	    line();
	    getchar();
	    
	    e = 2;
		b1=1,b2=1;
	    while(b1 == 1 ||b2 == 1)
	    {
	    	if (b1 == 1)
	    	{			
	        printf(">ׯ�һغ�<\n");
	        printf("������Ƿ����Ҫ�ƣ�\n(��������1����Ҫ�ƣ������������ַ���Ҫ��)\n");
	        scanf("%d",&b1); 
	        if(b1 == 1)
	        {
	        	p_1 = &poker[a[e]];
	      
	        	printf("ׯ�ҵ���һ������%s,%s\n",p_1->symbol,p_1->num);
	        	score_1 += p_1->worth;
	        	e++;
	        	dealer(score_1);
	        	if(score_1 > 21)
	        	{
	        		printf("ׯ�ҵĵ÷��ܼ�Ϊ%d\npush!!!\nׯ������˱�������һ�ʤ!\n",score_1);
	        		b1 = 0,b2 = 0;
	        		continue;
				}
			}else printf("�ѷ���Ҫ��\n");
        	}else printf("ׯ���ѷ���Ҫ��\n");
        	sline();
        	
        	if(b2 == 1)
        	{
        		printf(">��һغ�<\n");
        		printf("������Ƿ����Ҫ�ƣ�\n(��������1����Ҫ�ƣ������������ַ���Ҫ��)\n");
        		scanf("%d",&b2);
        		if(b2 == 1)
        		{
        			p_2 = &poker[a[e]];
        			printf("��ҵ���һ������%s,%s\n",p_2->symbol,p_2->num);
					score_2 += p_2->worth;
					e++;
					gamer(score_2);
					if(score_2>21) 
					{
	        		printf("��ҵĵ÷��ܼ�Ϊ%d\npush!!!\n�������˱�����ׯ�һ�ʤ!\n",score_2);
	        		b1 = 0; b2 = 0; 
	        		continue;
				}
				}else printf("�ѷ���Ҫ��\n");
			}else printf("��Ҽ��ѷ���Ҫ��\n");
			line();
			penter();
			getchar();
       	}
       	if(score_1<=21 && score_2<=21)
       	{
       		printf("ׯ�ҵĵ÷���%d\n��ҵĵ÷���%d\n",score_1,score_2);
       		 if (score_1 > score_2)
			 printf("ׯ�ҵ���������ң�ׯ�һ�ʤ!\n");
		 if (score_1 < score_2)
			 printf("��ҵ�������ׯ�ң���һ�ʤ!\n");
		 if (score_1 == score_2)
			 printf("ׯ������ҵ�����ͬ��ƽ�֡�\n");
		   }    
}


