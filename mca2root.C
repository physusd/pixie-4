void mca2root(char* input=NULL, char* output=NULL)
{
   // create output file
   TFile *fo = new TFile(output,"recreate");

   // define histogram for each channel
   const int ncha = 4; // PIXIE-4
   TH1I *h[ncha]= {0};
   const int nbit = (int) pow(2,15); // 15-bit
   for (int i=0; i<ncha; i++)
      h[i] = new TH1I(Form("h%d",i),
            Form("Channel %d;ADC counts;Entries;",i),nbit,0,nbit);

   // open input file
   ifstream fi;
   fi.open(input);

   // read input file line by line
   const int nc=256; // read 256 characters in each line
   char line[nc];
   int icha=0, ibin=1; // counters
   bool isData=false; // flag
   while(fi.getline(line, nc)) { // get a line
      if (line[0]=='B') { // meet the line started with 'BEGIN'
         isData=true; // turn on flag
         fi.getline(line, nc); // go to next line
      }
      if (line[0]=='E') isData=false;// meet line started with 'END'
      if (isData) {
         h[icha]->SetBinContent(ibin, atoi(line));
         ibin++;
         if (ibin>nbit) { // finished one channel
            icha++;
            ibin=1;
         }
      }
   }
   fi.close();

   // write histograms to root file
   fo->Write();
   fo->Close();
}
