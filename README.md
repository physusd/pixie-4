# Pixie-4

Scripts to convert outputs from Pixie-4 Igor GUI to ROOT format

## Download
```
$ git clone https://github.com/physusd/pixie-4.git
```

## Convert Igor text file to ROOT format

1. Create Igor text file from the PIXIE MCA Spectrum GUI:
![How to create Igor text file from PIXIE MCA Spectrum GUI](https://dl.dropboxusercontent.com/u/19851056/0/PIXIE-MCA-Spectrum-save-as-Igor-text.png)
2. scp the Igor text file, say spectra.itx, from the Windows PC to a Linux machine with ROOT installed.
3. run the script to convert the Igore text file to ROOT format:
```
$ ./itx.sh spectra.itx # convert spectra.itx to spectra.root
$ root spectra.root # open spectra.root
ROOT[] .ls // list histograms saved in mca.root
ROOT[] h2->Draw() // draw spectrum from channel 2
```
