//
//  wrapper.cpp
//  AVCam
//
//  Created by Youssef Victor on 11/23/19.
//  Copyright © 2019 Apple. All rights reserved.
//

#include "wrapper.hpp"


extern "C" int getRAWHeight() {
    // Let us create an image processor
    LibRaw iProcessor;
    
    // TODO: Change this to the correct path:
    const char* basic = "sample.DNG";
    
    // Open the file and read the metadata
    int32_t error = iProcessor.open_file(basic);
    if (error != LIBRAW_SUCCESS) {
        fprintf(stderr,"Cannot open %s: %s\n",basic,libraw_strerror(error));
    };
    
//    // Try reading using file_datastream too, maybe this works?
//    LibRaw_file_datastream* filestr = new LibRaw_file_datastream(basic);
//    error = iProcessor.open_datastream(filestr);
//    if (error != LIBRAW_SUCCESS) {
//        fprintf(stderr,"Cannot open AGAIN %s: %s\n",basic,libraw_strerror(error));
//    };
    

    // The metadata are accessible through data fields of the class
    printf("Image size: %d x %d\n",iProcessor.imgdata.sizes.width,iProcessor.imgdata.sizes.height);
    
    
    // MARK: GET IMAGE WIDTH
    int height = iProcessor.imgdata.sizes.iheight;
    
    // Finally, let us free the image processor for work with the next image
    iProcessor.recycle();
    return height;
}
