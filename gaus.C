{
  float sign(float x){return(x>0.)-(x<0.);}
  clock_t t1,t2;
  t1=clock();
  FILE *fp;
  char filename[256];
  char nrun[256];
  int sch;
  int nsample;
  int ch;
  int i;
  int frame;
  int adcX;
  int adcY;
  int ax,ay;
  int xchek=0;
  int ychek=0;
  int next=0;
  float vx[100],vy[100];
  float **pp=new float*[100];
  for (int a=0;a<100;++a){
    pp[a]=new float[100];
    for (int b=0;b<100;++b){
      pp[a][b]=0.;
    }
  }
  short px[100];
  short py[100];
  printf("enter file name : ");
  scanf("%s",nrun);

  auto inf=new TFile(strcat(nrun,".root"),"read");
  auto intree=(TTree*) inf->Get("data");
  intree->SetBranchAddress("px",&px);
  intree->SetBranchAddress("py",&py);
  
  TCanvas *c1 = new TCanvas("c1", "KIMS", 500, 500);
  c1->Divide(2,1);
  res=10;
  TH1F *hos1 = new TH1F("hos1", "hist", 100, 0, 100);
  TH1F *hos2 = new TH1F("hos2", "hist", 100, 0, 100);
  TH2F *hos3 = new TH2F("hos3", nrun, res*100, 0, 100,res*100,0,100);

  hos1->Reset();
  hos2->Reset();
  hos3->Reset();
  int maxx,maxy;
  int cnt=0;
  int skpx,skpy;
  int idx1,idx2,idy1,idy2;
  float bx,by,bb,bv;
  int NN=intree->GetEntries();
  for (i = 0; i < NN/10; i++) {
    intree->GetEntry(i);
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
        if(px[j]>40){
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
        if(py[j]>60){
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
    for(int j=0;j<2;j++){
    if(idx1!=-1&&idy1!=-1){
      hos1->Fit("gaus","Q","",idx1-3,idx1+3);
      hos2->Fit("gaus","Q","",idy1-3,idy1+3);
      bx=hos1->GetFunction("gaus")->GetParameter(1);
      by=hos2->GetFunction("gaus")->GetParameter(1);
      //bb=hos3->GetBinContent(bx,by);
      //bv=hos1->GetFunction("gaus")->GetMaximum();
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
              hos3->Fill(bx+l,by+m,1.*maxy/maxx*hos1->GetFunction("gaus")->Eval(bx+l));
            }
            else if(l==0){
              hos3->Fill(bx+l,by+m,1.*hos2->GetFunction("gaus")->Eval(by+m));
            }
            else{
              bv=sqrt(m*m+l*l);
              hos3->Fill(bx+l,by+m,(1.*maxy/maxx*hos1->GetFunction("gaus")->Eval(bx+bv)+hos2->GetFunction("gaus")->Eval(by+bv))/2.);
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
 c1->cd(1);
 hos3->SetStats(0);
 hos3->Draw("colz");
 c1->cd(2);
c1->Update();
t2=clock();
float diff((float)t2-(float)t1);
cout<<cnt<<endl;
cout<<diff/CLOCKS_PER_SEC<<endl;
}
    
