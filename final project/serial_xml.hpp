#ifndef SERIAL_XML_HPP
#define SERIAL_XML_HPP

#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace tinyxml2;

//functions used in tinyxml2:XMLDocument
/*
1.Clear():
Purpose: Clears the content of the entire XML document, releasing all memory resources.

2.NewDeclaration():
Purpose: Creates a new XML declaration, typically used to specify the XML version and character encoding.

3.NewElement():
Purpose: Creates a new XML element node that can be added to the XML document.

4.InsertFirstChild():
Purpose: Inserts an XML element node as the first child node of the current node.

5.InsertEndChild():
Purpose: Inserts an XML element node as the last child node of the current node.

6.SaveFile():
Purpose: Saves the XML document to a file.

7.LoadFile():
Purpose: Loads the XML document from a file.

8.FirstChildElement():
Purpose: Retrieves the first child element node of the current node, commonly used for traversing the XML document structure.
*/

//serial_xml for arithmetic types in xml format
namespace xml_serial{
    template <class T>
    void serialize_xml(const T &obj, const string &filename)
    {   
        //create a new XML document
        XMLDocument doc;
        //create a new XML element node and name it as the type of the object
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement(typeid(obj).name());
        XMLElement *value = doc.NewElement("value");
        //set the value of the XML element node to the object by converting it to a string
        value->SetAttribute(typeid(obj).name(),to_string(obj).c_str());
        //insert the XML element node as the last child node of the XML element node
        type->InsertEndChild(value);
        root->InsertEndChild(type);
        //insert the XML element node as the first child node of the XML document
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
    }

    template <class T>
    void deserialize_xml(T &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        //load the XML document from a file
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        //retrieve the first child element node of the first chile element node of the XML document
        XMLElement *type = root->FirstChildElement(typeid(obj).name());
        //retrieve the first child element node of this type element node
        XMLElement *value = type->FirstChildElement("value");
        //set the object to the value of the XML element node by converting it to the type of the object
        const char* valueStr = value->Attribute(typeid(obj).name());
        //convert the value of the XML element node to the type of the object
        istringstream iss(valueStr);
        iss >> obj;
    }




    //serial_xml for string type in xml format
    void serialize_xml(const string &obj, const string &filename)
    {   
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as the type of the object
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("string");
        XMLElement *value = doc.NewElement("value");
        //set the value of the XML element node to the object
        value->SetAttribute("string",obj.c_str());
        //insert the XML element node as the last child node of the XML element node
        type->InsertEndChild(value);    
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
    }
    void deserialize_xml(string &obj, const string &filename)
    {   
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("string");
        XMLElement *value = type->FirstChildElement("value");
        //set the object to the value of the XML element node
        const char* valueStr = value->Attribute("string");
        obj = valueStr;
    }



