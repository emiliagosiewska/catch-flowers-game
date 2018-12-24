#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

struct cell
{
    std::string miasto1;
    std::string miasto2;
    int odleglosc;
    cell *x= nullptr; //pointer ktory sie nazywa x do nastepnej komorki

};

void add_cell (cell *head, cell *next_cell, int &size);






#endif // FUNCTIONS_H
