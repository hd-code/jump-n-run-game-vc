#include "tinyxml2.h"
#include <assert.h>
#include <iostream>
#include <string>

namespace testxml {

void main() {
    std::cout << "-- Test XML" << std::endl;

    std::string dataDir = "..\\data";
    std::string filepath = dataDir + "\\meta-entities.xml";

    tinyxml2::XMLDocument doc;
    auto err = doc.LoadFile(filepath.c_str());
    assert(err == tinyxml2::XML_SUCCESS);

    auto metaEntity = doc.FirstChildElement()->FirstChildElement();
    std::cout << "->Value: " << metaEntity->Value() << std::endl;

    const char *name;
    std::cout << "->QueryStringAttribute: "
              << metaEntity->QueryStringAttribute("name", &name) << std::endl;
    std::cout << "name: " << name << std::endl;

    std::cout << std::endl;
    auto size =
        metaEntity->FirstChildElement("data")->FirstChildElement("size");
    std::cout << "meta > data > size->Value: " << size->Value() << std::endl;
    std::cout << "meta > data > size->GetText : " << size->GetText()
              << std::endl;

    std::cout << std::endl;
    auto pos =
        metaEntity->FirstChildElement("data")->FirstChildElement("position");
    std::cout << "meta > data > position->Value: " << pos->Value() << std::endl;
    std::cout << "meta > data > position > x->FloatText : "
              << pos->FirstChildElement("x")->FloatText() << std::endl;

    std::cout << std::endl;
    auto none = metaEntity->FirstChildElement("noneexisting");
    std::cout << "meta > noneexisting: " << none << std::endl;
    std::cout << "meta > noneexisting == nullptr: " << (none == nullptr)
              << std::endl;

    std::cout << std::endl;
    auto next = metaEntity->NextSiblingElement();
    std::cout << "meta->NextSiblingElement: " << next << std::endl;
    std::cout << "next->QueryStringAttribute: "
              << next->QueryStringAttribute("name", &name) << std::endl;
    std::cout << "name: " << name << std::endl;

    std::cout << std::endl;
    int numOfEntities = 0;
    auto nextEntity = metaEntity;
    while (nextEntity != nullptr) {
        numOfEntities += 1;
        nextEntity = nextEntity->NextSiblingElement();
    }
    std::cout << "number of meta-entities: " << numOfEntities << std::endl;

    std::cout << "-- End Test XML" << std::endl << std::endl;
}

} // namespace testxml