// Mainframe macro generated from application: /home/gkfthddk/source/root/bin/root.exe
// By ROOT version 6.13/02 on 2018-11-15 15:17:15
#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGColorDialog
#include "TGColorDialog.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGFontDialog
#include "TGFontDialog.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TRootContextMenu
#include "TRootContextMenu.h"
#endif
#ifndef ROOT_TGSlider
#include "TGSlider.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGProgressBar
#include "TGProgressBar.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif

#include "Riostream.h"
#include "TGDoubleSlider.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TApplication.h"
#include <stdio.h>
#include <stdlib.h>
#include <libusb-1.0/libusb.h>
#include "src/NoticeUOSDAQ3.h"
#include <time.h>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

class GetCondition {
        private:
                TGMainFrame *fMainFrame1658;
                TGTextButton *fRunButton, *fPedButton, *fStopButton, *fAnalyzeButton, *fSaveButton, *fLoadButton, *fExitButton;
                TGCheckButton *fLockCheck;
                TGTextEntry *fLoadEntry;
                TGLabel *fLabeldown, *fLabelup, *fLabel1432;
    TCanvas *c1,*c2,*c3,*c4,*c5;
    TGNumberEntry *fNumberEntry744, *fStripEntry, *fNumberEntry747;
    TGStatusBar *StatusBar;
    TGHProgressBar *ProgressBar;
    TGRadioButton *RadioButtonX, *RadioButtonY;
    TRootEmbeddedCanvas *TabCanvas1, *TabCanvas2, *TabCanvas3, *TabCanvas4, *TabCanvas5;
    TGCompositeFrame *fMainFrame2334, *fMainFrame5073;
    TGGroupFrame *fGroupFrame743;
    TGTab *fTab775;
        public:
                GetCondition(TGTextButton *_fRunButton, TGTextButton *_fPedButton, TGTextButton *_fStopButton, TGCheckButton *_fLockCheck,TGTextButton *_fAnalyzeButton,TGTextButton *_fSaveButton,TGTextButton *_fLoadButton,TGTextButton *_fExitButton,TGTextEntry *_fLoadEntry, TGLabel *_fLabeldown, TGLabel *_fLabelup, TGLabel *_fLabel1432, TGNumberEntry *_fNumberEntry747, TCanvas *_c1, TCanvas *_c2, TCanvas *_c3, TCanvas *_c4, TCanvas *_c5, TGNumberEntry *_fNumberEntry744, TGNumberEntry *_fStripEntry,TGStatusBar *_StatusBar, TGHProgressBar *_ProgressBar, TGRadioButton *_RadioButtonX, TGRadioButton *_RadioButtonY, TGMainFrame *_fMainFrame1658, TRootEmbeddedCanvas *_TabCanvas1, TRootEmbeddedCanvas *_TabCanvas2, TRootEmbeddedCanvas *_TabCanvas3, TRootEmbeddedCanvas *_TabCanvas4, TRootEmbeddedCanvas *_TabCanvas5, TGCompositeFrame *_fMainFrame2334, TGCompositeFrame *_fMainFrame5073, TGGroupFrame *_fGroupFrame743, TGTab *_fTab775);
                int RunNumber,nn;
                float sldown,slup;
		int res = 5; 
		int running =0;
	int size=1;
	int fsize=20*size;
	float wsize=20*size;
	float hsize=20*size;
	float bwsize=20*size;
	float bhsize=20*size;
  int sid;
    void Slider();
    void Load();
    void Exit();
    void Run();
    void Ped();
    void Stop();
    void Analyze();
    void Init();
    void EventInfo(Int_t event, Int_t px, Int_t py, TObject *selected);
    void RadioX();
    void RadioY();
    void Rescale();
    TFile *fp;
    TTree *intree;
    TH1F *hos1,*hos2,*h5;
    TH2F *h1, *h2, *h3;
    TH2F *h4;
    short px[100];
    short py[100];
  int pedX[100];
  int pedY[100];
    bool doPedestal = false;

};

GetCondition::GetCondition(TGTextButton *_fRunButton, TGTextButton *_fPedButton, TGTextButton *_fStopButton, TGCheckButton *_fLockCheck,TGTextButton *_fAnalyzeButton,TGTextButton *_fSaveButton,TGTextButton *_fLoadButton,TGTextButton *_fExitButton,TGTextEntry *_fLoadEntry, TGLabel *_fLabeldown, TGLabel *_fLabelup, TGLabel *_fLabel1432, TGNumberEntry *_fNumberEntry747, TCanvas *_c1, TCanvas *_c2, TCanvas *_c3, TCanvas *_c4, TCanvas *_c5, TGNumberEntry *_fNumberEntry744, TGNumberEntry *_fStripEntry,TGStatusBar *_StatusBar, TGHProgressBar *_ProgressBar, TGRadioButton *_RadioButtonX, TGRadioButton *_RadioButtonY, TGMainFrame *_fMainFrame1658, TRootEmbeddedCanvas *_TabCanvas1, TRootEmbeddedCanvas *_TabCanvas2, TRootEmbeddedCanvas *_TabCanvas3, TRootEmbeddedCanvas *_TabCanvas4, TRootEmbeddedCanvas *_TabCanvas5, TGCompositeFrame *_fMainFrame2334, TGCompositeFrame *_fMainFrame5073, TGGroupFrame *_fGroupFrame743, TGTab *_fTab775){
        fRunButton = _fRunButton;
        fPedButton = _fPedButton;
        fStopButton = _fStopButton;
        fAnalyzeButton = _fAnalyzeButton;
        fSaveButton = _fSaveButton;
        fLoadButton = _fLoadButton;
        fExitButton = _fExitButton;
        fLockCheck = _fLockCheck;
        fLoadEntry = _fLoadEntry;
        fLabeldown = _fLabeldown;
        fLabelup = _fLabelup;
	fLabel1432 = _fLabel1432;
       	RadioButtonX =_RadioButtonX;
       	RadioButtonY =_RadioButtonY;
        TabCanvas1=_TabCanvas1;
        TabCanvas2=_TabCanvas2;
        TabCanvas3=_TabCanvas3;
        TabCanvas4=_TabCanvas4;
        TabCanvas5=_TabCanvas5;
        fMainFrame2334=_fMainFrame2334;
        fMainFrame5073=_fMainFrame5073;
        fGroupFrame743=_fGroupFrame743;
        fTab775=_fTab775;
  fNumberEntry747 = _fNumberEntry747;
  fMainFrame1658=_fMainFrame1658;
  c1=_c1;
  c2=_c2;
  c3=_c3;
  c4=_c4;
  c5=_c5;
  fNumberEntry744=_fNumberEntry744;
  fStripEntry=_fStripEntry;
  StatusBar=_StatusBar;
  ProgressBar=_ProgressBar;
}


