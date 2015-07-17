#!/usr/bin/python
import sys
import SimpleITK as sitk
import numpy as np


if len(sys.argv) != 2:
  print "Usage: "+sys.argv[0]+" InputFileNAme"
  exit(-1)
input=sitk.ReadImage(sys.argv[1])

a=10
b=10

### METHOD 1
output1 = sitk.Shrink(input,[a,b])
sitk.WriteImage(sitk.Cast(output1,input.GetPixelID()), 'method1.jpg')

### METHOD 2 : selection of pixels -> not working
print str(input.GetPixelID())
output2 = sitk.Image(int(input.GetWidth()/a),int(input.GetHeight()/b),input.GetPixelID())
print input.GetPixelIDTypeAsString()


# Application of Shrink Filter
k=0
l=0
for i in range(1,input.GetWidth()-1,a):
    for j in range(1,input.GetHeight()-1,b):
        print str(input.GetPixel(i,j))
        print str(i)
        print str(j)
        #output2.SetPixelAsVectorUInt8(k,l,input.GetPixel(i,j))
        #output2.SetPixel(k,l,input.GetPixel(i,j))
        output2[k,l]=input.GetPixel(i,j)
        l=l+1
    k=k+1
    l=0
        
sitk.WriteImage(sitk.Cast(output2,input.GetPixelIDValue()), 'method2.jpg')

#### METHOD 3 : mean of square -> not working
output3 = sitk.Image(int(input.GetWidth()/a),int(input.GetHeight()/b),input.GetPixelID())

# Application of Shrink Filter
k=0
l=0
SumShrink=0
for k in range(a,output3.GetWidth()-a):
    for l in range(b,output3.GetHeight()-b):
        val=[0,0,0]
        for i in range(k-a,k+a):
            for j in range(l-b,l+b):
                for c in range(0,3):
                    val[c]=val[c]+input.GetPixel(i,j)[c] 
        SumShrink=(int(val[0]/(a*b)),int(val[1]/(a*b)),int(val[2]/(a*b)))
                 
        output3.SetPixel(k,l,SumShrink)

        
sitk.WriteImage(sitk.Cast(output3,input.GetPixelIDValue()), 'method3.jpg')
