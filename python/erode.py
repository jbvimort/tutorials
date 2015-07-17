#!/usr/bin/python
import sys
import SimpleITK as sitk
import numpy as np

if len(sys.argv) != 2:
  print "Usage: "+sys.argv[0]+" InputFileNAme"
  exit(-1)
input=sitk.ReadImage(sys.argv[1])

# Definition of the kernel radius
r=3

#Binari conversion
bin=sitk.Image([int(input.GetWidth()),int(input.GetHeight())],1,1)
for i in range(1,input.GetWidth()):
    for j in range(1,input.GetHeight()):
        if (input.GetPixel(i,j)[1]>122):
            bin.SetPixel(i,j,255)
        else:
            bin.SetPixel(i,j,0)
            
sitk.WriteImage(sitk.Cast(bin,input.GetPixelIDValue()), 'binary.bmp')

# METHOD 1 

erode=sitk.BinaryErodeImageFilter()
erode.SetBackgroundValue(255)
erode.SetForegroundValue(0)
erode.SetBoundaryToForeground(True)
erode.SetKernelRadius(r)
erode.SetKernelType(3)

output1=erode.Execute(bin)
sitk.WriteImage(sitk.Cast(output1,input.GetPixelIDValue()), 'method1.bmp')

# METHOD 2 (For a cross of 5 pixels)

output2=sitk.Image([int(bin.GetWidth()),int(bin.GetHeight())],1,1)
for i in range(1,bin.GetWidth()):
    for j in range(1,bin.GetHeight()):
        output2.SetPixel(i,j,0)

for i in range(r,bin.GetWidth()-r):
    for j in range(r,bin.GetHeight()-r):
        if(bin.GetPixel(i,j)==255):
            for k in range(-r,r):
                output2.SetPixel(i+k,j,255)
                output2.SetPixel(i,j+k,255) 

sitk.WriteImage(sitk.Cast(output2,input.GetPixelIDValue()), 'method2.bmp')               
                