void GetCondition::Slider(){
  fLabeldown->SetText(sldown);
  fLabelup->SetText(slup);
}
void GetCondition::RadioX(){
	//RadioButtonY->SetState(kButtonDisabled);
	RadioButtonY->SetState(kButtonUp);
	fLabel1432->SetText("Y Strip");
}
void GetCondition::RadioY(){
	RadioButtonX->SetState(kButtonUp);
	fLabel1432->SetText("X Strip");
}
void GetCondition::Rescale(){
wsize=fMainFrame1658->GetWidth()/40.;
hsize=fMainFrame1658->GetHeight()/30.;
if(wsize!=bwsize||hsize!=bhsize){
bwsize=wsize;
bhsize=hsize;
TabCanvas1->MoveResize(0,0.1*hsize,29*wsize,26.4*hsize);
TabCanvas2->MoveResize(0,0.1*hsize,29*wsize,26.4*hsize);
TabCanvas3->MoveResize(0,0.1*hsize,29*wsize,26.4*hsize);
TabCanvas4->MoveResize(0,0.1*hsize,29*wsize,26.4*hsize);
TabCanvas5->MoveResize(0,0.1*hsize,29*wsize,26.4*hsize);
fMainFrame5073->Resize(40*wsize,30*hsize);
fMainFrame2334->Resize(40*wsize,30*hsize);
fGroupFrame743->MoveResize(29*wsize,8*hsize,11*wsize,22*hsize);
fTab775->MoveResize(1,1,29*wsize,28*hsize);
   fStopButton->MoveResize(37*wsize,1*hsize,2.5*wsize,1.5*hsize);
fExitButton->MoveResize(37*wsize,5*hsize,2.5*wsize,1.5*hsize);
    StatusBar->MoveResize(1,28*hsize,29*wsize,3.1*hsize);
    ProgressBar->MoveResize(1,29.5*hsize,29*wsize,0.5*hsize);
    fRunButton->MoveResize(30*wsize,3*hsize,2.5*wsize,1.5*hsize);
    fPedButton->MoveResize(30*wsize,5*hsize,4.5*wsize,1.5*hsize);
cout<<"rescale"<<endl;
}
}

void GetCondition::EventInfo(Int_t event, Int_t px, Int_t py, TObject *selected){
const char *text0, *text1;
text0=selected->GetTitle();
text1=selected->GetObjectInfo(px,py);
StatusBar->SetText(Form("%s : %s",text0,text1));

}

