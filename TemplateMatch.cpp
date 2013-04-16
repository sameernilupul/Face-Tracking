//
//  TemplateMatch.cpp
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "FaceDetection.h"
#include "CropImage.h"
#include "TemplateMatch.h"


TemplateMatcher::TemplateMatcher(){
    imgTemplate = cvCreateImage(cvSize(100, 100), 8, 1);
}

void TemplateMatcher::Initializer(IplImage* image, IplImage** tempImage){
    min_val=0;
    max_val=0;
    
    
    cvReleaseImage(&imgTemplate);
    imgTemplate = cvCloneImage(*tempImage);
    
    imgResult = cvCreateImage(cvSize(image->width - imgTemplate->width+1,image->height - imgTemplate->height+1 ), IPL_DEPTH_32F, 1);
}


double TemplateMatcher::matchTemplate(IplImage* image, CvPoint* center){
    cvZero(imgResult);
    cvMatchTemplate(image, imgTemplate, imgResult, CV_TM_CCORR_NORMED);
    cvMinMaxLoc(imgResult,&min_val,&max_val,&min,&max);
    
    cropImage(image, &imgTemplate, cvRect(max.x,max.y,imgTemplate->width,imgTemplate->height ));
    
    center->x = max.x;
    center->y = max.y;
    
    return max_val;
}





