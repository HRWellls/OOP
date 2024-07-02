#include "serial_bin.hpp"
#include "serial_xml.hpp"

using namespace std;

void arithmetic_bin_test() {
    cout << "Arithmetic_bin_test" << endl;

    int a = 123;
    cout <<"Test arithmetic_bin_serialization: input a = " << a  <<endl;
    bin_serial::serial_bin(a, "int.data");
    int b;
    bin_serial::deserial_bin(b, "int.data");
    cout <<"Test arithmetic_bin_deserialization: output b = " << b << endl;

    float c = 3.14;
    cout <<"Test arithmetic_bin_serialization: input c = " << c << endl;
    bin_serial::serial_bin(c, "float.data");
    float d;
    bin_serial::deserial_bin(d, "float.data");
    cout <<"Test arithmetic_bin_deserialization: output d = " << d << endl;

    cout<<endl;
}

void string_bin_test() {
    cout<<"String_bin_test"<<endl;
    string s = "Hello, World!";
    cout << "Test string_bin_serialization: input s1 = " << s << endl;
    bin_serial::serial_bin(s, "string.data");
    string s2;
    bin_serial::deserial_bin(s2, "string.data");
    cout << "Test string_bin_deserialization: output s2 = " << s2 << endl;

    cout << endl;
}

void pair_bin_test() {
    cout<<"Pair_bin_test"<<endl;
    pair<int, string> p1 = {123, "Hello, World!"};
    cout << "Test pair_bin_serialization: input p1 = " << p1.first << " " << p1.second << endl;
    bin_serial::serial_bin(p1, "pair1.data");
    pair<int, string> p2;
    bin_serial::deserial_bin(p2, "pair1.data");
    cout << "Test pair_bin_deserialization: output p2 = " << p2.first << " " << p2.second << endl;

    pair<string, int> p3 = {"Hello, World!", 123};
    cout << "Test pair_bin_serialization: input p3 = " << p3.first << " " << p3.second << endl;
    bin_serial::serial_bin(p3, "pair2.data");
    pair<string, int> p4;
    bin_serial::deserial_bin(p4, "pair2.data");
    cout << "Test pair_bin_deserialization: output p4 = " << p4.first << " " << p4.second << endl;

    pair<string, string> p5 = {"Hello", "World"};
    cout << "Test pair_bin_serialization: input p5 = " << p5.first << " " << p5.second << endl;
    bin_serial::serial_bin(p5, "pair3.data");
    pair<string, string> p6;
    bin_serial::deserial_bin(p6, "pair3.data");
    cout << "Test pair_bin_deserialization: output p6 = " << p6.first << " " << p6.second << endl;

    pair<int, int> p7 = {123, 456};
    cout << "Test pair_bin_serialization: input p7 = " << p7.first << " " << p7.second << endl;
    bin_serial::serial_bin(p7, "pair4.data");
    pair<int, int> p8;
    bin_serial::deserial_bin(p8, "pair4.data");
    cout << "Test pair_bin_deserialization: output p8 = " << p8.first << " " << p8.second << endl;

    cout << endl;
}

void arithmetic_vector_bin_test() {
    cout<<"Arithmetic_vector_bin_test"<<endl;
    vector<int> v1 = {1, 2, 3, 4, 5};
    cout << "Test arithmetic_vector_bin_serialization: input v1 = ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    bin_serial::serial_bin(v1, "vector.data");
    vector<int> v2;
    bin_serial::deserial_bin(v2, "vector.data");
    cout << "Test arithmetic_vector_bin_deserialization: output v2 = ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    cout << endl;
}

void string_vector_bin_test() {
    cout<<"String_vector_bin_test"<<endl;
    vector<string> v3 = {"Hello", "World", "!"};
    cout << "Test arithmetic_vector_bin_serialization: input v3 = ";
    for (auto i : v3) {
        cout << i << " ";
    }
    cout << endl;
    bin_serial::serial_bin(v3, "vector_string.data");
    vector<string> v4;
    bin_serial::deserial_bin(v4, "vector_string.data");
    cout << "Test arithmetic_vector_bin_deserialization: output v4 = ";
    for (auto i : v4) {
        cout << i << " ";
    }
    cout << endl;

    cout << endl;
}

