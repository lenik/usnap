

import javax.speech.*;
import javax.speech.synthesis.*;
import java.util.Locale;


public class HelloReader {

	public static void main(String[] args) {
		try {
			Synthesizer synth = Central.createSynthesizer(new SynthesizerModeDesc(Locale.ENGLISH));

			synth.allocate();
			synth.resume();

			synth.speakPlainText("Hello, reader.", null);

			System.out.println("Do you hear something?");

			synth.waitEngineState(Synthesizer.QUEUE_EMPTY);

			synth.deallocate();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
