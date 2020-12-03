#include "tinyxml2.h"
#include "tinyxmlTest.h"

int runTestCase_1()
{
    using namespace tinyxml2;

    static const char* xml =
        "<?xml version=\"1.0\"?>"
        "<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
        "<PLAY>"
        "<TITLE>A Midsummer Night's Dream</TITLE>"
        "</PLAY>";

    XMLDocument doc;
    doc.Parse(xml);

    XMLElement* titleElement = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE");
    const char* title = titleElement->GetText();
    printf("Name of play (1): %s\n", title);

    XMLText* textNode = titleElement->FirstChild()->ToText();
    title = textNode->Value();
    printf("Name of play (2): %s\n", title);

    return doc.ErrorID();
}