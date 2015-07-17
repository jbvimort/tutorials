#!/usr/bin/python
import sys
import SimpleITK as sitk
import numpy as np


if len(sys.argv) != 2:
  print "Usage: "+sys.argv[0]+" InputFileNAme"
  exit(-1)
input=sitk.ReadImage(sys.argv[1])

#definition of Standard Deviation
Sd=7.0

#METHOD 1
output1 = sitk.SmoothingRecursiveGaussian(input,Sd)
sitk.WriteImage(sitk.Cast(output1,input.GetPixelIDValue()), 'method1.jpg')


#METHOD 2
output2 = input

#gaussian matrix definition (matrice de type 2*a)
a=1
sumGauss=0
gauss = np.zeros((2*a+1,2*a+1))
for i in range(-a,a+1):
    for j in range (-a,a+1):
        gauss[i+a][j+a]=(1.0/(Sd*np.sqrt(2.0*np.pi)))*np.exp(-((i*i+j*j)/(2.0*Sd*Sd)))
        sumGauss=sumGauss+gauss[i+a][j+a]  
#gauss=[[1.0/16,1.0/8,1.0/16],[1.0/8,1.0/4,1.0/8],[1.0/16,1.0/8,1.0/16]]     
#print gauss   


# Application of the Gaussian Filter
for i in range(a,input.GetWidth()-a):
    for j in range(a,input.GetHeight()-a):
        val=[0,0,0]
        for k in range(-a,a+1):
            for l in range (-a,a+1):
                for c in range(0,3):
                    val[c]=val[c]+input.GetPixel(i+k,j+l)[c]*gauss[k][l] 
        pixelVal=(int(val[0]/sumGauss),int(val[1]/sumGauss),int(val[2]/sumGauss))
        output2.SetPixel(i,j,pixelVal)
sitk.WriteImage(sitk.Cast(output2,input.GetPixelIDValue()), 'method2.jpg')