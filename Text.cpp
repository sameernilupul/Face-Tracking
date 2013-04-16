//
//  Text.cpp
//  Final_This_Willbe
//
//  Created by Sameera Nilupul Wijayarathna on 2/23/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Text.h"


Text::Text(){
    hScale=1.0;
    vScale=1.0;
    lineWidth=3;
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);
}

void Text::printText(IplImage* image,char* text,CvPoint point){
    cvPutText (image, text, cvPoint(point.x -30,point.y-30), &font, cvScalar(255,255,255));
}
