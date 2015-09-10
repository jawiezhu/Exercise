package IoPatternDemo;

public class Amplifier {
	private Voice voice;

	public Amplifier(Voice voice) {
		super();
		this.voice = voice;
	}

	public Amplifier() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public void say(){
		System.out.println(voice.getVoice()*1000);
	}
}
