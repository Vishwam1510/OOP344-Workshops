// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang
// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 27-11-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"

#include <thread>
#include <functional>
#include <future>
using namespace std::placeholders; 
namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            std::ofstream f(filename,std::ios::out | std::ios::binary | std::ios::trunc);
            if(f.is_open()){
            if(f){
                f.write(reinterpret_cast<char*>(&rows),sizeof(rows));
                f.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
                for(size_t i = 0; i < rows; i++){
                    
                    f.write(&map[i][0], map[i].size());
                    
                }; 
                f.close(); 
            }; 
            // END TODO
            }else{
                throw "Cannot open the file.";
            }; 
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
        std::ifstream f(filename, std::ios::in | std::ios::binary); 
        if(f.is_open()){
        f.read(reinterpret_cast<char*>(&rows), sizeof(size_t));
        f.read(reinterpret_cast<char*>(&colSize), sizeof(size_t));
        map = new std::string[rows];
        
        for (size_t i = 0; i < rows; i++) {
            map[i].resize(colSize);
            f.read(&map[i][0], colSize);
        };
        f.close();
        }else{
            throw "File cannot be opened.";
        };        
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;
        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        
       std::string totalData = ""; 
       for(size_t i = 0; i < rows; i++){
            totalData += map[i]; 
       }; 
      
       auto p = std::bind(digForTreasure, _1, _2); 

       std::packaged_task <size_t(const std::string& , char)> pt1(p); 
       std::packaged_task <size_t(const std::string& , char)> pt2(p); 
       std::packaged_task <size_t(const std::string& , char)> pt3(p); 
       std::packaged_task <size_t(const std::string& , char)> pt4(p);
       auto f1 = pt1.get_future(); 
       auto f2 = pt2.get_future(); 
       auto f3 = pt3.get_future(); 
       auto f4 = pt4.get_future();
       size_t equal4 = totalData.size()/4;       
       std::thread th1(std::move(pt1),totalData.substr(0,equal4) ,mark); 
       std::thread th2(std::move(pt2),totalData.substr(equal4,equal4) , mark); 
       std::thread th3(std::move(pt3),totalData.substr(2*equal4,equal4 ) ,mark); 
       std::thread th4(std::move(pt4),totalData.substr(3 * equal4,equal4) ,mark);
       th1.join();
       th2.join();
       th3.join();
       th4.join();
       count = f1.get() + f2.get() + f3.get() + f4.get();
       return count;
    }
}