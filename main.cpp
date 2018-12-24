#include <iostream>
#include"functions.h"

using namespace std;

int main()
{
    cell* head=nullptr;
    int rozmiar=0;


    cell* new_cell= new cell;
    new_cell->odleglosc=5;
    new_cell->miasto1="krakow";
    new_cell->miasto2="warszawa";

    add_cell(head, new_cell, rozmiar);



   city* = read_data_from_file(miasta);
    find_distances_to_all_cities(name_of_city);
    export_data_to_file(koniec);

    return 0;
}
