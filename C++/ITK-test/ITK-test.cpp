#include <iostream>
#include <string>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"
#include "itkSmoothingRecursiveGaussianImageFilter.h"
#include "itkRGBPixel.h"
#include <itkBinaryThresholdImageFilter.h>

int main(int argc, char **argv )
{
    ///check of the number of informations given
    /// ---------------------------------------------------------

    if (argc != 2)
    {
        std::cout<< "Usage: "<<argv[0]<<" InputFileNAme";
        exit(-1);
    }

    ///reading of the input file
    /// --------------------------------

    //definition of the data type
   // typedef unsigned char PixelType;
    typedef itk::RGBPixel< unsigned char > RGBPixelType;
    const unsigned int Dimension = 2;
    typedef itk::Image< RGBPixelType, Dimension > RGBImageType;
    typedef itk::ImageFileReader< RGBImageType > RGBReaderType;

    //definition of the reader pointer
    RGBReaderType::Pointer RGBreader = RGBReaderType::New();

    //reading of the image
    const char * filename = argv[1];
    RGBreader->SetFileName( filename );
    RGBreader->Update();

    typedef unsigned char PixelType;
    typedef itk::Image< PixelType, Dimension > ImageType;
    typedef itk::ImageFileReader< ImageType > ReaderType;

    //definition of the reader pointer
    ReaderType::Pointer reader = ReaderType::New();

    //reading of the image
    reader->SetFileName( filename );
    reader->Update();

    ///definition of the writer
    ///--------------------------------

    typedef  itk::ImageFileWriter< RGBImageType  > RGBWriterType;
    RGBWriterType::Pointer RGBwriter = RGBWriterType::New();

    typedef  itk::ImageFileWriter< ImageType  > WriterType;
    WriterType::Pointer writer = WriterType::New();

    ///aplication of some filters
    /// ---------------------------------

    //Gaussian Filter
    typedef itk::SmoothingRecursiveGaussianImageFilter<RGBImageType, RGBImageType> GaussianFilterType;

    GaussianFilterType::Pointer gaussianFilter = GaussianFilterType::New();

    gaussianFilter->SetInput(RGBreader->GetOutput());
    gaussianFilter->SetSigma(8);

    RGBImageType::Pointer output1=RGBImageType::New();

    output1=gaussianFilter->GetOutput();

    //
    typedef itk::BinaryThresholdImageFilter<ImageType,ImageType> BinaryFilterType;

    BinaryFilterType::Pointer binaryFilter = BinaryFilterType::New();

    binaryFilter->SetInput(reader->GetOutput());
    binaryFilter->SetInsideValue(100);
    binaryFilter->SetOutsideValue(200);
    binaryFilter->SetLowerThreshold(100);
    //binaryFilter->SetLowerThresholdInput(100);
    binaryFilter->SetUpperThreshold(150);
    //binaryFilter->SetUpperThresholdInput(155);


    ImageType::Pointer output2=ImageType::New();

    output2=binaryFilter->GetOutput();





    ///writing of the output files
    /// ----------------------------------

    RGBwriter->SetFileName("gaussian.jpg");
    RGBwriter->SetInput(output1);
    RGBwriter->Update();

    writer->SetFileName("binary.jpg");
    writer->SetInput(output2);
    writer->Update();
}
