
void TGetBinApp::About(){
  TDialog *d=new TDialog(TRect(23, 7, 57, 18), "About Get Binary");
    d->insert(new TStaticText(TRect(1, 2, 33, 7),
	"\003Make a Text File \n\n\n"
	"\003Describe the Binary File\n\n\n"
	"\003Author / DanSei"));
    d->insert(new TButton(TRect(20, 8, 30, 10), " Ok", cmOK, bfDefault));
    d->options|=ofCentered;
    deskTop->execView(d);
    destroy(d);
}
