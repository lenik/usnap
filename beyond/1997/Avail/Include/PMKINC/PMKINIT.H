#ifndef __PMKINITIALIZES_H
  #define __PMKINITIALIZES_H

	#ifdef bolfn__
		void           _Cdecl        bold_font(void);
	#endif
	#ifdef eurfn__
		void           _Cdecl        euro_font(void);
	#endif
	#ifdef comfn__
		void           _Cdecl     complex_font(void);
	#endif
	#ifdef scrfn__
		void           _Cdecl      script_font(void);
	#endif
	#ifdef simfn__
		void           _Cdecl     simplex_font(void);
	#endif
	#ifdef tscfn__
		void           _Cdecl triplex_scr_font(void);
	#endif
	#ifdef bolff__
		extern int far _Cdecl        bold_font_far[];
	#endif
	#ifdef eurff__
		extern int far _Cdecl        euro_font_far[];
	#endif
	#ifdef comff__
		extern int far _Cdecl     complex_font_far[];
	#endif
	#ifdef scrff__
		extern int far _Cdecl      script_font_far[];
	#endif
	#ifdef simff__
		extern int far _Cdecl     simplex_font_far[];
	#endif
	#ifdef tscff__
		extern int far _Cdecl triplex_scr_font_far[];
	#endif

void  huge buildbgi(void){
			  #if   defined (hf__)
			  if (registerfarbgidriver(Herc_driver_far)<0)    exit(1);
			  #elif defined (hn__)
			  if (registerfarbgidriver(Herc_driver)<0)        exit(1);
			  #endif
			  #if   defined (ef__)
			  if (registerfarbgidriver(EGAVGA_driver_far)<0)  exit(1);
			  #elif defined (en__)
			  if (registerfarbgidriver(EGAVGA_driver)<0)      exit(1);
			  #endif
			  #if   defined (af__)
			  if (registerfarbgidriver(ATT_driver_far)<0)     exit(1);
			  #elif defined (an__)
			  if (registerfarbgidriver(ATT_driver)<0)         exit(1);
			  #endif
			  #if   defined (cf__)
			  if (registerfarbgidriver(CGA_driver_far)<0)     exit(1);
			  #elif defined (cn__)
			  if (registerfarbgidriver(CGA_driver)<0)         exit(1);
			  #endif
			  #if   defined (if__)
			  if (registerfarbgidriver(IBM8514_driver_far)<0) exit(1);
			  #elif defined (in__)
			  if (registerfarbgidriver(IBM8514_driver)<0)     exit(1);
			  #endif
			  #if   defined (pf__)
			  if (registerfarbgidriver(PC3270_driver_far)<0)  exit(1);
			  #elif defined (pn__)
			  if (registerfarbgidriver(PC3270_driver)<0)      exit(1);
			  #endif
			 }

void  huge buildchr(void){
			  #if   defined (sanff__)
			  if (registerfarbgifont(sansserif_font_far)<0)   exit(1);
			  #elif defined (sanfn__)
			  if (registerfarbgifont(sansserif_font)<0)       exit(1);
			  #endif
			  #if   defined (gotff__)
			  if (registerfarbgifont(gothic_font_far)<0)      exit(1);
			  #elif defined (gotfn__)
			  if (registerfarbgifont(gothic_font)<0)          exit(1);
			  #endif
			  #if   defined (smaff__)
			  if (registerfarbgifont(small_font_far)<0)       exit(1);
			  #elif defined (smafn__)
			  if (registerfarbgifont(small_font)<0)           exit(1);
			  #endif
			  #if   defined (triff__)
			  if (registerfarbgifont(triplex_font_far)<0)     exit (1);
			  #elif defined (trifn__)
			  if (registerfarbgifont(triplex_font)<0)         exit (1);
			  #endif
			  #if   defined (bolff__)
			  if (registerfarbgifont(bold_font_far)<0)        exit (1);
			  #elif defined (bolfn__)
			  if (registerfarbgifont(bold_font)<0)            exit (1);
			  #endif
			  #if   defined (eurff__)
			  if (registerfarbgifont(euro_font_far)<0)        exit (1);
			  #elif defined (eurfn__)
			  if (registerfarbgifont(euro_font)<0)            exit (1);
			  #endif
			  #if   defined (comff__)
			  if (registerfarbgifont(complex_font_far)<0)     exit (1);
			  #elif defined (comfn__)
			  if (registerfarbgifont(complex_font)<0)         exit (1);
			  #endif
			  #if   defined (scrff__)
			  if (registerfarbgifont(script_font_far)<0)      exit (1);
			  #elif defined (scrfn__)
			  if (registerfarbgifont(script_font)<0)          exit (1);
			  #endif
			  #if   defined (simff__)
			  if (registerfarbgifont(simplex_font_far)<0)     exit (1);
			  #elif defined (simfn__)
			  if (registerfarbgifont(simplex_font)<0)         exit (1);
			  #endif
			  #if   defined (tscff__)
			  if (registerfarbgifont(triplex_scr_font_far)<0) exit (1);
			  #elif defined (tscfn__)
			  if (registerfarbgifont(triplex_scr_font)<0)     exit (1);
			  #endif
			 }

int   huge init(int gdriver,int gmode)
	  {int errorcode;
	   initgraph(&gdriver,&gmode,"");
	   errorcode=graphresult();
	   if(errorcode!=grOk)
	     {printf("Initializes Graphics Error: %s\n",
		     grapherrormsg(errorcode));
	      printf("Press any key to return to command prompt:");
	      getch();
	      exit(1);}
	   gd=gdriver;
	   gm=gmode;
	   return 0;}

void  huge init(void)
	  {init(VGA,VGAMED);}

#endif