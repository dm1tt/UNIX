#include <fstream>
#include <sys/shm.h>
#include "DataExchangeStructure.h"


int main() {

    std::ifstream reader("process_id.txt");
    int segment_id;

    if (reader)
    {
        reader >> segment_id;
        printf("launch fromreader %i", segment_id);
    }

    DataExchangeStruct* shared_mem = (DataExchangeStruct*)shmat(segment_id, 0, 0);

    printf("launch from reader %p \n", shared_mem);

    for (int x = 0; x < 100; x++)
    {
        printf(" %c", shared_mem->data[x]);
    }

}
