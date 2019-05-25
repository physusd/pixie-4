/*
this macro reads in the mca binary file
save the results to root histograms and then
save all histograms to file
*/


void convert_mca_to_histograms(Char_t* mca_filename, Char_t* output_histo_filename)
{
//
   const int nchannels=4; // this must be user-defined
   const int NMCAC=32768;
//
   Char_t MCAValue_block[131072];
   unsigned long int MCAValue[32768];
//
//--> prepare output histograms
//
   TH1F* hmca[nchannels];
   for (int i=0; i<nchannels; i++) {
      hmca[i] = new TH1F(Form("hmca_%d",i),Form("hmca_%d",i),
                         NMCAC,0.0,float(NMCAC) );
   }
//
//--> read in binary file
//
   std::ifstream inputfile;
   inputfile.open(mca_filename, ios::in | ios::binary | ios::ate);
      short int a;
      short int b;
      short unsigned int returnint;
    Int_t temp_int;
    for (Int_t icha=0; icha<nchannels; icha++) {
//------> read in the block
      inputfile.seekg(icha*131072);
      inputfile.read(MCAValue_block,131072);
//------> process the block
      for (Int_t i=0; i<32768; i++) {
        Int_t j=i*4;
        a=MCAValue_block[j];
        b=MCAValue_block[j+1];
        returnint=0;
        for (Int_t ii=0; ii<8; ii++) {
          if (a & (1<<ii) )   { returnint |= (1<<ii); }
          if (b & (1<<ii) )   { returnint |= (1<<(ii+8));}
        }
        MCAValue[i] = returnint;
        Int_t k=i*4+2;
        a=MCAValue_block[k];
        b=MCAValue_block[k+1];
        returnint=0;
        for (Int_t ii=0; ii<8; ii++) {
          if (a & (1<<ii) )   { returnint |= (1<<ii); }
          if (b & (1<<ii) )   { returnint |= (1<<(ii+8));}
        }
        MCAValue[i] = MCAValue[i]+returnint*65536;
        //hmca[icha]->SetBinContent(i+1,returnint);
        hmca[icha]->SetBinContent(i+1,MCAValue[i]);
      }
//-----> done looping over all channels
      hmca[icha]->SetBinContent(1,0.0);
      hmca[icha]->SetBinContent(2,0.0);
      hmca[icha]->SetBinContent(3,0.0);
      cout<<" channel "<<icha<<" finished "<<endl;
    }
//
//--> save histograms to output file
//
    TFile* foutput = new TFile(output_histo_filename,"recreate");
    foutput->cd();
    for (Int_t i=0; i<nchannels; i++) {
      hmca[i]->Write();
    }
    foutput->Close();








}
