#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H

#include "util.h"
#include <string>
#include <stdio.h>

class OutputStream
{
public:
    virtual void writeChar (unsigned char v) = 0;
	 /* Write 1 bytes in the output (little endian order) */
	 virtual void writeBoolean (bool v) = 0;
	 /* Write 2 bytes in the output (little endian order) */
	 virtual void writeInt (__int32 v) = 0;
	 /* Write 4 bytes in the output (little endian order) */
	 virtual void writeLong (__int64 v) = 0;
	 /* Write a 4 byte float in the output */
	 virtual void writeFloatIEEE (float v) = 0;
	 /* Write a 8 byte double in the output */
	 virtual void writeDoubleIEEE (double v) = 0;
	 /* Write a char */
	 virtual void writeChars(const char* text, __int32 len) = 0;
	 virtual void writeString(const std::string& text) = 0;

	// Does nothing at the base, but can be overriden to provide flush capabilities
	 virtual void flush() {
	 };

	 template<typename T>
		 void writeData(T data) {
			 unsigned char* v = (unsigned char*)&data;
			 int size = sizeof(T);
			 for (int i = 0; i < size; i++) {
				 unsigned char c = v[i];
				 writeChar(c);
			 }
		 }
	 /*
		 void writeData(unsigned char* v, int size) {
		 for (int i = 0; i < size; i++) {
		 unsigned char c = v[i];
		 writeChar(c);
		 }
		 }
		 */
};

#endif // OUTPUTSTREAM_H
