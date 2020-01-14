#include "flatbuffers/flatbuffers.h"
#include "maptest_generated.h"
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

using namespace maptest;


int main()

{
  //this is the slightly slower, Object api method:
  int fd=open ("maptest.dat",O_RDONLY);

  //we first read the size

  unsigned int size;
  read(fd,&size,sizeof(size));

  //allocate memory and read

  auto buf=malloc(size);

  read(fd,buf,size);
  close(fd);

  auto eve=flatbuffers::GetRoot<event>(buf);

  for (auto entry:*eve->hits())
   {
     std::cout<<"Entry key:"<<entry->key()<<" X:"<<entry->value().x()<<std::endl;

   }


}

