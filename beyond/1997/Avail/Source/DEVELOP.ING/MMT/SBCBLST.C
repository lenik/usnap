/***********************************************************
  @@ Source Documentation
  SBCBLST.C

  The program checks the BLASTER environment variable for the
  Card settings. It also performs a test based on the BLASTER
  environment settings to envsure they tlly with the hardware
  settings on the card.
  *********************************************************/

#include <stdio.h>
#include <sbc.h>

char *CardType[]={
  "Sound Blaster",
  "Sound Blaster Pro",
  "Sound Blaster 2.0"
};
main(){
  unsigned wFeature;
  if(!GetEnvSetting()){
    if((wFeature=sbc_check_card())!=0){
      if(sbc_test_int()){
	if(sbc_test_dma()>=0){
	  printf("%s card installed at :\n", CardType[wCardID-1]);
	  printf("\tI/O address: %x hex\n", ct_io_addx);
	  printf("\tInterrupt: %d\n", ct_intnum);
	  printf("\tDMA Channel: %d\n\n", ct_dma_channel);
	  if(wFeature&2)
	    printf("FM music available.\n");
	  if(wFeature&4)
	    printf("Creative voice available.\n");
	}
	else
	  printf("Error on DMA channel.\n");
      }
      else
	printf("Error on interrupt.\n");
    }
    else
      printf("Sound Blaster Card not found or wrong I/O setting.\n");
  }
  else
    printf("BLASTER environment variable not set r incomplete or invalid.\n");
}
