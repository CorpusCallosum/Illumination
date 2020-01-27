#include "data.h"

Data::Data()
{

}

void Data::load(){
    //load OCR data
    dataXml.load("output.hocr");

}
