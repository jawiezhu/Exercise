package IoPatternDemo;

public class Voice {
	private int voice=10;

	public int getVoice() {
		return voice;
	}

	public void setVoice(int voice) {
		this.voice = voice;
	}

	public Voice(int voice) {
		super();
		this.voice = voice;
	}

	public Voice() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public void say(){
		System.out.println(voice);
	}

}
