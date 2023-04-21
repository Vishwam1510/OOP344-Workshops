/*
*****************************************************************************
                          Workshop - #7
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "CrimeStatistics.h"

namespace sdds {

    CrimeStatistics::CrimeStatistics(const char* fName){
        std::ifstream is(fName); 
        if(is.is_open()){

            while(is){
                std::string str;  
                std::getline(is ,str , '\n'); 

                std::string provinceSpace = str.substr(0,25); 
                std::string districtSpace = str.substr(25,25); 
                std::string crimeSpace = str.substr(50,25); 
                std::string yearSpace = str.substr(75,5); 
                std::string noCasesSpace = str.substr(80,5);
                std::string noCasesResolveSpace = str.substr(85,5);

                provinceSpace.erase(remove(provinceSpace.begin(), provinceSpace.end(), ' '), provinceSpace.end());
                districtSpace.erase(remove(districtSpace.begin(), districtSpace.end(), ' '), districtSpace.end());
                crimeSpace.erase(remove(crimeSpace.begin(), crimeSpace.end(), ' '), crimeSpace.end());
                yearSpace.erase(remove(yearSpace.begin(), yearSpace.end(), ' '), yearSpace.end());
                noCasesSpace.erase(remove(noCasesSpace.begin(), noCasesSpace.end(), ' '), noCasesSpace.end());
                noCasesResolveSpace.erase(remove(noCasesResolveSpace.begin(), noCasesResolveSpace.end(), ' '), noCasesResolveSpace.end());               

                Crime crimeDetail; 
                crimeDetail.province = provinceSpace; 
                crimeDetail.district = districtSpace; 
                crimeDetail.crime = crimeSpace;
                crimeDetail.year = std::stoi(yearSpace);
                crimeDetail.noCases = std::stoi(noCasesSpace);
                crimeDetail.m_resolved = std::stoi(noCasesResolveSpace);                 

                crimeCollection.push_back(crimeDetail);                
                
                if(is.peek() == EOF){
                    is.setstate(std::ios_base::badbit); 
                }; 
            }; 
        }else{
            throw "File Name Incorrect !!!"; 
        };
    }; 

    void CrimeStatistics::display(std::ostream& out) const{
        std::for_each(crimeCollection.begin() , crimeCollection.end() , [&](const Crime& crime){
            out << crime; 
            out << std::endl; 
        }); 

        unsigned int init = 0; 
        unsigned int totalCases = std::accumulate(crimeCollection.begin() , crimeCollection.end() ,init , [](unsigned int init, const Crime& crime)
        {
            return init + crime.noCases;
        }); 

        unsigned int totalResolvedCases = std::accumulate(crimeCollection.begin() , crimeCollection.end() ,init , [](unsigned int init, const Crime& crime){
            return init + crime.m_resolved; 

        }); 

       
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        out << "| "; 
        out.width(77); 
        out.setf(std::ios::right);
        out << "Total Crimes:"; 
        out.width(7);
        out << totalCases;   
        out << " |"; 
        out.unsetf(std::ios::right); 
        out << std::endl; 
        out << "| "; 
        out.width(77); 
        out.setf(std::ios::right);
        out << "Total Resolved Cases:"; 
        out.width(7);
        out << totalResolvedCases;  
        out << " |"; 
        out.unsetf(std::ios::right); 
        out << std::endl; 


    }; 

    std::ostream& operator<<(std::ostream& out, const Crime& theCrime){
        out << "| "; 
        out.unsetf(std::ios::right);
        out.width(21); 
        out.setf(std::ios::left);
        out << theCrime.province; 
        out.unsetf(std::ios::left);
        out << " | "; 
        out.width(15);
        out.setf(std::ios::left);
        out << theCrime.district; 
        out.unsetf(std::ios::left);
        out << " | "; 
        out.width(20);
        out.setf(std::ios::left);
        out << theCrime.crime; 
        out.unsetf(std::ios::left);
        out << " | "; 
        out.width(6);
        out.setf(std::ios::right);
        out << theCrime.year; 
        out.unsetf(std::ios::right);
        out << " | "; 
        out.width(4);
        out.setf(std::ios::right);
        out << theCrime.noCases; 
        out.unsetf(std::ios::right);
        out << " | "; 
        out.width(3); 
        out.setf(std::ios::right);
        out << theCrime.m_resolved; 
        out.unsetf(std::ios::right);
        out << " |"; 

        return out; 
    }; 

    void CrimeStatistics::sort(std::string fieldName){
        
        if(fieldName == "Province"){
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.province < crime2.province;
            });  

        }else if(fieldName == "Crime"){
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.crime < crime2.crime;
            });  

        }else if(fieldName == "Cases"){
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.noCases < crime2.noCases;
            });  
        }else{            
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.m_resolved < crime2.m_resolved;
            });  

        }; 
    };

    void CrimeStatistics::cleanList(){
        std::vector <Crime> crimesWithoutNone(crimeCollection.size()); 
        std::transform(crimeCollection.begin() , crimeCollection.end() , crimesWithoutNone.begin(),[](Crime crimeDetail){            
            if(crimeDetail.crime == "[None]"){
                crimeDetail.crime = ""; 
            };
            return crimeDetail;  
        }); 
        crimeCollection = crimesWithoutNone; 
    };
    bool CrimeStatistics::inCollection(std::string crimeType) const{

        unsigned int cnt = std::count_if(crimeCollection.begin(), crimeCollection.end() ,[=](const Crime& crimeDetail){
             return crimeType == crimeDetail.crime; 
        });
        return (cnt > 0)?true : false; 

    }; 

    std::list<Crime> CrimeStatistics::getListForProvince(std::string provinceName) const{
        std::vector <Crime> crimesInProvinceVector(crimeCollection.size()); 
        auto it = std::copy_if(crimeCollection.begin() , crimeCollection.end() , crimesInProvinceVector.begin(),[=](const Crime& crimeDetail){
            return crimeDetail.province == provinceName; 
        });
        unsigned int size = it - crimesInProvinceVector.begin();
        std::list <Crime> crimesInProvinceList(size); 
        std::copy(crimesInProvinceVector.begin() , it , crimesInProvinceList.begin());
        return crimesInProvinceList; 
    }; 
}