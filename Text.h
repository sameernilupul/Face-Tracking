//
//  Text.h
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Final_This_Willbe_Text_h
#define Final_This_Willbe_Text_h
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

class Text
{
private:
    CvFont font; 
    
    double hScale;
    double vScale;
    int    lineWidth;
    
public:
    Text();
    void printText(IplImage* image, char* text,CvPoint point);
};

#endif
