# mca2root
convert PIXIE-4 mca spectrum from itx to root format

# Usage

```
$ ./mca2root.sh mca.itx
$ root mca.root
ROOT[] .ls // list histograms saved in mca.root
ROOT[] h2->Draw() // draw spectrum from channel 2
```
