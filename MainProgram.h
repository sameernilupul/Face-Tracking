//
//  MainProgram.h
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Final_This_Willbe_MainProgram_h
#define Final_This_Willbe_MainProgram_h

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "FaceDetection.h"
#include "Text.h"
#include "TemplateMatch.h"

class Main{
    
private:
    CvCapture* capture;
    IplImage* frame;
    IplImage* resized;
    IplImage* imgTemplate;
    
    CvRect box;
    CvPoint center;
    char text[255];
    
    FaceDetector detector;
    Text textWriter;
    bool initialized;
    double prob;
    double averageProb[5];
    TemplateMatcher tempMatcher;
    int count;
    
public:
    Main();
    ~Main();
    void mainLoop();
};

#endif
