public class Test extends Test2{

	private int x;
	private int y;
	
	public Test(int x, int  y){
		this.x = x;
		this.y = y;
	}

	public int getX(){
		return this.x;
	}

	public int getY(){
		return this.y;
	}

	public void quickMath(){
		System.out.println(x+y);
	}
}