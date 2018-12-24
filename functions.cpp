#include"functions.h"
#include <fstream>
#include <string>
using namespace std;


city* read_data_from_file(string& miasta)
{
    string city1, city2;
    int length;
    char e;
    ifstream cities;
    cities.open("miasta.txt");
    size = 1000;
    city* tab= new city [size];
    int i=0;

    if(!cities)
        return nullptr;
    while (true)
    {
        cities>>city1>>city2>>lenght;
        if(cities)
        {
            if(i<length)
            city[i++] = new city{city1, city2, length};
        }
                                                           //cities>>e;
        if (cities.fail())
            cout<<"error"<<endl;
        if(cities.eof())
            break;
    }
    return tab;
}
//struct cities
//{
 //   string city_name1;
  //  string city_name2;
  //  int distance_between_cities;
//};
int checking_tab()
{
    city* tab[];
    int length=10;
    for(int i=0; i<lenth; i++)
        if(!city)
    {
        city1->distance_to[2]->pointer_to_city=city2*
        city1->distance_to[2]->distance= ??? odl z pliku czyli
    }



    struct city
    {
        string city_name;
        connection_with* tab[];
        city* next_city;
        city* prev_city;
    };
    struct connection_with
    {
        city* connected_with;
        int distance;
    };


    struct file_row
    {
        string name_of_city1;
        string name_of_city2;
        int distance;
    };

   void add_new_city(city* first_city, city* new_city)
    {

        city* temporary_pointer=first_city;
        while(temporary_pointer->next_city!=nullptr)
        {
            temporary_pointer=temporary_pointer->next_city;
        }
           temporary_pointer->next_city=new_city;
           new_city->prev_city=temporary_pointer;
           new_city->next_city=nullptr;

    }
int delete_all_cities(city*first_city)
{
    city* tmp_city1=first_city;
    city* tmp_city2=first_city->next city;
    while(tmp_city2->next_city!=nullptr)
    {
        delete tmp_city1;
        tmp_city1=tmp_city2;
        tmp_city2=tmp_city2->next_city;
    }
        delete tmp_city2;
        return;
}
