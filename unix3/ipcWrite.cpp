#include <stdio.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/shm.h>
#include "cstring"
#include "DataExchangeStructure.h"


int main()
{

    DataExchangeStruct* data = new DataExchangeStruct;
    int segment_size = 1;
    int segment_id = shmget(IPC_PRIVATE, segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    DataExchangeStruct* shared_mem = (DataExchangeStruct*)shmat(segment_id, 0, 0);
    strcpy(shared_mem->data, "sompl text");


    printf("launch from writer %p \n", shared_mem);

    std::ofstream writer;
    writer.open("process_id.txt");

    if (writer)
    {
        printf("writer writing process id %i", segment_id);
        writer << segment_id;
    }

    writer.close();
}
