//
//  CropImage.cpp
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

void cropImage(IplImage* image,IplImage ** cropped,CvRect box);

void cropImage(IplImage* image,IplImage ** cropped,CvRect box){
    
    
    cvReleaseImage(cropped);
    *cropped = cvCreateImage( cvSize(box.width,box.height), image->depth, image->nChannels);
    
    cvSetImageROI(image, box);
    cvCopy( image, *cropped );
    cvResetImageROI( image );
    //cvSaveImage("/Users/sameernilupul/Desktop/CROPPED.jpg", *cropped);
}