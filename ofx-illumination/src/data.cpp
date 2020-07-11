#include "data.h"

Data::Data()
{
    //load the settings XML data file
    settingsXML.load("settings.xml");
}

void Data::loadOutputOCR(){
    cout<<"data.load"<<endl;
    text = "";

    //load OCR data
    hocr.load("output.hocr");

    //parse data and generate vector of Word objects with text and rect data for each word
    string dataAsString;
    hocr.copyXmlToString(dataAsString);
    //cout<<dataAsString<<endl;
    if(!dataAsString.empty())
    {
        //clear out the words vector
        wordsVector.clear();
        cout<<"data exists"<<endl;
        //draw boxes around words
        hocr.pushTag("html");
        cout<<"pushtag html"<<endl;
        hocr.pushTag("body");
        cout<<"pushtag body"<<endl;

        //PAGEs
        for(int pg=0;pg<hocr.getNumTags("div");pg++){
        //    cout<<"page "<<pg;
            hocr.pushTag("div", pg);
            //careas
            for(int c=0;c<hocr.getNumTags("div");c++){
          //       cout<<", carea "<<c;
                hocr.pushTag("div",c);
                //paragraphs
                for(int p=0;p<hocr.getNumTags("p");p++){
            //        cout<<", paragraph "<<p;
                    hocr.pushTag("p",p);
                    //lines
                    for(int l=0;l<hocr.getNumTags("span");l++){
              //          cout<<", line "<<l;
                        hocr.pushTag("span",l);
                        //words
                        for(int w=0;w<hocr.getNumTags("span");w++){
                          // cout<<"word "<<w<<endl;
                           string wordText = hocr.getValue("span","",w);

                           //strip string whitespace
                           ofStringReplace(wordText," ","");

                           //ignore words that are blank
                           if(wordText !=""){
                               string boxData = hocr.getAttribute("span","title","",w);
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
                        hocr.popTag();
                    }
                    hocr.popTag();
                }
                hocr.popTag();
            }
            hocr.popTag();
        }
        hocr.popTag();
        hocr.popTag();
        hocr.popTag();
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

vector<int> Data::loadPoem(){
    //load poem.txt file
    vector < string > p = ofSplitString(ofBufferFromFile("poem.txt").getText(), " ");

    //convert string vector to int vector
    for (int i=0; i< p.size(); i++)
    {
     int num = atoi(p.at(i).c_str());
     poemDataVector.push_back(num);
    }

    return poemDataVector;
}

