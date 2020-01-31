#include "data.h"

Data::Data()
{

}

void Data::load(){
    cout<<"data.load"<<endl;
    text = "";
    //load OCR data
    dataXml.load("output.hocr");

    //parse data and generate vector of Word objects with text and rect data for each word
    string dataAsString;
    dataXml.copyXmlToString(dataAsString);
    //cout<<dataAsString<<endl;
    if(!dataAsString.empty())
    {
        //clear out the words vector
        wordsVector.clear();
        cout<<"data exists"<<endl;
        //draw boxes around words
        dataXml.pushTag("html");
        cout<<"pushtag html"<<endl;
        dataXml.pushTag("body");
        cout<<"pushtag body"<<endl;

        //PAGEs
        for(int pg=0;pg<dataXml.getNumTags("div");pg++){
        //    cout<<"page "<<pg;
            dataXml.pushTag("div", pg);
            //careas
            for(int c=0;c<dataXml.getNumTags("div");c++){
          //       cout<<", carea "<<c;
                dataXml.pushTag("div",c);
                //paragraphs
                for(int p=0;p<dataXml.getNumTags("p");p++){
            //        cout<<", paragraph "<<p;
                    dataXml.pushTag("p",p);
                    //lines
                    for(int l=0;l<dataXml.getNumTags("span");l++){
              //          cout<<", line "<<l;
                        dataXml.pushTag("span",l);
                        //words
                        for(int w=0;w<dataXml.getNumTags("span");w++){
                          // cout<<"word "<<w<<endl;
                           string wordText = dataXml.getValue("span","",w);

                           //strip string whitespace
                           ofStringReplace(wordText," ","");

                           //ignore words that are blank
                           if(wordText !=""){
                               string boxData = dataXml.getAttribute("span","title","",w);
                               cout<<" boxData: "<<boxData;
                               ofRectangle rect = parseRect(boxData);

                               //also ignore anything that is the whole screen size...
                               if(rect.width<1920){
                                   addWord(wordText, rect);
                                   //wordsVector.push_back(Word(wordText, rect));
                                   cout<<wordText<<" ";
                               }
                           }
                        }
                        dataXml.popTag();
                    }
                    dataXml.popTag();
                }
                dataXml.popTag();
            }
            dataXml.popTag();
        }
        dataXml.popTag();
        dataXml.popTag();
        dataXml.popTag();
    }

    //cleanup - remove weird characters
    removeChar("(");
    removeChar("\"");
    removeChar("'");
    removeChar("-");
    removeChar(";");
    removeChar("}");

    cout<<endl<<"parsing complete"<<endl;
}

void Data::removeChar(string c){
    ofStringReplace(text,c,"");
}

void Data::addWord(string wordText, ofRectangle rect){
    wordsVector.push_back(Word(wordText, rect));
    text += " "+wordText;
   // cout<<text<<endl;
}

ofRectangle Data::parseRect(string d){
    ofRectangle rect;
    vector<string> splitString = ofSplitString( d, ";");
    splitString = ofSplitString( d, " ");
    rect.x = ofToInt(splitString[1]);
    rect.y = ofToInt(splitString[2]);
    rect.width = ofToInt(splitString[3]) - ofToInt(splitString[1]);
    rect.height = ofToInt(splitString[4]) - ofToInt(splitString[2]);
    return rect;
}
