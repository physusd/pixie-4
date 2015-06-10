Scripts to convert outputs from PIXIE Igor GUI to ROOT format

# Convert Igor text file to ROOT format

```
$ ./itx.sh spectra.itx # convert spectra.itx to spectra.root
$ root spectra.root # open spectra.root
ROOT[] .ls // list histograms saved in mca.root
ROOT[] h2->Draw() // draw spectrum from channel 2
```
