package cy.android.meituan.com;

public class Gambler {
	private String name;
	private int state;//0Ϊ����1Ϊ����
	private int sumPoint;
	
	public Gambler(String name) {
		super();
		this.name = name;
	}

	/**
	 * ����
	 * @param p ����һ���Ƶ�ʵ��
	 * @param lp ��������ʣ������
	 */
	public void fetch(Poker p, int lp) {
		sumPoint += p.getRealPoint();
		Main.fetchPoker ++;
		Main.leftPoker --;
		System.out.println("��鵽"+p.getState());
		System.out.println("��ǰ�ܵ���Ϊ:" + sumPoint);
	}
	public void giveUp() {
		setState(1);
	}
	
	public void printSate() {
		
	}
	
	public int getState() {
		return state;
	}

	public void setState(int state) {
		this.state = state;
	}

	public String getName() {
		return name;
	}

	public int getSumPoint() {
		return sumPoint;
	}
	
	
	

}
