#include <iostream>
#include <string>

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkNeighborhoodIterator.h"
#include "itkImageRegionIterator.h"
#include "itkNeighborhoodAlgorithm.h"
#include "erodeCLP.h"


int main(int argc, char **argv )
{

    PARSE_ARGS;

    ///reading of the input file
    /// --------------------------------
    
    if( radius < 1 )
    {
        std::cout << "Radius value must be non-zero positive integer." << std::endl ;
        return EXIT_FAILURE ;
    }

    //definition of the data type
    typedef unsigned char PixelType;
    const unsigned int Dimension = 2;
    typedef itk::Image< PixelType, Dimension > ImageType;
    typedef itk::ImageFileReader< ImageType > ReaderType;

    //definition of the reader pointer
    ReaderType::Pointer reader = ReaderType::New();

    //reading of the image
    reader->SetFileName(inputFileName);
    reader->Update();

    ///definition of the writer
    ///--------------------------------

    typedef  itk::ImageFileWriter< ImageType  > WriterType;
    WriterType::Pointer writer = WriterType::New();

    ///------------------------------------------------///
    ///                 erode filter                   ///
    ///------------------------------------------------///

    //definition of the kernel's size
    int R=radius;

    //definition of the filters
    typedef itk::NeighborhoodIterator< ImageType > NeighborhoodIteratorType;
    typedef itk::ImageRegionIterator< ImageType> IteratorType;

    //creation of the input image iterator (neighborhood iterator)
    NeighborhoodIteratorType::RadiusType rad;
    rad.Fill(R);
    NeighborhoodIteratorType it( rad, reader->GetOutput(),reader->GetOutput()->GetRequestedRegion() );

    //creation of the output iterator
    ImageType::Pointer output1 = ImageType::New();
    output1->SetRegions(reader->GetOutput()->GetRequestedRegion());
    output1->Allocate();
    IteratorType out1(output1, reader->GetOutput()->GetRequestedRegion());

    //creation of a vector of offset (those offset will constitute the kernel)
    std::vector<NeighborhoodIteratorType::OffsetType> usefullOffset;
    usefullOffset.resize(4*R+1);

    //filling of the offset vector (here the kernel will be a cross)
    NeighborhoodIteratorType::OffsetType temp = {{0,0}};
    usefullOffset.at(0)=temp;
    for(int i=1 , j=1 ; i<R ; i++ , j=j+4)
    {
        NeighborhoodIteratorType::OffsetType temp1={{-i,0}};
        usefullOffset[j]=temp1;
        NeighborhoodIteratorType::OffsetType temp2={{0,-i}};
        usefullOffset[j+1]=temp2;
        NeighborhoodIteratorType::OffsetType temp3={{i,0}};
        usefullOffset[j+2]=temp3;
        NeighborhoodIteratorType::OffsetType temp4={{0,i}};
        usefullOffset[j+3]=temp4;
    }

    //erosion main algorythms
    for (it.GoToBegin(), out1.GoToBegin(); !it.IsAtEnd(); ++it, ++out1)
    {
        for(int i=0;i<4*(R-1)+1;i++)
        {

            if(it.GetPixel(usefullOffset[i])!=0)
            {
                out1.Set(255);
            }
        }
    }

    ///writing of the output file
    /// ---------------------------------
    writer->SetFileName(outputFileName1);
    writer->SetInput(output1);
    writer->Update();

    return 0;
}