void GetCondition::Init(){
	res=3;
    TH2F* h1 = new TH2F("h1","2D Plot Title" , res*100, 0, 100,res*100,0,100);
    h1->Fill(50,50);
    gStyle->SetPalette(kRainBow);
    cout<<"##"<<endl;
    cout<<h1<<endl;
    cout<<"##"<<endl;
    h1->SetStats(0);
    c1->cd();
    h1->Draw("colz");
    TH2F* h2 = new TH2F("h2","Spectrum Plot Title" , res*100, 0, 100,res*100,0,100);
    h2->SetStats(0);
    c2->cd();
    h2->Draw("colz");
    TH2F* h3 = new TH2F("h3","Strip Sum Plot Title" , res*100, 0, 100,res*100,0,100);
    h3->SetStats(0);
    c3->cd();
    h3->Draw("colz");
    TH2F* h4 = new TH2F("h4","Strip Waveform Plot Title" , 1000, 0, 1000,100,0,100);
    h4->SetStats(0);
    c4->cd();
    h4->Draw("colz");
    TH1F* h5 = new TH1F("h5","Count Plot Title" , 100, 0, 100);
    h5->SetStats(0);
    c5->cd();
    h5->Draw();
    RadioButtonY->SetState(kButtonDown);
}
void GetCondition::Run(){
  ProgressBar->Reset();
	if(running==0){
  running =1;
  double sec;
  int gain;
  int pol;
  int dec;
  int nread, nsample;
  unsigned char data[16384];
  int adcX[100];
  int adcY[100];
  int i;
  int ch;
  int frame;
  int co=0;
  int maxh=0;
  int cut=fNumberEntry747->GetNumber();
  cout<<cut<<endl;
  int xcut=cut;
  int ycut=cut;
  int count=0;
  sid = 1;
  sec = 1;
  gain = 0;
  pol = 0;
  dec = 1;

  res=1;
  h1 = new TH2F("h1","DAQ Plot Title" , res*100, 0, 100,res*100,0,100);
  h1->SetStats(0);
  h1->GetXaxis()->SetTitle("X strips");
  h1->GetYaxis()->SetTitle("Y strips");
  h1->GetYaxis()->SetTitleOffset(1.2);
  gStyle->SetPalette(kRainBow);
  c1->cd();
  h1->Draw("colz");
  c1->SetMargin(0.09,0.13,.07,0.06);
  TH2F* h2 = new TH2F("h3","Spectrum Plot Title" , res*100, 100, 1000,res*100,100,1000);
  h2->SetStats(0);
  TH2F* h4 = new TH2F("h4","Strip Waveform Plot Title" , 2000, 0, 2000,100,0,100);
  h4->GetXaxis()->SetTitle("Entries");
  if(RadioButtonX->IsDown()){
  h4->SetTitle("X Strip Waveform Plot Title");
  h4->GetYaxis()->SetTitle("X strips");
	}
  else{
  //h4->SetTitle("DAQ Plot Title");
  h4->SetTitle("Y Strip Waveform Plot Title");
  h4->GetYaxis()->SetTitle("Y strips");
	}
  h4->GetYaxis()->SetTitleOffset(1.2);
  h4->SetStats(0);
  TH1F* h5 = new TH1F("h5","Count Plot Title" , 100, 0, 100);
  h5->SetStats(0);
  /*###
  // open USB3
  UOSDAQ3init(0);
  // open UOSDAQ3  
  UOSDAQ3open(sid, 0);
  // write settings
  UOSDAQ3setup_DAQ(sid, gain, pol, dec);
  // get # of frames to take
  // 32 frames per read
  nread = UOSDAQ3get_NUM(sec, dec);
  nsample = 0*nread * 32;
  // reset DAQ
  UOSDAQ3reset(sid);
  // start DAQ by software
  UOSDAQ3start_DAQ(sid);
  ###*/
  nread=10000;
  nsample=0;
  auto inf=new TFile("frog.root","read");
  auto intree=(TTree*) inf->Get("data");
  short px[100];
  short py[100];
  int xchek=0;
  int ychek=0;
  int entry=0;
  intree->SetBranchAddress("px",&px);
  intree->SetBranchAddress("py",&py);
  
  int cycle=fNumberEntry744->GetNumber();
  int cycle1=fNumberEntry744->GetNumber();
  if(cycle<0){
	  cycle=1;
	  fNumberEntry744->SetNumber(1);
  }
  cout<<"runing..."<<endl;
  while(1){
  cycle=fNumberEntry744->GetNumber();
  cycle1=fNumberEntry744->GetNumber();
    co+=1;
cout<<co<<" count cycle "<<cycle<<endl;
cout<<fNumberEntry744->GetNumber()<<endl;
    if(co>cycle1){
cout<<"cycle break"<<endl;
break;}
    if(running==0){
      cout<<endl<<"break"<<endl;
          cout<<"@"<<endl;
      break;}
  for (i = 0; i < nread; i++) {
	  ProgressBar->Increment(100./(nread*cycle));
	  //cout<<(1./(nread*cyc))<<endl;
    gSystem->ProcessEvents();
    if(running==0){
      cout<<endl<<"break"<<endl;
      break;}
    
    // reads 16384 char at once
    // each 'event' is 512 char
    //###UOSDAQ3read_DATA(sid, data);
    // reads 32 events at once
    //printf("nread:: %i \n", i);
    for (int event =0; event < 32; ++event) {
      entry+=1;
      //unsigned char data[16384];
      //###unsigned char *evdata = &(data[event*512]);
      //###UOSDAQ3get_DATA(evdata, adcX, adcY, &frame);
      intree->GetEntry(entry);
      for(int ii=0;ii<100;ii++){
        adcX[ii]=px[ii];
        adcY[ii]=py[ii];
        pedX[ii]=0;
        pedY[ii]=0;
      }
      // std::cout <<"evdata:: "<< evdata<<std::endl;
      // for (int cc=0; cc<512; ++cc) {
      //   std::cout << std::bitset<4>(evdata[cc]);
      // }
      
      //printf("frame:: %i \n", frame);
    nsample +=1;
      for (ch = 0; ch < 100; ch++) {
        if(doPedestal) {
          pedX[ch] += adcX[ch];
          pedY[ch] += adcY[ch];          
        }
        /*###else {
          for(int chh=0;chh<100;chh++)h2->Fill(adcX[chh],adcY[ch]);
          adcX[ch] = adcX[ch]-(pedX[ch]);
          adcY[ch] = adcY[ch]-(pedY[ch]);
        //  cout<<"run"<<adcX[ch]<<endl;
        }*/
	  if(nsample<3000){
            if(RadioButtonX->IsDown()){
		  h4->SetBinContent(nsample-1000,ch+1,adcY[int(fStripEntry->GetNumber())]);
	    }
	    else {
		  h4->SetBinContent(nsample-1000,ch+1,adcX[int(fStripEntry->GetNumber())]);
	    }
	  }
      }
      //Fill histogram
      if(!doPedestal){
      int xlist[10],ylist[10];
      for(int ii=0;ii<10;ii++){
      xlist[ii]=-1;
      ylist[ii]=-1;
      }
      int xval=0;
      int yval=0;
      int xvalb=0;
      int yvalb=0;
      int xco=0;
      int yco=0;
      int xpi=0;
      int ypi=0;
      bool xup=false;
      bool yup=false;
      int xi=0;
      int yi=0;
      for(int ii=0;ii<100;ii++){
        xco-=1;
        if(adcX[ii]>xcut){
         xpi+=1;
         xval=adcX[ii];
         if(xco<0){
         if(xlist[xi]!=-1){xi+=1;}
         xup=true;
         xco=3;
         xpi=0;
         }
         else if(xpi==1&&xco==0){
         if(xlist[xi]!=-1){xi+=1;}
         xup=true;
         xco=3;
         xpi=0;
         }
         else{
         if(xup==true){
           if(xval<xvalb){
             xup=false;
             //if(xlist[xi]==-1)xlist[xi]=ii;
           }
           else{xlist[xi]=ii;}
         }
         else{
           xi+=1;
         }
         }
        xvalb=xval;
        }
        yco-=1;
        if(adcY[ii]>ycut){
         ypi+=1;
         yval=adcY[ii];
         if(yco<0){
         if(ylist[yi]!=-1){yi+=1;}
         yup=true;
         yco=3;
         ypi=0;
         }
         else if(ypi==1&&yco==0){
         if(ylist[yi]!=-1){yi+=1;}
         yup=true;
         yco=3;
         ypi=0;
         }
         else{
         if(yup==true){
           if(yval<yvalb){
             yup=false;
             //if(ylist[yi]==-1)ylist[yi]=ii;
           }
           else{ylist[yi]=ii;}
         }
         else{
           yi+=1;
         }
         }
        yvalb=yval;
        }
      } 
      for(int ii=0;ii<10;ii++){
        if(xlist[ii]==-1||ylist[ii]==-1){
         xi=ii;
         break;
         }
      }
      int left=0;
      int right=xi-1;
      int temp;
      while(left<right){
        left=0;
        while(left<right){
        if(adcX[xlist[left]]<adcX[xlist[left+1]]){
        temp=xlist[left];
        xlist[left]=xlist[left+1];
        xlist[left+1]=temp;
        }
        left++;
        }
        right--;
        
      }
      /*if(xi>=2){cout<<xi<<endl;
      for(int ii=0;ii<xi;ii++){
       cout<<adcX[xlist[ii]]<<" "<<adcY[ylist[ii]]<<endl;
      }
      }*/
 
      for(int ii=0;ii<xi;ii++)h1->Fill(xlist[ii],ylist[ii]);
      h5->Fill(count/1000,xi);
      count+=1;
      
      /*if(distance(adcX,max_element(adcX,adcX+100))==0||distance(adcY,max_element(adcY,adcY+100))==0)continue;
      if((*max_element(adcX,adcX+100)+*max_element(adcY,adcY+100))/2<cut)continue;
      h1->Fill(distance(adcX,max_element(adcX,adcX+100)),distance(adcY,max_element(adcY,adcY+100))); 
      */
      

      }
    }
  }

  // normalising pedestals
  cout<<"drawing"<<endl;
  c1->cd();
  h1->Draw("colz");
  c1->Modified();
  c1->Update();
  c2->cd();
  h2->Draw("colz");
  c2->Modified();
  c2->Update();
  }


  if(doPedestal) {
    h3 = new TH2F("h3","Strip Sum Plot Title" , 100, 0, 100,100,0,100);
    h3->SetStats(0);
  for (ch = 0; ch < 100; ch++) {
      pedX[ch] = pedX[ch]/nsample;
      pedY[ch] = pedY[ch]/nsample;          
      //cout<<pedX[ch]<<endl;
    }
  cout<<nsample<<endl;
  for (ch = 0; ch < 100; ch++) {
          for (int chh = 0; chh < 100; chh++) {
	    h3->SetBinContent(ch+1,chh+1,pedX[ch]+pedY[chh]);
	  }
  }
  cout<<nsample<<endl;
   c3->cd();
   h3->Draw("colz");
   c3->Modified();
   c3->Update();
  }
   c4->cd();
	   h4->GetYaxis()->SetRange(h4->GetMinimum(),h4->GetMaximum());
   h4->Draw("colz");
   c4->Modified();
   c4->Update();
   c5->cd();
   h5->Draw("Hist C");
   c5->Modified();
   c5->Update();
   
/*###
  UOSDAQ3stop_DAQ(sid);
  UOSDAQ3close(sid);
  UOSDAQ3exit(0);
###*/
  c1->cd();
  //h1->Fill(50,50);
  h1->Draw("colz");
  c1->Modified();
  c1->Update();

/*  while(1){
    gSystem->ProcessEvents();
    co+=1;
    if(running==0){cout<<endl<<"break"<<endl;break;}
    if(co>200000)break;
  }*/
  cout<<maxh<<endl;
  running = 0;
  doPedestal = false;
cout<<entry<<endl;
  }
}

