void mca2root(char* input, char* output)
{
   // create output file to hold histograms
   TFile *fo = new TFile(output,"recreate");

   // define histogram for each channel
   const int ncha = 4; // PIXIE-4
   TH1I *h[ncha]= {0};
   const int nbit = (int) pow(2,15); // 15-bit
   for (int i=0; i<ncha; i++)
      h[i] = new TH1I(Form("h%d",i),
            Form("Channel %d;ADC counts;Entries;",i),nbit,0,nbit);

   ifstream fi(input); // open input file

   // read input file line by line
   const int nc=256; // read 256 characters in each line
   char line[nc];
   int icha=0, ibin=1; // counters
   bool isData=false; // flag
   while(fi.getline(line, nc)) { // get a line
      if (line[0]=='E') isData=false;// meet lines starting with 'END'
      if (isData) {
         h[icha]->SetBinContent(ibin, atoi(line));
         ibin++;
         if (ibin>nbit) { // finish one channel
            icha++;
            ibin=1;
         }
      }
      if (line[0]=='B') isData=true; // meet lines starting with 'BEGIN'
   }

   fi.close(); // close input file

   // save histograms to ouptut file
   fo->Write();
   fo->Close();
}
