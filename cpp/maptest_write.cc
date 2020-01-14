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

  eventT evt;


  for (int i=0;i<100;i++)
    {
             
      evt.hits.push_back(entry(i*1000,hit(i,i*10,i*100 )));
    }

  flatbuffers::FlatBufferBuilder fbb;
  fbb.Finish(event::Pack(fbb,&evt));

  std::cout<<"Vector size:"<<evt.hits.size()<<"  Size:"<<fbb.GetSize()<<std::endl;
  int fd=open ("maptest.dat",O_WRONLY|O_CREAT|O_TRUNC,0666);
  unsigned int size=fbb.GetSize(); // We have to write the size first
  write(fd,&size,sizeof(size));
  write(fd,fbb.GetBufferPointer(),size);

  close(fd);


}

