/***********************************************************
 TITLE	DEMOSBTS.C

 This rogram demostrates how to use the Text-toSpeech functions
 Note that the BLASTER environment has  to be set before
 executing this program.
 **********************************************************/

#include <sbcts.h>
main(){
  if(sbts_init()){
    printf("SBTALKER installed.\n\n");
    sbts_say("SB-talker installed.");
    printf('Press a key to continue...");
    getch();

    sbts_settings(0,0,9,5,5);
    printf("I can speak louder.\n");
    sbts_say("I can speak louder.");
    printf("Pres a key to continue.);
    getch();
    sbts_settings(0,0,9,9,5);
    printf("I can change my pitch.\n");
    sbts_say("I can change my pitch.");
    printf("Press a key to continue...");
    getch();

    sbts_settings(0,0,9,9,9);
    printf("I can speak very fase.\n\n");
    sbts_say ("I can speak very fase.");
  }
  else
    printf("SBTALKER not installed.\n");
}