void GetCondition::Ped(){
if(running==0){
doPedestal = true;
  for(int i=0;i<100;i++){
  pedX[i]=0;
  pedY[i]=0;
}
cout<<"pedestal"<<endl;
GetCondition::Run();
}
}

void GetCondition::Stop(){
    cout<<h1<<endl;
    cout<<fNumberEntry744->GetNumber()<<endl;
running =0;
}
void GetCondition::Exit(){
if(!fLockCheck->IsDown()){
running =0;
  gApplication->Terminate(0);
}
}
void GetCondition::Load(){
  cout<<fLoadEntry->GetText()<<endl;
  fp = new TFile(Form("%s.root",fLoadEntry->GetText()), "read");
        if (!fp->IsOpen()){
                printf("Unable to open file %s.root!\n", fLoadEntry->GetText());
        }
        else{
                printf("Successfully opened file %s.root!\n", fLoadEntry->GetText());
		int nn=0;
		h1 = new TH2F("h1","DAQ Plot Title" , res*100, 0, 100,res*100,0,100);
		intree=(TTree*) fp->Get("data");
		intree->SetBranchAddress("px",&px);
		intree->SetBranchAddress("py",&py);
                hos1 = new TH1F("hos1", "hist", 100, 0, 100);
                hos2 = new TH1F("hos2", "hist", 100, 0, 100);
          }
}
void GetCondition::Analyze(){
	if (!fp->IsOpen()){
                printf("Need to load file!\n");
        }
        else{
		gStyle->SetOptStat(0);

  //TCanvas *c1 = new TCanvas("c1", "MECAR GEM Detector Kit", 1000, 800);
  gPad->SetLeftMargin(0.15);
  gPad->SetRightMargin(0.15);
  //int res=5;
  gStyle->SetPalette(kRainBow);
  int maxx,maxy;
  int cnt=0;
  int skpx,skpy;
  int xcut=40;
  int ycut=60;
  int idx1,idx2,idy1,idy2;
  int xchek,ychek;
  float bx,by,bv;
  int NN=intree->GetEntries();
 for (int i = 0; i < 1000; i++) {
    nn+=1;
    if(nn==NN)break;
    // read frame number
    intree->GetEntry(nn);
    xchek=0;ychek=0;
    skpx=0;skpy=0;
    // fill X channel
    maxx=0;maxy=0;
    idx1=-1;idy1=-1;idx2=-1;idy2=-1;
    py[74]=0.55*(py[73]+py[75]);
    px[2]=0.6*(px[1]+py[3]);
    for(int j=0;j<100;j++){
      hos1->SetBinContent(j+1,px[j]);
      hos2->SetBinContent(j+1,py[j]);
      if(skpx>0){
        skpx-=1;
      }else{
        if(px[j]>xcut){
          if(px[j-1]>8||px[j+1]>8){
            if(idx1==-1){
              idx1=distance(px,max_element(px+j-3,px+j+4));
              skpx+=3;
            }else if(idx2==-1){
              if(idx1<j-4){
                idx2=distance(px,max_element(px+j-3,px+j+4));
                skpx+=3;
              }else{
                idx1=-1;
              }
            }else{
              if(idx2<j-4){
                if(px[idx1]<px[idx2]&&px[idx1]<px[j]){
                  idx1=distance(px,max_element(px+j-3,px+j+4));
                  skpx+=3;
                }else if(px[idx2]<px[idx1]&&px[idx2]<px[j]){
                  idx2=distance(px,max_element(px+j-3,px+j+4));
                  skpx+=3;
                }
              }else{
                idx2=-1;
              }
            }
          }
        }
      }
      if(skpy>0){
        skpy-=1;
      }else{
        if(py[j]>ycut){
          if(py[j-1]>8||py[j+1]>8){
            if(idy1==-1){
              idy1=distance(py,max_element(py+j-3,py+j+4));
              skpy+=3;
            }else if(idy2==-1){
              if(idy1<j-4){
                idy2=distance(py,max_element(py+j-3,py+j+4));
                skpy+=3;
              }else{
                idy1=-1;
              }
            }else{
              if(idy2<j-4){
                if(py[idy1]<py[idy2]&&py[idy1]<py[j]){
                  idy1=distance(py,max_element(py+j-3,py+j+4));
                  skpy+=3;
                }else if(py[idy2]<py[idy1]&&py[idy2]<py[j]){
                  idy2=distance(py,max_element(py+j-3,py+j+4));
                  skpy+=3;
                }
              }else{
                idy2=-1;
              }
            }
          }
        }
      }
    }
    for(int j=0;j<2;j++){
    if(idx1!=-1&&idy1!=-1){
      hos1->Fit("gaus","Q","",idx1-3,idx1+3);
      hos2->Fit("gaus","Q","",idy1-3,idy1+3);
      bx=hos1->GetFunction("gaus")->GetParameter(1);
      by=hos2->GetFunction("gaus")->GetParameter(1);
      if(bx>=0&&by>=0&&bx<100&&by<100&&bx>idx1-5&&bx<idx1+5&&by>idy1-5&&by<idy1+5){
        bx=hos1->GetFunction("gaus")->GetMaximumX();
        by=hos2->GetFunction("gaus")->GetMaximumX();
        maxx=*max_element(px+idx1-3,px+idx1+4);
        maxy=*max_element(py+idy1-3,py+idy1+4);
        if(maxx*4>hos1->GetFunction("gaus")->GetMaximum()&&maxy*4>hos2->GetFunction("gaus")->GetMaximum()&&maxx/2<hos1->GetFunction("gaus")->GetMaximum()&&maxy/2<hos2->GetFunction("gaus")->GetMaximum()){
        maxx=hos1->GetMaximum();
        maxy=hos2->GetMaximum();
for(float l=-2.;l<2.+1./res;l+=1./res){
        for(float m=-2.;m<2.+1./res;m+=1./res){
            if(m==0){
              h1->Fill(bx+l,by+m,1.*maxy/maxx*hos1->GetFunction("gaus")->Eval(bx+l));
            }
            else if(l==0){
              h1->Fill(bx+l,by+m,1.*hos2->GetFunction("gaus")->Eval(by+m));
            }
            else{
              bv=sqrt(m*m+l*l);
              h1->Fill(bx+l,by+m,(1.*maxy/maxx*hos1->GetFunction("gaus")->Eval(bx+bv)+hos2->GetFunction("gaus")->Eval(by+bv))/2.);
              }
        }
        }
        cnt+=1;
        break;
      }
      }
      idx1=idx2;
      idy1=idy2;
      }
      }
      hos1->Reset();
      hos2->Reset();
   }
c1->cd();
h1->SetStats(0);
        h1->GetXaxis()->SetTitle("X strips");
        h1->GetYaxis()->SetTitle("Y strips");
        h1->GetYaxis()->SetTitleOffset(1.2);
        h1->Draw("colz");

        c1->SetMargin(0.09,0.13,.07,0.06);
        c1->Modified();
        c1->Update();

          }
}







