# Pixie-4

Scripts to convert outputs from [Pixie-4][] [GUI] to [ROOT] format

## Download
```
$ git clone https://github.com/physusd/pixie-4.git
```

## Convert Igor text file to ROOT format

1. Create [Igor] text file from the [Pixie-4] MCA Spectrum [GUI]:
![How to create Igor text file from Piexie-4 MCA Spectrum Viewer](https://dl.dropboxusercontent.com/u/19851056/0/Pixie-4-MCA-Spectrum-save-as-Igor-text.png)
2. scp the [Igor] text file, say spectra.itx, from the Windows PC to a Linux machine with ROOT installed.
3. run the script to convert the [Igor] text file to [ROOT] format:
```
$ ./itx.sh spectra.itx # convert spectra.itx to spectra.root
$ root spectra.root # open spectra.root
ROOT[] .ls // list histograms saved in mca.root
ROOT[] h2->Draw() // draw spectrum from channel 2
```

[Pixie-4]:http://www.xia.com/DGF_Pixie-4.html
[GUI]:http://www.xia.com/DGF_Pixie-4_Software.html
[ROOT]:http://root.cern.ch
[Igor]:https://www.wavemetrics.com/index.html
