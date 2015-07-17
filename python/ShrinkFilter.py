#!/usr/bin/python
import sys
import SimpleITK as sitk


if len(sys.argv) != 2:
  print "Usage: "+sys.argv[0]+" InputFileNAme"
  exit(-1)
input=sitk.ReadImage(sys.argv[1])

a=10
b=10

### METHOD 1
print "method 1"
output1 = sitk.Shrink(input,[a,b])
sitk.WriteImage(sitk.Cast(output1,input.GetPixelID()), 'method1.jpg')

### METHOD 2 : selection of pixels
print "method 2"
output2 = sitk.Image([int(input.GetWidth()/a),int(input.GetHeight()/b)],input.GetPixelID(),3)

# Application of Shrink Filter
k=0
l=0
for i in range(1,input.GetWidth()-1,a):
    for j in range(1,input.GetHeight()-1,b):
        output2[k,l]=input.GetPixel(i,j)
        l=l+1
    k=k+1
    l=0
        
sitk.WriteImage(sitk.Cast(output2,input.GetPixelIDValue()), 'method2.jpg')

#### METHOD 3 : mean of square
print "method 3"
output3 = sitk.Image([int(input.GetWidth()/a),int(input.GetHeight()/b)],input.GetPixelID(),3)

#Application of Shrink Filter
SumShrink=0
for k in range(1,output3.GetWidth()):
    for l in range(1,output3.GetHeight()):
        val=[0,0,0]
        for i in range(1,a):
            for j in range(1,b):
                for c in range(0,3):
                    val[c]=val[c]+input.GetPixel(i+a*(k-1),j+b*(l-1))[c]
        SumShrink=(int(val[0]/(a*b)),int(val[1]/(a*b)),int(val[2]/(a*b)))
        output3.SetPixel(k,l,SumShrink)


sitk.WriteImage(sitk.Cast(output3,input.GetPixelIDValue()), 'method3.jpg')




























