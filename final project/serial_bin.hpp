#ifndef SERIAL_BIN_HPP
#define SERIAL_BIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

namespace bin_serial{
    //serial_bin for arithmetic types in binary format
    template <class T>
    void serial_bin(const T& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        ofs.write((char*)&obj, sizeof(obj));//write obj to file
        ofs.close();//close file
    }

    template <class T>
    void deserial_bin(T& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        ifs.read((char*)&obj, sizeof(obj));//read obj from file
        ifs.close();//close file
    }




    //serial_bin for string in binary format
    //string can be only serialized by 2 parts: size and content
    //I choose to implement 2 funiton for strings so that latter other functions can use serial_bin_string
    //1.serial_bin_string is the real function to write string to file.
    //2.serial_bin is the function interface provided to user

    //real dealer
    static void serial_bin_string(const string& obj,  ofstream& ofs){
        int size = obj.size();//get size of string
        ofs.write((char*)&size, sizeof(size));//write size to file
        ofs.write(obj.c_str(), size);//write string to file
    }
    static void deserial_bin_string(string& obj, ifstream& ifs){
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        char* buffer = new char[size];
        ifs.read(buffer, size);//read string from file
        obj = string(buffer, size);//convert char* to string
        delete[] buffer;
    }
    //interface
    void serial_bin(const string& obj, const string& filename) {
        ofstream ofs(filename, ios::app | ios::binary);//open file in binary mode
        serial_bin_string(obj, ofs);//write string to file
        ofs.close();//close file
    }
    void deserial_bin(string& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        deserial_bin_string(obj, ifs);//read string from file
        ifs.close();//close file
    }






    //serial_bin for pair in binary format
    //4 kinds of pairs: pair<T1, T2>, pair<string, T>, pair<T, string>, pair<string, string>

    //pair<T1,T2>  can be only serialized by 3 parts: size of pair, first, second
    template <class T1, class T2>
    void serial_bin(const pair<T1, T2>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode

        ofs.write((char*)&obj.first, sizeof(obj.first));//write first to file
        ofs.write((char*)&obj.second, sizeof(obj.second));//write second to file

        ofs.close();//close file
    }
    template <class T1, class T2>
    void deserial_bin(pair<T1, T2>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        ifs.read((char*)&obj.first, sizeof(obj.first));//read first from file
        ifs.read((char*)&obj.second, sizeof(obj.second));//read second from file
        ifs.close();//close file
    }

    //pair<string,T> can be only serialized by 4 parts: size of pair, size of first, first, second
    template <class T>
    void serial_bin(const pair<string, T>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode

        serial_bin_string(obj.first, ofs);//write first to file
        ofs.write((char*)&obj.second, sizeof(obj.second));//write second to file

        ofs.close();//close file
    }
    template <class T>
    void deserial_bin(pair<string, T>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        deserial_bin_string(obj.first, ifs);//read first from file
        ifs.read((char*)&obj.second, sizeof(obj.second));//read second from file
        ifs.close();//close file
    }

    //pair<T,string> can be only serialized by 4 parts: size of pair, first, size of second, second
    template <class T>
    void serial_bin(const pair<T, string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode

        ofs.write((char*)&obj.first, sizeof(obj.first));//write first to file
        serial_bin_string(obj.second, ofs);//write second to file

        ofs.close();//close file
    }
    template <class T>
    void deserial_bin(pair<T, string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        ifs.read((char*)&obj.first, sizeof(obj.first));//read first from file
        deserial_bin_string(obj.second, ifs);//read second from file
        ifs.close();//close file
    }

    //pair<string,string> can be only serialized by 5 parts: size of pair, size of first, first, size of second, second
    void serial_bin(const pair<string, string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode

        serial_bin_string(obj.first, ofs);//write first to file

        serial_bin_string(obj.second, ofs);//write second to file

        ofs.close();//close file
    }
    void deserial_bin(pair<string, string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        deserial_bin_string(obj.first, ifs);//read first from file
        deserial_bin_string(obj.second, ifs);//read second from file
        ifs.close();//close file
    }



    //serial_bin for vector in binary format
    //2 kinds of vectors: vector<T> and vector<string>
    template <class T>
    void serial_bin(const vector<T>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of vector
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (int i = 0; i < size; i++) {
            ofs.write((char*)&obj[i], sizeof(obj[i]));//write vector to file
        }
        ofs.close();//close file
    }
    void serial_bin(const vector<string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of vector
        ofs.write((char*)&size, sizeof(size));//write the size of vector to file
        for (int i = 0; i < size; i++) {
            serial_bin_string(obj[i], ofs);//write string to file
        }
        ofs.close();//close file
    }

    template <class T>
    void deserial_bin(vector<T>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        obj.resize(size);//resize vector
        for (int i = 0; i < size; i++) {
            ifs.read((char*)&obj[i], sizeof(obj[i]));//read vector from file
        }
        ifs.close();//close file
    }
    void deserial_bin(vector<string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        obj.resize(size);//resize vector
        for (int i = 0; i < size; i++) {
            deserial_bin_string(obj[i], ifs);//read string from file
        }
        ifs.close();//close file
    }

