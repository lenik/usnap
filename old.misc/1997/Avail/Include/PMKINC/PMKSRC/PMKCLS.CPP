	void far colorcls(unsigned long count,unsigned char type,unsigned char lwidth)
	{register unsigned int a=0x1010,x=0,y=0,rr;while(count--)
	 {setcolor(random(16));setlinestyle(4,a,lwidth);a=random(0x8887);x=random(mx+1);y=random(my+1);rr=random(mx+my);
	  switch(type){case pset:putpixel(x,y,random(16));break;
		       case linex:line(random(2),y,mx,y);break;
		       case liney:line(x,random(2),x,my);break;
		       case cirmid:circle(mx/2,my/2,rr);break;
		       case cirmov:circle(x,y,rr);break;
		       default:;}if(bioskey(1)!=0)break;}}
