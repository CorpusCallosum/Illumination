#include "display.h"

DisplaySystem::DisplaySystem()
{

}

void DisplaySystem::draw(){

}

void Display::updateData(ofxXmlSettings d){
    //parse data and generate vector or Word objects with text and rect data for each word
    string dataAsString;
    dataXml.copyXmlToString(dataAsString);
    //cout<<dataAsString<<endl;
    if(!dataAsString.empty())
    {
        //cout<<"data exists"<<endl;
        //draw boxes around words
        dataXml.pushTag("html");
        dataXml.pushTag("body");

        //PAGEs
        dataXml.pushTag("div");

        dataXml.popTag();
        dataXml.popTag();
        dataXml.popTag();


    }
}