void list_bin_test() {
    cout<<"List_bin_test"<<endl;
    list<int> l1 = {1, 2, 3, 4, 5};
    cout << "Test list_bin_serialization: input l1 = ";
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
    bin_serial::serial_bin(l1, "list.data");
    list<int> l2;
    bin_serial::deserial_bin(l2, "list.data");
    cout << "Test list_bin_deserialization: output l2 = ";
    for (auto i : l2) {
        cout << i << " ";
    }
    cout << endl;

    list<string> l3 = {"Hello", "World", "!"};
    cout << "Test list_bin_serialization: input l3 = ";
    for (auto i : l3) {
        cout << i << " ";
    }
    cout << endl;
    bin_serial::serial_bin(l3, "list_string.data");
    list<string> l4;
    bin_serial::deserial_bin(l4, "list_string.data");
    cout << "Test list_bin_deserialization: output l4 = ";
    for (auto i : l4) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void set_bin_test() {
    cout<<"Set_bin_test"<<endl;
    set<int> s1 = {1, 2, 3, 4, 5};
    cout << "Test set_bin_serialization: input s1 = ";
    for (auto i : s1) {
        cout << i << " ";
    }
    cout << endl;
    bin_serial::serial_bin(s1, "set.data");
    set<int> s2;
    bin_serial::deserial_bin(s2, "set.data");
    cout << "Test set_bin_deserialization: output s2 = ";
    for (auto i : s2) {
        cout << i << " ";
    }
    cout << endl;

    set<string> s3 = {"Hello", "World", "!"};
    cout << "Test set_bin_serialization: input s3 = ";
    for (auto i : s3) {
        cout << i << " ";
    }
    cout << endl;
    bin_serial::serial_bin(s3, "set_string.data");
    set<string> s4;
    bin_serial::deserial_bin(s4, "set_string.data");
    cout << "Test set_bin_deserialization: output s4 = ";
    for (auto i : s4) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void map_bin_test() {
    cout<<"Map_bin_test"<<endl;
    map<int, string> m1 = {{1, "Hello"}, {2, "World"}, {3, "!"}};
    cout << "Test map_bin_serialization: input m1 = ";
    for (auto i : m1) {
        cout <<"< "<< i.first << " " << i.second<< " >" << " ";
    }
    cout << endl;
    bin_serial::serial_bin(m1, "map.data");
    map<int, string> m2;
    bin_serial::deserial_bin(m2, "map.data");
    cout << "Test map_bin_deserialization: output m2 = ";
    for (auto i : m2) {
        cout<<"< " << i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;

    map<string, int> m3 = {{"Hello", 1}, {"World", 2}, {"!", 3}};
    cout << "Test map_bin_serialization: input m3 = ";
    for (auto i : m3) {
        cout<<"< " << i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;
    bin_serial::serial_bin(m3, "map_string.data");
    map<string, int> m4;
    bin_serial::deserial_bin(m4, "map_string.data");
    cout << "Test map_bin_deserialization: output m4 = ";
    for (auto i : m4) {
        cout <<"< "<< i.first << " " << i.second << " >"<<" ";
    }
    cout << endl;

    map<string, string> m5 = {{"Hello", "World"}, {"World", "!"}, {"!", "Hello"}};
    cout << "Test map_bin_serialization: input m5 = ";
    for (auto i : m5) {
        cout <<"< "<< i.first << " " << i.second<< " >" << " ";
    }
    cout << endl;
    bin_serial::serial_bin(m5, "map_string2.data");
    map<string, string> m6;
    bin_serial::deserial_bin(m6, "map_string2.data");
    cout << "Test map_bin_deserialization: output m6 = ";
    for (auto i : m6) {
        cout <<"< "<< i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;

    map<int, int> m7 = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Test map_bin_serialization: input m7 = ";
    for (auto i : m7) {
        cout <<"< "<< i.first << " " << i.second<< " >" << " ";
    }
    cout << endl;
    bin_serial::serial_bin(m7, "map2.data");
    map<int, int> m8;
    bin_serial::deserial_bin(m8, "map2.data");
    cout<< "Test map_bin_deserialization: output m8 = ";
    for (auto i : m8) {
        cout  <<"< "<< i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;
    cout << endl;
}

void user_defined_type_bin_test() {
    cout<<"User_defined_type_bin_test"<<endl;
    struct UserDefinedType {
    int idx;
    std::string name;
    std::vector<double> data;
    };

    UserDefinedType u1 = {1, "Alice", {1.1, 2.2, 3.3}};
    cout << "Test user_defined_type_bin_serialization: input u1 = "<<u1.idx<<" "<<u1.name<<"     ";
    for(auto i:u1.data){
        cout<<i<<" ";
    }
    cout<<endl;
    bin_serial::serial_bin_userdefined_type("user1.data",u1.idx,u1.name,u1.data);
    
    bin_serial::deserial_bin_userdefined_type("user1.data",u1.idx,u1.name,u1.data);
    cout << "Test user_defined_type_bin_deserialization: output u2 = "<<u1.idx<<" "<<u1.name<<"     ";
    for(auto i:u1.data){
        cout<<i<<" ";
    }
    cout<<endl;

    struct userdefined_type {
        string name;
        int age;
        userdefined_type() {}
        userdefined_type(string name, int age) : name(name), age(age) {}
    };

    userdefined_type u3 = {"Alice", 20};
    cout << "Test user_defined_type_bin_serialization: input u3 = " << u3.name << " " << u3.age << endl;
    bin_serial::serial_bin_userdefined_type("user2.data",u3.name,u3.age);
    userdefined_type u4("Alice", 20);
    bin_serial::deserial_bin_userdefined_type("user2.data",u4.name,u4.age);
    cout << "Test user_defined_type_bin_deserialization: output u4 = " << u4.name << " " << u4.age << endl;

    cout << endl;
}

void arithmetic_xml_test() {
    cout << "Arithmetic_xml_test" << endl;

    int a = 123;
    cout <<"Test arithmetic_xml_serialization: input a = " << a  <<endl;
    xml_serial::serialize_xml(a, "int.xml");
    int b;
    xml_serial::deserialize_xml(b, "int.xml");
    cout <<"Test arithmetic_xml_deserialization: output b = " << b << endl;

    float c = 3.14;
    cout <<"Test arithmetic_xml_serialization: input c = " << c << endl;
    xml_serial::serialize_xml(c, "float.xml");
    float d;
    xml_serial::deserialize_xml(d, "float.xml");
    cout <<"Test arithmetic_xml_deserialization: output d = " << d << endl;

    cout<<endl;
}

void string_xml_test() {
    cout<<"String_xml_test"<<endl;
    string s = "Hello, World!";
    cout << "Test string_xml_serialization: input s1 = " << s << endl;
    xml_serial::serialize_xml(s, "string.xml");
    string s2;
    xml_serial::deserialize_xml(s2, "string.xml");
    cout << "Test string_xml_deserialization: output s2 = " << s2 << endl;

    cout << endl;
}

void pairs_xml_test() {
    cout<<"Pair_xml_test"<<endl;
    pair<int, string> p1 = {123, "Hello, World!"};
    cout << "Test pair_xml_serialization: input p1 = " << p1.first << " " << p1.second << endl;
    xml_serial::serialize_xml(p1, "pair1.xml");
    pair<int, string> p2;
    xml_serial::deserialize_xml(p2, "pair1.xml");
    cout << "Test pair_xml_deserialization: output p2 = " << p2.first << " " << p2.second << endl;

    pair<string, int> p3 = {"Hello, World!", 123};
    cout << "Test pair_xml_serialization: input p3 = " << p3.first << " " << p3.second << endl;
    xml_serial::serialize_xml(p3, "pair2.xml");
    pair<string, int> p4;
    xml_serial::deserialize_xml(p4, "pair2.xml");
    cout << "Test pair_xml_deserialization: output p4 = " << p4.first << " " << p4.second << endl;

    pair<string, string> p5 = {"Hello", "World"};
    cout << "Test pair_xml_serialization: input p5 = " << p5.first << " " << p5.second << endl;
    xml_serial::serialize_xml(p5, "pair3.xml");
    pair<string, string> p6;
    xml_serial::deserialize_xml(p6, "pair3.xml");
    cout << "Test pair_xml_deserialization: output p6 = " << p6.first << " " << p6.second << endl;

    pair<int, int> p7 = {123, 456};
    cout << "Test pair_xml_serialization: input p7 = " << p7.first << " " << p7.second << endl;
    xml_serial::serialize_xml(p7, "pair4.xml");
    pair<int, int> p8;
    xml_serial::deserialize_xml(p8, "pair4.xml");
    cout << "Test pair_xml_deserialization: output p8 = " << p8.first << " " << p8.second << endl;

    cout << endl;
}

void arithmetic_vector_xml_test() {
    cout<<"Arithmetic_vector_xml_test"<<endl;
    vector<int> v1 = {1, 2, 3, 4, 5};
    cout << "Test arithmetic_vector_xml_serialization: input v1 = ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(v1, "vector.xml");
    vector<int> v2;
    xml_serial::deserialize_xml(v2, "vector.xml");
    cout << "Test arithmetic_vector_xml_deserialization: output v2 = ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    cout << endl;
}

void string_vector_xml_test() {
    cout<<"String_vector_xml_test"<<endl;
    vector<string> v3 = {"Hello", "World", "!"};
    cout << "Test arithmetic_vector_xml_serialization: input v3 = ";
    for (auto i : v3) {
        cout << i << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(v3, "vector_string.xml");
    vector<string> v4;
    xml_serial::deserialize_xml(v4, "vector_string.xml");
    cout << "Test arithmetic_vector_xml_deserialization: output v4 = ";
    for (auto i : v4) {
        cout << i << " ";
    }
    cout << endl;

    cout << endl;
}

void list_xml_test() {
    cout<<"List_xml_test"<<endl;
    list<int> l1 = {1, 2, 3, 4, 5};
    cout << "Test list_xml_serialization: input l1 = ";
    for (auto i : l1) {
        cout << i << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(l1, "list.xml");
    list<int> l2;
    xml_serial::deserialize_xml(l2, "list.xml");
    cout << "Test list_xml_deserialization: output l2 = ";
    for (auto i : l2) {
        cout << i << " ";
    }
    cout << endl;

    list<string> l3 = {"Hello", "World", "!"};
    cout << "Test list_xml_serialization: input l3 = ";
    for (auto i : l3) {
        cout << i << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(l3, "list_string.xml");
    list<string> l4;
    xml_serial::deserialize_xml(l4, "list_string.xml");
    cout << "Test list_xml_deserialization: output l4 = ";
    for (auto i : l4) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void set_xml_test() {
    cout<<"Set_xml_test"<<endl;
    set<int> s1 = {1, 2, 3, 4, 5};
    cout << "Test set_xml_serialization: input s1 = ";
    for (auto i : s1) {
        cout << i << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(s1, "set.xml");
    set<int> s2;
    xml_serial::deserialize_xml(s2, "set.xml");
    cout << "Test set_xml_deserialization: output s2 = ";
    for (auto i : s2) {
        cout << i << " ";
    }
    cout << endl;

    set<string> s3 = {"Hello", "World", "!"};
    cout << "Test set_xml_serialization: input s3 = ";
    for (auto i : s3) {
        cout << i << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(s3, "set_string.xml");
    set<string> s4;
    xml_serial::deserialize_xml(s4, "set_string.xml");
    cout << "Test set_xml_deserialization: output s4 = ";
    for (auto i : s4) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void map_xml_test() {
    cout<<"Map_xml_test"<<endl;
    map<int, string> m1 = {{1, "Hello"}, {2, "World"}, {3, "!"}};
    cout << "Test map_xml_serialization: input m1 = ";
    for (auto i : m1) {
        cout <<"< "<< i.first << " " << i.second<< " >" << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(m1, "map1.xml");
    map<int, string> m2;
    xml_serial::deserialize_xml(m2, "map1.xml");
    cout << "Test map_xml_deserialization: output m2 = ";
    for (auto i : m2) {
        cout<<"< " << i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;

    map<string, int> m3 = {{"Hello", 1}, {"World", 2}, {"!", 3}};
    cout << "Test map_xml_serialization: input m3 = ";
    for (auto i : m3) {
        cout<<"< " << i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;
    xml_serial::serialize_xml(m3, "map2.xml");
    map<string, int> m4;
    xml_serial::deserialize_xml(m4, "map2.xml");
    cout << "Test map_xml_deserialization: output m4 = ";
    for (auto i : m4) {
        cout <<"< "<< i.first << " " << i.second << " >"<<" ";
    }
    cout << endl;

    map<string, string> m5 = {{"Hello", "World"}, {"World", "!"}, {"!", "Hello"}};
    cout << "Test map_xml_serialization: input m5 = ";
    for (auto i : m5) {
        cout <<"< "<< i.first << " " << i.second<< " >" << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(m5, "map3.xml");
    map<string, string> m6;
    xml_serial::deserialize_xml(m6, "map3.xml");
    cout << "Test map_xml_deserialization: output m6 = ";
    for (auto i : m6) {
        cout <<"< "<< i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;

    map<int, int> m7 = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Test map_xml_serialization: input m7 = ";
    for (auto i : m7) {
        cout <<"< "<< i.first << " " << i.second<< " >" << " ";
    }
    cout << endl;
    xml_serial::serialize_xml(m7, "map4.xml");
    map<int, int> m8;
    xml_serial::deserialize_xml(m8, "map4.xml");
    cout<< "Test map_xml_deserialization: output m8 = ";
    for (auto i : m8) {
        cout  <<"< "<< i.first << " " << i.second << " >"<< " ";
    }
    cout << endl;
    cout << endl;
}



int main() {
    arithmetic_bin_test();
    string_bin_test();
    pair_bin_test();
    arithmetic_vector_bin_test();
    string_vector_bin_test();
    list_bin_test();
    set_bin_test();
    map_bin_test();
    user_defined_type_bin_test();

    arithmetic_xml_test();
    string_xml_test();
    pairs_xml_test();
    arithmetic_vector_xml_test();
    string_vector_xml_test();
    list_xml_test();
    set_xml_test();
    map_xml_test();
    return 0;
}