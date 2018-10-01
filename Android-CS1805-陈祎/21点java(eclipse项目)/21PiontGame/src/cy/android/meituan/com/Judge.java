package cy.android.meituan.com;

public class Judge {
	private String name = "�ɹ�";
	
	
	public Judge() {
		
	}


	public void wash (Poker[] p) {
		for(int i = p.length;i > 1;i --)
	     {
	        int r = (int)(Math.random()*i);//����0~i-1�е�һ�������
	        Poker temp;
		    
	        temp = p[i - 1];
		    p[i - 1] = p[r];
		    p[r] = temp;
		    
	     }
	}
	
	void claim(int t) {
		System.out.println("------------------");
		System.out.println(getName()+":�����ǵ�"+t+"��");
		System.out.println("------------------");
		Main.turn ++;
	}
	
	void check(Gambler a, Gambler b) {
		int s1 = a.getSumPoint();
		int s2 = b.getSumPoint();
		if (s1>21 && s2<22){
			System.out.println(a.getName()+":");
			for(int i = 0;i < (s2/2);i ++)
				System.out.println("�㱬���ˣ���һ�ʤ��");
			a.setState(-1);
        }else if (s2>21 && s1<22){
        	System.out.println(b.getName()+":");
			for(int i = 0;i < (s1/2);i ++)
				System.out.println("�㱬���ˣ�ׯ�һ�ʤ��");
			b.setState(-1);
        }else if(s1>21&&s2>21){
			System.out.println("�ɹ�:����ׯ�����ͬʱ��ʤ��������ׯ�һ�ʤ��");
			b.setState(-1);
        }
		
		if ((a.getState() == 1)&&(b.getState() == 1)) {
			System.out.println(getName()+":"+"����ׯ�Һ����ͬʱ���������ڽ������׶�...");
			if (s1 == s2){
				System.out.println("push״̬:ׯ�Һ���Ҵ��ƽ�֣�\n");
				a.setState(-1);
				b.setState(-1);
	        }else if(s1 > s2) {
	        	System.out.println("ׯ��ʤ����");
	        	b.setState(-1);
	        }else {
	        	System.out.println("���ʤ����");
	        	a.setState(-1);
	        }
		}
	}

	public String getName() {
		return name;
	}
	
}
