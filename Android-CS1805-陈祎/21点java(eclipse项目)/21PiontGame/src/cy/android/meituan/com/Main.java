package cy.android.meituan.com;

import java.util.Scanner;

public class Main {
	static int turn = 1;
	static int leftPoker = 52;
	static int fetchPoker = 0;
	
	
	public static void main(String[] args) {		
		
		/*����һ������*/
		Poker[] poker = new Poker[52];
		for(int i = 0;i < leftPoker;i ++)
			poker[i] = new Poker(i);
		
		/*ϴ��*/
		Judge h = new Judge();
		h.wash(poker);
		
		/*������ɫ*/
		Gambler boss = new Gambler("ׯ��");
		Gambler player = new Gambler("���");
		
		/*�����һ��*/
		h.claim(turn);
		System.out.println(boss.getName()+":");
		boss.fetch(poker[fetchPoker], leftPoker);
		System.out.println(player.getName()+":");
		player.fetch(poker[fetchPoker], leftPoker);
		
		while((boss.getState()!= 1)&&(player.getState()!=-1)) {
			h.claim(turn);
			System.out.println(boss.getName()+":");
			choose(boss, poker);
			System.out.println(player.getName()+":");
			choose(player, poker);			

			//����׶�
			h.check(boss, player);
		}

		//��������
//		for(Poker p : poker)
//			System.out.println(p.getState());
	}
	
	static void choose (Gambler g, Poker[] p){
		Scanner s = new Scanner(System.in);
		System.out.println("�Ƿ���ܱ��ַ��ƣ�(1.����.2.����.)");
		System.out.print("���ѡ����:");
		int num = s.nextInt();
		
		switch (num) {
		case 1:
			g.fetch(p[fetchPoker], leftPoker);
			break;
		case 2:
			g.giveUp();
			System.out.println("��������ƵĻ��ᣡ");
			break;
		}
	}
	
	
}
