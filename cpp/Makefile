all: maptest_read maptest_write

maptest_write: maptest_write.cc maptest_generated.h
	c++ -O3 -o $@ $< -lflatbuffers -std=c++14

maptest_read: maptest_read.cc maptest_generated.h
	c++ -O3 -o $@ $< -lflatbuffers -std=c++14

maptest_generated.h: maptest.fbs
	flatc --cpp --gen-object-api maptest.fbs 

clean:
	rm maptest_read maptest_write