    //serial_bin for list in binary format
    //2 kinds of lists: list<T> and list<string>
    template <class T>
    void serial_bin(const list<T>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of list
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            ofs.write((char*)&(*it), sizeof(*it));//write list to file
        }
        ofs.close();//close file
    }

    void serial_bin(const list<string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of list
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            serial_bin_string(*it, ofs);//write string to file
        }
        ofs.close();//close file
    }

    template <class T>
    void deserial_bin(list<T>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            T temp;
            ifs.read((char*)&temp, sizeof(temp));//read list from file
            obj.push_back(temp);//push_back to list
        }
        ifs.close();//close file
    }
    void deserial_bin(list<string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            string temp;
            deserial_bin_string(temp, ifs);//read string from file
            obj.push_back(temp);//push_back to list
        }
        ifs.close();//close file
    }



    //serial_bin for set in binary format
    //2 kinds of sets: set<T> and set<string>
    template <class T>
    void serial_bin(const set<T>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of set
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            ofs.write((char*)&(*it), sizeof(*it));//write set to file
        }
        ofs.close();//close file
    }
    void serial_bin(const set<string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of set
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            serial_bin_string(*it, ofs);//write string to file
        }
        ofs.close();//close file
    }

    template <class T>
    void deserial_bin(set<T>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            T temp;
            ifs.read((char*)&temp, sizeof(temp));//read set from file
            obj.insert(temp);//insert to set
        }
        ifs.close();//close file
    }
    void deserial_bin(set<string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            string temp;
            deserial_bin_string(temp, ifs);//read string from file
            obj.insert(temp);//insert to set
        }
        ifs.close();//close file
    }




    //serial_bin for map in binary format
    //4 kinds of maps: map<T1, T2> map<string, T>, map<T, string>, map<string, string>
    //map<T1, T2> 
    template <class T1, class T2>
    void serial_bin(const map<T1, T2>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of map
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            ofs.write((char*)&it->first, sizeof(it->first));//write first to file
            ofs.write((char*)&it->second, sizeof(it->second));//write second to file
        }
        ofs.close();//close file
    }
    template <class T1, class T2>
    void deserial_bin(map<T1, T2>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            T1 first;
            T2 second;
            ifs.read((char*)&first, sizeof(first));//read first from file
            ifs.read((char*)&second, sizeof(second));//read second from file
            obj[first] = second;//insert to map
        }
        ifs.close();//close file
    }

    template <class T>
    void serial_bin(const map<string, T>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of map
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            serial_bin_string(it->first, ofs);//write first to file
            ofs.write((char*)&it->second, sizeof(it->second));//write second to file
        }
        ofs.close();//close file
    }
    template <class T>
    void deserial_bin(map<string, T>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            string first;
            T second;
            deserial_bin_string(first, ifs);//read first from file
            ifs.read((char*)&second, sizeof(second));//read second from file
            obj[first] = second;//insert to map
        }
        ifs.close();//close file
    }

    template <class T>
    void serial_bin(const map<T, string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of map
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            ofs.write((char*)&it->first, sizeof(it->first));//write first to file
            serial_bin_string(it->second, ofs);//write second to file
        }
        ofs.close();//close file
    }
    template <class T>
    void deserial_bin(map<T, string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            T first;
            string second;
            ifs.read((char*)&first, sizeof(first));//read first from file
            deserial_bin_string(second, ifs);//read second from file
            obj[first] = second;//insert to map
        }
        ifs.close();//close file
    }

    void serial_bin(const map<string, string>& obj, const string& filename) {
        ofstream ofs(filename,ios::app | ios::binary);//open file in binary mode
        int size = obj.size();//get size of map
        ofs.write((char*)&size, sizeof(size));//write size to file
        for (auto it = obj.begin(); it != obj.end(); it++) {
            serial_bin_string(it->first, ofs);//write first to file
            serial_bin_string(it->second, ofs);//write second to file
        }
        ofs.close();//close file
    }
    void deserial_bin(map<string, string>& obj, const string& filename) {
        ifstream ifs(filename, ios::in | ios::binary);//open file in binary mode
        int size;
        ifs.read((char*)&size, sizeof(size));//read size from file
        for (int i = 0; i < size; i++) {
            string first;
            string second;
            deserial_bin_string(first, ifs);//read first from file
            deserial_bin_string(second, ifs);//read second from file
            obj[first] = second;//insert to map
        }
        ifs.close();//close file
    }



    //serial_bin for user defined types in binary format
        void serial_bin_userdefined_type(string filename){
            return;
        }

        void deserial_bin_userdefined_type(string filename){
            return;
        }

        template<class T , class... Args>
        void serial_bin_userdefined_type(string filename, T first, Args... args){
            serial_bin(first, filename);
            serial_bin_userdefined_type(filename, args...);
        }

        template<class T , class... Args>
        void deserial_bin_userdefined_type(string filename, T first, Args... args){
            deserial_bin(first, filename);
            deserial_bin_userdefined_type(filename, args...);
        }


}

#endif // SERIAL_BIN_HPP
