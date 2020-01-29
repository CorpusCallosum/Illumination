#include "gui.h"

GUI::GUI()
{
    guiPanel.setup("GUI","gui_settings.xml", ofGetWindowWidth()-300, 10);

    //calibration
    guiPanel.add(xPos.setup("X", 0, 0, 1000));
    guiPanel.add(yPos.setup("Y", 0, 0, 1000));
    guiPanel.add(xScale.setup("X Scale", 1, 0, 1));
    guiPanel.add(yScale.setup("Y Scale", 1, 0, 1));

    //load settings
    guiPanel.loadFromFile("gui_settings.xml");
}

void GUI::draw(){
    guiPanel.draw();
}
