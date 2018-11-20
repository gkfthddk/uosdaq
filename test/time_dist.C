{
  FILE *fp;
  char filename[256];
  int nrun;
  int sid;
	int cut;
  int nsample;
  int ch;
  int i;
  int frame;
  int adcX;
	int totADC = 0; 
  float px;

	gStyle->SetOptStat(0);
 
  printf("enter run number : ");
  scanf("%d", &nrun);

  printf("enter sid number : ");
  scanf("%d", &sid);

	printf("enter cut number : ");
	scanf("%d", &cut);

  //sprintf(filename, "data/uosdaq_%d_%d_%d.txt", nrun, sid, fn);
  sprintf(filename, "data/uosdaq_%d_%d.txt", nrun, sid);

  fp = fopen(filename, "rt");

  fscanf(fp, "%d", &nsample);

  TCanvas *c1 = new TCanvas("c1", "KIMS", 1000, 800);
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.15);
  TH2F *hoscd1 = new TH2F("hoscd1", "X distribution by frames", 200, 0, 200, nsample, 0, nsample);
	gStyle->SetPalette(kRainBow);

  hoscd1->Reset();

	/*
	for (i = 0; i < nsample; i++) {
    // read frame number
    fscanf(fp, "%d", &frame);
   
    // add ADC to get sum for X channels
    for (ch = 0; ch < 200; ch++) {
      fscanf(fp, "%d", &adcX);
			px = ch;
			if (ch>=0 && ch<50) continue;
			else if (ch>=50 && ch<100){
				if (ch==53 || ch==90 || ch==93) continue;
				else{
					// Noise cut
					if (adcX > cut){
						hoscd1->Fill(px, i, adcX);
					}
					else continue;
				}
			}
			else if (ch>=100 && ch<150) continue;
			else if (ch>=150){
				if (ch==176 || ch==194 || ch==195) continue;
				else{
					// Noise cut
					if (adcX > cut){
						hoscd1->Fill(px, i, adcX);
					}
					else continue;
				}
			}
		}				
 
    printf("%d / %d filled, frame # = %d\n", i + 1, nsample, frame);
	}
	*/

	for (i = 0; i < nsample; i++) {
    // read frame number
    fscanf(fp, "%d", &frame);
   
    // add ADC to get sum for X channels
    for (ch = 0; ch < 200; ch++) {
      fscanf(fp, "%d", &adcX);
			px = ch;
			// Noise cut
			if (adcX > cut){	
				hoscd1->Fill(px, i, adcX);
				totADC += adcX;
			}
			else continue;
		}
 
    printf("%d / %d filled, frame # = %d\n", i + 1, nsample, frame);
	}

  fclose(fp);

	printf("Total ADC = %d\n",totADC);

	hoscd1->GetXaxis()->SetTitle("Strips");
	hoscd1->GetYaxis()->SetTitle("Frames (34880 frames/s)");
	hoscd1->GetYaxis()->SetTitleOffset(2);
	hoscd1->GetZaxis()->SetRangeUser(0, 4096);
  hoscd1->Draw("colz");

  c1->Modified();
  c1->Update();
}

