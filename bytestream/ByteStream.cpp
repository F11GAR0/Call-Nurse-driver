#include "../main.h"

ByteStream::ByteStream(char * data_, int len)
{
    data = (char*)malloc(len);
    memcpy(data, data_, len);
    bytes_allocated = len;
    write_offset = 0;
    read_offset = 0;
}
ByteStream::ByteStream(int len)
{
    data = (char*)malloc(len);
    bytes_allocated = len;
    write_offset = 0;
    read_offset = 0;
}
ByteStream::ByteStream()
{
    bytes_allocated = 0;
    write_offset = 0;
    read_offset = 0;
    data = nullptr;
}
void ByteStream::WriteText(const char *what, int len)
{
    int free_bytes = bytes_allocated - write_offset - len;
    if (free_bytes < 0) {
        int new_size = bytes_allocated + abs(free_bytes);
        char *dump = (char*)malloc(new_size);
        memcpy(dump, data, bytes_allocated);
        data = (char*)malloc(new_size);
        memcpy(data, dump, bytes_allocated);
        bytes_allocated = new_size;
        free(dump);
    }
    memcpy((void*)&data[write_offset], what, len);
    write_offset += len;
}
ByteStream::~ByteStream()
{
    free(data);
}
char *ByteStream::GetData()
{
    return data;
}
int ByteStream::GetBytes()
{
    return bytes_allocated;
}