    //serial_xml for pair in xml format
    template <class T1, class T2>
    void serialize_xml(const pair<T1, T2> &obj, const string &filename)
    {   
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create 2 new XML element nodes and name them as first and second
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_pair");
        //set the value of the XML element nodes to the object
        XMLElement *first = doc.NewElement("first");
        first->SetAttribute("val",to_string(obj.first).c_str());
        XMLElement *second = doc.NewElement("second");
        second->SetAttribute("val",to_string(obj.second).c_str());
        //insert the XML element nodes as the last child nodes of the XML element node
        type->InsertEndChild(first);
        type->InsertEndChild(second);
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str()); 
    }
    template <class T1, class T2>
    void deserialize_xml(pair<T1, T2> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_pair");
        //retrieve the first child element node of the type element node
        XMLElement *first = type->FirstChildElement("first");
        //set the first element of the object to the value of the XML element node
        const char* firstStr = first->Attribute("val");
        istringstream iss1(firstStr);
        iss1 >> obj.first;
        //retrieve the second child element node of the type element node
        XMLElement *second = type->FirstChildElement("second");
        //set the second element of the object to the value of the XML element node
        const char* secondStr = second->Attribute("val");
        istringstream iss2(secondStr);
        iss2 >> obj.second;
    }

    template <class T>
    void serialize_xml(const pair<string,T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create 2 new XML element nodes and name them as first and second
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_pair");
        //set the value of the XML element nodes to the object
        XMLElement *first = doc.NewElement("first");
        first->SetAttribute("string",obj.first.c_str());
        XMLElement *second = doc.NewElement("second");
        second->SetAttribute("val",to_string(obj.second).c_str());
        //insert the XML element nodes as the last child nodes of the XML element node
        type->InsertEndChild(first);
        type->InsertEndChild(second);
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template <class T>
    void deserialize_xml(pair<string,T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_pair");
        //retrieve the first child element node of the type element node
        XMLElement *first = type->FirstChildElement("first");
        //set the first element of the object to the value of the XML element node
        const char* firstStr = first->Attribute("string");
        obj.first = firstStr;
        //retrieve the second child element node of the type element node
        XMLElement *second = type->FirstChildElement("second");
        //set the second element of the object to the value of the XML element node
        const char* secondStr = second->Attribute("val");
        istringstream iss(secondStr);
        iss >> obj.second;
    }

    template <class T>
    void serialize_xml(const pair<T,string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create 2 new XML element nodes and name them as first and second
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_pair");
        //set the value of the XML element nodes to the object
        XMLElement *first = doc.NewElement("first");
        first->SetAttribute("val",to_string(obj.first).c_str());
        XMLElement *second = doc.NewElement("second");
        second->SetAttribute("string",obj.second.c_str());
        //insert the XML element nodes as the last child nodes of the XML element node
        type->InsertEndChild(first);
        type->InsertEndChild(second);
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template <class T>
    void deserialize_xml(pair<T,string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_pair");
        //retrieve the first child element node of the type element node
        XMLElement *first = type->FirstChildElement("first");
        //set the first element of the object to the value of the XML element node
        const char* firstStr = first->Attribute("val");
        istringstream iss(firstStr);
        iss >> obj.first;
        //retrieve the second child element node of the type element node
        XMLElement *second = type->FirstChildElement("second");
        //set the second element of the object to the value of the XML element node
        const char* secondStr = second->Attribute("string");
        obj.second = secondStr;
    }

    void serialize_xml(const pair<string,string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as the type of the object
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_pair");
        //create 2 new XML element nodes and name them as first and second
        XMLElement *first = doc.NewElement("first");
        first->SetAttribute("string",obj.first.c_str());
        XMLElement *second = doc.NewElement("second");
        second->SetAttribute("string",obj.second.c_str());
        //insert the XML element nodes as the last child nodes of the XML element node
        type->InsertEndChild(first);
        type->InsertEndChild(second);
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
    }
    void deserialize_xml(pair<string,string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_pair");
        //retrieve the first child element node of the type element node
        XMLElement *first = type->FirstChildElement("first");
        //set the first element of the object to the value of the XML element node
        const char* firstStr = first->Attribute("string");
        obj.first = firstStr;
        //retrieve the second child element node of the type element node
        XMLElement *second = type->FirstChildElement("second");
        //set the second element of the object to the value of the XML element node
        const char* secondStr = second->Attribute("string");
        obj.second = secondStr;
    }




    //serial_xml for vector in xml format
    template <class T>
    void serialize_xml(const vector<T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_VECTOR
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_vector");
        for(int i = 0; i < obj.size(); i++)
        {   
            //create a new XML element node and name it as the type of the object
            XMLElement *value = doc.NewElement("value");
            value->SetAttribute(typeid(T).name(),to_string(obj[i]).c_str());
            type->InsertEndChild(value);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template <class T>
    void deserialize_xml(vector<T> &obj, const string &filename)
    {
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_vector");
        XMLElement *value = type->FirstChildElement("value");
        for(XMLElement *value = type->FirstChildElement("value"); value != NULL; value = value->NextSiblingElement("value"))
        {
            const char* valueStr = value->Attribute(typeid(T).name());
            istringstream iss(valueStr);
            T temp;
            iss >> temp;
            obj.push_back(temp);
        }
    }

    void serialize_xml(const vector<string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_VECTOR
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_vector");
        for(int i = 0; i < obj.size(); i++)
        {
            //create a new XML element node and name it as string
            XMLElement *value = doc.NewElement("value");
            value->SetAttribute("string",obj[i].c_str());
            type->InsertEndChild(value);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());

    }
    void deserialize_xml(vector<string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_vector");
        for(XMLElement *value = type->FirstChildElement("value"); value != NULL; value = value->NextSiblingElement("value"))
        {
            const char* valueStr = value->Attribute("string");
            obj.push_back(valueStr);
        }
    }




    //serial_xml for list in xml format
    template<class T>
    void serialize_xml(const list<T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_LIST
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_list");
        for(typename list<T>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as the type of the object
            XMLElement *value = doc.NewElement("value");
            value->SetAttribute(typeid(T).name(),to_string(*it).c_str());
            type->InsertEndChild(value);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template<class T>
    void deserialize_xml(list<T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_list");
        for(XMLElement *value = type->FirstChildElement("value"); value != NULL; value = value->NextSiblingElement("value"))
        {
            const char* valueStr = value->Attribute(typeid(T).name());
            istringstream iss(valueStr);
            T temp;
            iss >> temp;
            obj.push_back(temp);
        }
    }

    void serialize_xml(const list<string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_LIST
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_list");
        for(list<string>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as string
            XMLElement *value = doc.NewElement("value");
            value->SetAttribute("string",(*it).c_str());
            type->InsertEndChild(value);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
    }
    void deserialize_xml(list<string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_list");
        for(XMLElement *value = type->FirstChildElement("value"); value != NULL; value = value->NextSiblingElement("value"))
        {
            const char* valueStr = value->Attribute("string");
            obj.push_back(valueStr);
        }
    }





    //serial_xml for set in xml format
    template<class T>
    void serialize_xml(const set<T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_SET
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_set");
        for(typename set<T>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as the type of the object
            XMLElement *value = doc.NewElement("value");
            value->SetAttribute(typeid(T).name(),to_string(*it).c_str());
            type->InsertEndChild(value);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template<class T>
    void deserialize_xml(set<T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_set");
        for(XMLElement *value = type->FirstChildElement("value"); value != NULL; value = value->NextSiblingElement("value"))
        {
            const char* valueStr = value->Attribute(typeid(T).name());
            istringstream iss(valueStr);
            T temp;
            iss >> temp;
            obj.insert(temp);
        }
    }

    void serialize_xml(const set<string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_SET
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_set");
        for(set<string>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as string
            XMLElement *value = doc.NewElement("value");
            value->SetAttribute("string",(*it).c_str());
            type->InsertEndChild(value);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
    }
    void deserialize_xml(set<string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_set");
        for(XMLElement *value = type->FirstChildElement("value"); value != NULL; value = value->NextSiblingElement("value"))
        {
            const char* valueStr = value->Attribute("string");
            obj.insert(valueStr);
        }
    }

    //serial_xml for map in xml format
    template<class T1, class T2>
    void serialize_xml(const map<T1, T2> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_MAP
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_map");
        for(typename map<T1, T2>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as the type of the object
            XMLElement *pair = doc.NewElement("pair");
            //create 2 new XML element nodes and name them as first and second
            XMLElement *first = doc.NewElement("first");
            first->SetAttribute(typeid(T1).name(),to_string(it->first).c_str());
            XMLElement *second = doc.NewElement("second");
            second->SetAttribute(typeid(T2).name(),to_string(it->second).c_str());
            //insert the XML element nodes as the last child nodes of the XML element node
            pair->InsertEndChild(first);
            pair->InsertEndChild(second);
            type->InsertEndChild(pair);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template<class T1, class T2>
    void deserialize_xml(map<T1, T2> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_map");
        for(XMLElement *pair = type->FirstChildElement("pair"); pair != NULL; pair = pair->NextSiblingElement("pair"))
        {
            //retrieve the first child element node of the pair element node
            XMLElement *first = pair->FirstChildElement("first");
            //set the first element of the object to the value of the XML element node
            const char* firstStr = first->Attribute(typeid(T1).name());
            istringstream iss1(firstStr);
            T1 temp1;
            iss1 >> temp1;
            //retrieve the second child element node of the pair element node
            XMLElement *second = pair->FirstChildElement("second");
            //set the second element of the object to the value of the XML element node
            const char* secondStr = second->Attribute(typeid(T2).name());
            istringstream iss2(secondStr);
            T2 temp2;
            iss2 >> temp2;
            obj[temp1] = temp2;
        }
    }

    template<class T>
    void serialize_xml(const map<string, T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_MAP
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_map");
        for(typename map<string, T>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as string
            XMLElement *pair = doc.NewElement("pair");
            //create 2 new XML element nodes and name them as first and second
            XMLElement *first = doc.NewElement("first");
            first->SetAttribute("string",it->first.c_str());
            XMLElement *second = doc.NewElement("second");
            second->SetAttribute(typeid(T).name(),to_string(it->second).c_str());
            //insert the XML element nodes as the last child nodes of the XML element node
            pair->InsertEndChild(first);
            pair->InsertEndChild(second);
            type->InsertEndChild(pair);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template<class T>
    void deserialize_xml(map<string, T> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_map");
        for(XMLElement *pair = type->FirstChildElement("pair"); pair != NULL; pair = pair->NextSiblingElement("pair"))
        {
            //retrieve the first child element node of the pair element node
            XMLElement *first = pair->FirstChildElement("first");
            //set the first element of the object to the value of the XML element node
            const char* firstStr = first->Attribute("string");
            //retrieve the second child element node of the pair element node
            XMLElement *second = pair->FirstChildElement("second");
            //set the second element of the object to the value of the XML element node
            const char* secondStr = second->Attribute(typeid(T).name());
            istringstream iss(secondStr);
            T temp;
            iss >> temp;
            obj[firstStr] = temp;
        }
    }

    template<class T>
    void serialize_xml(const map<T, string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_MAP
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_map");
        for(typename map<T, string>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as the type of the object
            XMLElement *pair = doc.NewElement("pair");
            //create 2 new XML element nodes and name them as first and second
            XMLElement *first = doc.NewElement("first");
            first->SetAttribute(typeid(T).name(),to_string(it->first).c_str());
            XMLElement *second = doc.NewElement("second");
            second->SetAttribute("string",it->second.c_str());
            //insert the XML element nodes as the last child nodes of the XML element node
            pair->InsertEndChild(first);
            pair->InsertEndChild(second);
            type->InsertEndChild(pair);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        doc.SaveFile(filename.c_str());
    }
    template<class T>
    void deserialize_xml(map<T, string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_map");
        for(XMLElement *pair = type->FirstChildElement("pair"); pair != NULL; pair = pair->NextSiblingElement("pair"))
        {
            //retrieve the first child element node of the pair element node
            XMLElement *first = pair->FirstChildElement("first");
            //set the first element of the object to the value of the XML element node
            const char* firstStr = first->Attribute(typeid(T).name());
            istringstream iss(firstStr);
            T temp;
            iss >> temp;
            //retrieve the second child element node of the pair element node
            XMLElement *second = pair->FirstChildElement("second");
            //set the second element of the object to the value of the XML element node
            const char* secondStr = second->Attribute("string");
            obj[temp] = secondStr;
        }
    }

    void serialize_xml(const map<string, string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as STD_MAP
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement("std_map");
        for(map<string, string>::const_iterator it = obj.begin(); it != obj.end(); it++)
        {
            //create a new XML element node and name it as string
            XMLElement *pair = doc.NewElement("pair");
            //create 2 new XML element nodes and name them as first and second
            XMLElement *first = doc.NewElement("first");
            first->SetAttribute("string",it->first.c_str());
            XMLElement *second = doc.NewElement("second");
            second->SetAttribute("string",it->second.c_str());
            //insert the XML element nodes as the last child nodes of the XML element node
            pair->InsertEndChild(first);
            pair->InsertEndChild(second);
            type->InsertEndChild(pair);
        }
        //insert the XML element node as the last child node of the XML element node
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
    }
    void deserialize_xml(map<string, string> &obj, const string &filename)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement("std_map");
        for(XMLElement *pair = type->FirstChildElement("pair"); pair != NULL; pair = pair->NextSiblingElement("pair"))
        {
            //retrieve the first child element node of the pair element node
            XMLElement *first = pair->FirstChildElement("first");
            //set the first element of the object to the value of the XML element node
            const char* firstStr = first->Attribute("string");
            //retrieve the second child element node of the pair element node
            XMLElement *second = pair->FirstChildElement("second");
            //set the second element of the object to the value of the XML element node
            const char* secondStr = second->Attribute("string");
            obj[firstStr] = secondStr;
        }
    }



    //serial_xml for user-defined types in xml format
    void serial_xml_userdefined_type(const string &filename)
    {
        return;
    }
    void deserial_xml_userdefined_type(const string &filename)
    {
        return;
    }

    template<class T,class...Args>
    void serial_xml_userdefined_type(const string &filename,T first ,Args...args)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //create a new XML element node and name it as the type of the object
        XMLElement *root = doc.NewElement("serialization");
        XMLElement *type = doc.NewElement(typeid(T).name());
        XMLElement *value = doc.NewElement("value");
        //set the value of the XML element node to the object
        if(std::is_same<T, std::string>::value)
            value->SetAttribute("string",first.c_str());
        else
            value->SetAttribute(typeid(T).name(),to_string(first).c_str());
        //insert the XML element node as the last child node of the XML element node
        type->InsertEndChild(value);
        root->InsertEndChild(type);
        doc.InsertFirstChild(root);
        //save the XML document to a file
        doc.SaveFile(filename.c_str());
        serial_xml_userdefined_type(filename,args...);
    }
    template<class T,class...Args>
    void deserial_xml_userdefined_type(const string &filename,T &first ,Args&...args)
    {
        //create a new XML document
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        //retrieve the first child element node of the XML document
        XMLElement *root = doc.FirstChildElement("serialization");
        XMLElement *type = root->FirstChildElement(typeid(T).name());
        //retrieve the first child element node of the type element node
        XMLElement *value = type->FirstChildElement("value");
        //set the object to the value of the XML element node
        if(std::is_same<T, std::string>::value)
        {
            const char* valueStr = value->Attribute("string");
            first = valueStr;
        }
        else
        {
            const char* valueStr = value->Attribute(typeid(T).name());
            istringstream iss(valueStr);
            iss >> first;
        }
        deserial_xml_userdefined_type(filename,args...);
    }

}

#endif // SERIAL_XML_HPP