void rungui()
{
	int size=1;
	int fsize=20;

   // main frame
   TGMainFrame *fMainFrame1658 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame1658->SetName("fMainFrame1658");
   fMainFrame1658->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame2334 = new TGCompositeFrame(fMainFrame1658,612,440,kVerticalFrame);
   fMainFrame2334->SetName("fMainFrame2334");
   fMainFrame2334->SetLayoutBroken(kTRUE);

   ULong_t ucolor;        // will reflect user color changes
   gClient->GetColorByName("#fafafa",ucolor);

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize));
   TGGC   *uGC;           // will reflect user GC changes
   // composite frame
   TGCompositeFrame *fMainFrame5073 = new TGCompositeFrame(fMainFrame2334,615,444,kVerticalFrame,ucolor);
   fMainFrame5073->SetName("fMainFrame5073");
   fMainFrame5073->SetLayoutBroken(kTRUE);

   GCValues_t valButton738;
   valButton738.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton738.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton738.fBackground);
   valButton738.fFillStyle = kFillSolid;
   valButton738.fFont = ufont->GetFontHandle();
   valButton738.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton738, kTRUE);

   gClient->GetColorByName("#33ff33",ucolor);
   TGTextButton *fExitButton = new TGTextButton(fMainFrame5073,"Exit",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fExitButton->SetTextJustify(36);
   fExitButton->SetMargins(0,0,0,0);
   fExitButton->SetWrapLength(-1);
   fMainFrame5073->AddFrame(fExitButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fExitButton->MoveResize(37*fsize,5*fsize,2.5*fsize,1.5*fsize);

   gClient->GetColorByName("#33ffff",ucolor);
   TGTextButton *fSaveButton = new TGTextButton(fMainFrame5073,"Save",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fSaveButton->SetTextJustify(36);
   fSaveButton->SetMargins(0,0,0,0);
   fSaveButton->SetWrapLength(-1);
   fSaveButton->Resize(1.8*fsize,1.1*fsize);

   fSaveButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fSaveButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   //commentfSaveButton->MoveResize(522*size,64*size,36*size,23*size);

   gClient->GetColorByName("#cc33ff",ucolor);
   TGTextButton *fLoadButton = new TGTextButton(fMainFrame5073,"Load",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fLoadButton->SetTextJustify(36);
   fLoadButton->SetMargins(0,0,0,0);
   fLoadButton->SetWrapLength(-1);
   fLoadButton->Resize(1.8*fsize,1.1*fsize);

   fLoadButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fLoadButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   //commentfLoadButton->MoveResize(562*size,64*size,36*size,23*size);

   // status bar
   TGStatusBar *StatusBar = new TGStatusBar(fMainFrame5073,404,25);
   StatusBar->SetName("StatusBar");
   StatusBar->SetText("Dummy text",0);
   fMainFrame5073->AddFrame(StatusBar, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));
   StatusBar->MoveResize(1,28*fsize,29*fsize,3.1*fsize);
   //StatusBar->SetText(selected->GetTitle(),0);
   
   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize));

   // graphics context changes
   GCValues_t valpFrame743;
   valpFrame743.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valpFrame743.fForeground);
   gClient->GetColorByName("#e8e8e8",valpFrame743.fBackground);
   valpFrame743.fFillStyle = kFillSolid;
   valpFrame743.fFont = ufont->GetFontHandle();
   valpFrame743.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valpFrame743, kTRUE);

   gClient->GetColorByName("#a3aeb5",ucolor);

   TGHProgressBar *ProgressBar = new TGHProgressBar(fMainFrame5073,TGProgressBar::kStandard,100);
   ProgressBar->MoveResize(1,29.5*fsize,29*fsize,0.5*fsize); 
   //ProgressBar->ShowPosition();
   ProgressBar->SetFillType(TGProgressBar::kBlockFill);
   ProgressBar->SetBarColor("lightgreen");

   // "Options" group frame
   TGGroupFrame *fGroupFrame743 = new TGGroupFrame(fMainFrame5073,"Options",kVerticalFrame,uGC->GetGC(),ufont->GetFontStruct(),ucolor);
   fGroupFrame743->SetLayoutBroken(kTRUE);

   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize*2/3));
   GCValues_t vall1431;
   vall1431.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1431.fForeground);
   gClient->GetColorByName("#e8e8e8",vall1431.fBackground);
   vall1431.fFillStyle = kFillSolid;
   vall1431.fFont = ufont->GetFontHandle();
   vall1431.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1431, kTRUE);
   TGLabel *fLabel1431 = new TGLabel(fGroupFrame743,"1431",uGC->GetGC());
   fLabel1431->SetTextJustify(36);
   fLabel1431->SetMargins(0,0,0,0);
   fLabel1431->SetWrapLength(-1);
   fGroupFrame743->AddFrame(fLabel1431, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1431->MoveResize(1*fsize,8*fsize,5*fsize,1*fsize);
   fLabel1431->SetText(" waveform");

   GCValues_t vall1432;
   vall1432.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1432.fForeground);
   gClient->GetColorByName("#e8e8e8",vall1432.fBackground);
   vall1432.fFillStyle = kFillSolid;
   vall1432.fFont = ufont->GetFontHandle();
   vall1432.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1432, kTRUE);
   TGLabel *fLabel1432 = new TGLabel(fGroupFrame743,"1432",uGC->GetGC());
   fLabel1432->SetTextJustify(36);
   fLabel1432->SetMargins(0,0,0,0);
   fLabel1432->SetWrapLength(-1);
   fGroupFrame743->AddFrame(fLabel1432, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1432->MoveResize(5*fsize,9*fsize,3*fsize,1*fsize);
   fLabel1432->SetText("X strip");
   TGNumberEntry *fStripEntry = new TGNumberEntry(fGroupFrame743, (Double_t) 1,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame743->AddFrame(fStripEntry, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,24,2));
   fStripEntry->MoveResize(5*fsize,10*fsize,3*fsize,1*fsize);
   fStripEntry->SetLimits(TGNumberFormat::kNELLimitMinMax,0,100);
   fStripEntry->SetNumber(42);

   TGRadioButton *RadioButtonX = new TGRadioButton(fGroupFrame743, TGHotString("&X Strip"));
   fGroupFrame743->AddFrame(RadioButtonX, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   RadioButtonX->MoveResize(1*fsize,9*fsize,3*fsize,1*fsize);
   TGRadioButton *RadioButtonY = new TGRadioButton(fGroupFrame743, TGHotString("&Y Strip"));
   fGroupFrame743->AddFrame(RadioButtonY, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   RadioButtonY->MoveResize(1*fsize,10*fsize,3*fsize,1*fsize);


   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");
   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize));

   // graphics context changes
   gClient->GetColorByName("#ffcc00",ucolor);
   TGTextButton *fAnalyzeButton = new TGTextButton(fMainFrame5073,"Analyze",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fAnalyzeButton->SetTextJustify(36);
   fAnalyzeButton->SetMargins(0,0,0,0);
   fAnalyzeButton->SetWrapLength(-1);
   fAnalyzeButton->Resize(2.5*fsize,1*fsize);
   fAnalyzeButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fAnalyzeButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   //fAnalyzeButton->MoveResize(458*size,300+64*size,52*size,23*size);


   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",int(fsize/1.5)));

   // graphics context changes
   TGNumberEntry *fNumberEntry744 = new TGNumberEntry(fGroupFrame743, (Double_t) 1,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame743->AddFrame(fNumberEntry744, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,24,2));
   fNumberEntry744->MoveResize(1*fsize,3*fsize,4*fsize,1*fsize);
   fNumberEntry744->SetLimits(TGNumberFormat::kNELLimitMin,0);
   GCValues_t vall1331;
   vall1331.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#ffffff",vall1331.fForeground);
   gClient->GetColorByName("#000000",vall1331.fBackground);
   vall1331.fFillStyle = kFillSolid;
   vall1331.fFont = ufont->GetFontHandle();
   vall1331.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1331, kTRUE);
   TGLabel *fLabel1331 = new TGLabel(fGroupFrame743,"1331",uGC->GetGC());
   fLabel1331->SetTextJustify(36);
   fLabel1331->SetMargins(0,0,0,0);
   fLabel1331->SetWrapLength(-1);
   fGroupFrame743->AddFrame(fLabel1331, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1331->MoveResize(1*fsize,2.*fsize,4*fsize,1.*fsize);
   fLabel1331->SetText("Run Second");
   gClient->GetColorByName("#000000",ucolor);
   fLabel1331->ChangeBackground(ucolor);
   
   TGNumberEntry *fNumberEntry747 = new TGNumberEntry(fGroupFrame743, (Double_t) 1,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame743->AddFrame(fNumberEntry747, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,24,2));
   fNumberEntry747->MoveResize(1*fsize,6*fsize,4*fsize,1*fsize);
   fNumberEntry747->SetLimits(TGNumberFormat::kNELLimitMin,0);
   uGC = gClient->GetGC(&vall1331, kTRUE);
   TGLabel *fLabel1337 = new TGLabel(fGroupFrame743,"1331",uGC->GetGC());
   fLabel1337->SetTextJustify(36);
   fLabel1337->SetMargins(0,0,0,0);
   fLabel1337->SetWrapLength(-1);
   fGroupFrame743->AddFrame(fLabel1337, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1337->MoveResize(1*fsize,5.*fsize,4*fsize,1.*fsize);
   fLabel1337->SetText("Cut");
   gClient->GetColorByName("#000000",ucolor);
   fLabel1337->ChangeBackground(ucolor);
   //
   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize));
   GCValues_t vall1311;
   vall1311.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1311.fForeground);
   gClient->GetColorByName("#e8e8e8",vall1311.fBackground);
   vall1311.fFillStyle = kFillSolid;
   vall1311.fFont = ufont->GetFontHandle();
   vall1311.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1311, kTRUE);
   TGLabel *fLabel1311 = new TGLabel(fGroupFrame743,"1311",uGC->GetGC());
   fLabel1311->SetTextJustify(36);
   fLabel1311->SetMargins(0,0,0,0);
   fLabel1311->SetWrapLength(-1);
   fGroupFrame743->AddFrame(fLabel1311, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1311->MoveResize(0*fsize,0*fsize,0*fsize,0.*fsize);
   
   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize*2/3));

   GCValues_t vall1313;
   vall1313.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1313.fForeground);
   gClient->GetColorByName("#e8e8e8",vall1313.fBackground);
   vall1313.fFillStyle = kFillSolid;
   vall1313.fFont = ufont->GetFontHandle();
   vall1313.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1313, kTRUE);
   TGLabel *fLabel1313 = new TGLabel(fGroupFrame743,"1313",uGC->GetGC());
   fLabel1313->SetTextJustify(36);
   fLabel1313->SetMargins(0,0,0,0);
   fLabel1313->SetWrapLength(-1);
   fGroupFrame743->AddFrame(fLabel1313, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1313->MoveResize(0*fsize,0*fsize,0*fsize,0*fsize);


   fGroupFrame743->SetLayoutManager(new TGVerticalLayout(fGroupFrame743));
   fGroupFrame743->Resize(200,340);
   fMainFrame5073->AddFrame(fGroupFrame743, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,0,2,0));
   fGroupFrame743->MoveResize(29*fsize,8*fsize,11*fsize,22*fsize);


   // graphics context changes
   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize));
   GCValues_t valButton748;
   valButton748.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton748.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton748.fBackground);
   valButton748.fFillStyle = kFillSolid;
   valButton748.fFont = ufont->GetFontHandle();
   valButton748.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton748, kTRUE);

   gClient->GetColorByName("#33ff33",ucolor);
   TGTextButton *fRunButton = new TGTextButton(fMainFrame5073,"Run",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fRunButton->SetTextJustify(36);
   fRunButton->SetMargins(0,0,0,0);
   fRunButton->SetWrapLength(-1);
   fRunButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fRunButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fRunButton->MoveResize(30*fsize,3*fsize,2.5*fsize,1.5*fsize);

   gClient->GetColorByName("#33aa33",ucolor);
   TGTextButton *fPedButton = new TGTextButton(fMainFrame5073,"Pedestal",-1,uGC->GetGC(),ufont->GetFontStruct(),kRaisedFrame);
   fPedButton->SetTextJustify(36);
   fPedButton->SetMargins(0,0,0,0);
   fPedButton->SetWrapLength(-1);

   fPedButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fPedButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPedButton->MoveResize(30*fsize,5*fsize,4.5*fsize,1.5*fsize);

   ufont = gClient->GetFont(Form("-*-helvetica-medium-r-*-*-%d-*-*-*-*-*-iso8859-1",fsize));

   // graphics context changes
   GCValues_t valButton749;
   valButton749.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valButton749.fForeground);
   gClient->GetColorByName("#e8e8e8",valButton749.fBackground);
   valButton749.fFillStyle = kFillSolid;
   valButton749.fFont = ufont->GetFontHandle();
   valButton749.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valButton749, kTRUE);

   gClient->GetColorByName("#ff3333",ucolor);
   TGTextButton *fStopButton = new TGTextButton(fMainFrame5073,"Stop",-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame);
   fStopButton->SetTextJustify(36);
   fStopButton->SetMargins(0,0,0,0);
   fStopButton->SetWrapLength(-1);
   fStopButton->SetState(kButtonDown);

   fStopButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fStopButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fStopButton->MoveResize(37*fsize,1*fsize,2.5*fsize,1.5*fsize);



   gClient->GetColorByName("#ffffff",ucolor);

   TGTab *fTab775 = new TGTab(fMainFrame5073,416,376,uGC->GetGC(),ufont->GetFontStruct(),kChildFrame,ucolor);

   // container of "Tab1"
   TGCompositeFrame *fCompositeFrame1;
   fCompositeFrame1 = fTab775->AddTab("2D Plot");
   //TGTabElement *fTabElement = fTab775->GetCurrentTab();
   //TGString *fst=new TGString("aaaa");
   //fTabElement->SetText(fst);
   fCompositeFrame1->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1));
   // embedded canvas
   TRootEmbeddedCanvas *TabCanvas1 = new TRootEmbeddedCanvas("c1",fCompositeFrame1,450,400,kSunkenFrame,ucolor);
   TabCanvas1->SetName("TabCanvas1");
   Int_t wTabCanvas1 = TabCanvas1->GetCanvasWindowId();
   TCanvas *tc1 = new TCanvas("tc1", 200, 200, wTabCanvas1);
   TabCanvas1->AdoptCanvas(tc1);
   fCompositeFrame1->AddFrame(TabCanvas1, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,0,1,0));
   TabCanvas1->MoveResize(0,0.1*fsize,29*fsize,26.4*fsize);

   // container of "Tab2"
   TGCompositeFrame *fCompositeFrame2;
   fCompositeFrame2 = fTab775->AddTab("Spectrum");
   fCompositeFrame2->SetLayoutManager(new TGVerticalLayout(fCompositeFrame2));

   TRootEmbeddedCanvas *TabCanvas2 = new TRootEmbeddedCanvas("c2",fCompositeFrame2,450,400,kSunkenFrame,ucolor);
   TabCanvas2->SetName("TabCanvas2");
   Int_t wTabCanvas2 = TabCanvas2->GetCanvasWindowId();
   TCanvas *tc2 = new TCanvas("tc2", 200, 200, wTabCanvas2);
   TabCanvas2->AdoptCanvas(tc2);
   fCompositeFrame2->AddFrame(TabCanvas2, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,0,1,0));
   TabCanvas2->MoveResize(0,0.1*fsize,29*fsize,26.4*fsize);

   // container of "Tab3"
   TGCompositeFrame *fCompositeFrame3;
   fCompositeFrame3 = fTab775->AddTab("Strip Sum");
   fCompositeFrame3->SetLayoutManager(new TGVerticalLayout(fCompositeFrame3));

   TRootEmbeddedCanvas *TabCanvas3 = new TRootEmbeddedCanvas("c3",fCompositeFrame3,450,400,kSunkenFrame,ucolor);
   TabCanvas3->SetName("TabCanvas3");
   Int_t wTabCanvas3 = TabCanvas3->GetCanvasWindowId();
   TCanvas *tc3 = new TCanvas("tc3", 200, 200, wTabCanvas3);
   TabCanvas3->AdoptCanvas(tc3);
   fCompositeFrame3->AddFrame(TabCanvas3, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,0,1,0));
   TabCanvas3->MoveResize(0,0.1*fsize,29*fsize,26.4*fsize);

   // container of "Tab4"
   TGCompositeFrame *fCompositeFrame4;
   fCompositeFrame4 = fTab775->AddTab("Strip Waveform");
   fCompositeFrame4->SetLayoutManager(new TGVerticalLayout(fCompositeFrame4));

   TRootEmbeddedCanvas *TabCanvas4 = new TRootEmbeddedCanvas("c4",fCompositeFrame4,450,400,kSunkenFrame,ucolor);
   TabCanvas4->SetName("TabCanvas4");
   Int_t wTabCanvas4 = TabCanvas4->GetCanvasWindowId();
   TCanvas *tc4 = new TCanvas("tc4", 200, 200, wTabCanvas4);
   TabCanvas4->AdoptCanvas(tc4);
   fCompositeFrame4->AddFrame(TabCanvas4, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,0,1,0));
   TabCanvas4->MoveResize(0,0.1*fsize,29*fsize,26.4*fsize);
   
   // container of "Tab5"
   TGCompositeFrame *fCompositeFrame5;
   fCompositeFrame5 = fTab775->AddTab("Count");
   fCompositeFrame5->SetLayoutManager(new TGVerticalLayout(fCompositeFrame5));

   TRootEmbeddedCanvas *TabCanvas5 = new TRootEmbeddedCanvas("c5",fCompositeFrame5,450,400,kSunkenFrame,ucolor);
   TabCanvas5->SetName("TabCanvas5");
   Int_t wTabCanvas5 = TabCanvas5->GetCanvasWindowId();
   TCanvas *tc5 = new TCanvas("tc5", 200, 200, wTabCanvas5);
   TabCanvas5->AdoptCanvas(tc5);
   fCompositeFrame5->AddFrame(TabCanvas5, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,0,1,0));
   TabCanvas5->MoveResize(0,0.1*fsize,29*fsize,26.4*fsize);


   fTab775->SetTab(0);

   fTab775->Resize(fTab775->GetDefaultSize());
   fMainFrame5073->AddFrame(fTab775, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTab775->MoveResize(1,1,29*fsize,28*fsize);

   GCValues_t valEntry849;
   valEntry849.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry849.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry849.fBackground);
   valEntry849.fFillStyle = kFillSolid;
   valEntry849.fFont = ufont->GetFontHandle();
   valEntry849.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry849, kTRUE);
   TGTextEntry *fLoadEntry = new TGTextEntry(fGroupFrame743, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   fLoadEntry->SetMaxLength(4096);
   fLoadEntry->SetAlignment(kTextLeft);
   fLoadEntry->SetText("option");
   fLoadEntry->Resize(85,fLoadEntry->GetDefaultHeight());
   fGroupFrame743->AddFrame(fLoadEntry, new TGLayoutHints(kLHintsLeft | kLHintsExpandY,2,2,2,2));
   //commentfLoadEntry->MoveResize(88*size,40*size,85*size,23*size);

   /*TGTextButton *fAppendButton = new TGTextButton(fMainFrame5073,"Append",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fAppendButton->SetTextJustify(36);
   fAppendButton->SetMargins(0,0,0,0);
   fAppendButton->SetWrapLength(-1);
   fAppendButton->Resize(52,23);
   fAppendButton->ChangeBackground(ucolor);
   fMainFrame5073->AddFrame(fAppendButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fAppendButton->MoveResize(408,40,52,23);*/



   TGCheckButton *fLockCheck = new TGCheckButton(fMainFrame5073,"Lock");
   fLockCheck->SetTextJustify(36);
   fLockCheck->SetMargins(0,0,0,0);
   fLockCheck->SetWrapLength(-1);
   fMainFrame5073->AddFrame(fLockCheck, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLockCheck->MoveResize(30*fsize,0.3*fsize,2.5*fsize,0.9*fsize);


//-------------getcondition====================
//########################################################################

   fMainFrame2334->AddFrame(fMainFrame5073, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame5073->MoveResize(0,0,40*fsize,30*fsize);
   fMainFrame5073->Resize(fMainFrame5073->GetDefaultSize());

   fMainFrame1658->AddFrame(fMainFrame2334, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame2334->MoveResize(0,0,40*fsize,30*fsize);
   fMainFrame2334->Resize(fMainFrame2334->GetDefaultSize());

   fMainFrame1658->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame1658->MapSubwindows();

   fMainFrame1658->Resize(fMainFrame1658->GetDefaultSize());
   fMainFrame1658->MapWindow();
   //fMainFrame1658->Resize(665*size,454*size);
   fMainFrame1658->Resize(40*fsize,30*fsize);
   GetCondition *GC = new GetCondition(fRunButton, fPedButton, fStopButton, fLockCheck, fAnalyzeButton, fSaveButton, fLoadButton, fExitButton, fLoadEntry, fLabel1311, fLabel1313, fLabel1432, fNumberEntry747,tc1,tc2,tc3,tc4,tc5,fNumberEntry744,fStripEntry,StatusBar,ProgressBar,RadioButtonX,RadioButtonY,fMainFrame1658,TabCanvas1,TabCanvas2,TabCanvas3,TabCanvas4, TabCanvas5, fMainFrame2334, fMainFrame5073, fGroupFrame743, fTab775);
   fLoadButton->Connect("Clicked()","GetCondition",GC,"Load()");
   fExitButton->Connect("Clicked()","GetCondition",GC,"Exit()");
   fRunButton->Connect("Clicked()","GetCondition",GC,"Run()");
   fPedButton->Connect("Clicked()","GetCondition",GC,"Ped()");
   fStopButton->Connect("Clicked()","GetCondition",GC,"Stop()");
   fAnalyzeButton->Connect("Clicked()","GetCondition",GC,"Analyze()");
   RadioButtonX->Connect("Clicked()","GetCondition",GC,"RadioX()");
   RadioButtonY->Connect("Clicked()","GetCondition",GC,"RadioY()");
   fMainFrame1658->Connect("ProcessedEvent(Event_t*)","GetCondition",GC,"Rescale()");
   tc1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)","GetCondition",GC,"EventInfo(Int_t,Int_t,Int_t,TObject*)");
   tc2->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)","GetCondition",GC,"EventInfo(Int_t,Int_t,Int_t,TObject*)");
   tc3->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)","GetCondition",GC,"EventInfo(Int_t,Int_t,Int_t,TObject*)");
   tc4->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)","GetCondition",GC,"EventInfo(Int_t,Int_t,Int_t,TObject*)");
   tc5->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)","GetCondition",GC,"EventInfo(Int_t,Int_t,Int_t,TObject*)");
int height=fMainFrame1658->GetHeight();
int width=fMainFrame1658->GetWidth();
cout<<"@@"<<endl;
cout<<height<<width<<endl;
GC->Init();
//GC->Ped();
fNumberEntry747->SetNumber(10);
GC->Run();
}  
