#pragma once
class ByteStream {
private:
    char *data;
    int bytes_allocated;
    int read_offset;
    int write_offset;
public:
    ByteStream(char *data_, int len);
    ByteStream(int len);
    ByteStream();
    ~ByteStream();
    template<class T>
    void Read(T what);
    template<class T>
    void Read(T what, int len);
    template<class T>
    void Write(T what);
    void WriteText(const char *what, int len);
    char *GetData();
    int GetBytes();
};
template<typename T>
inline void ByteStream::Read(T what)
{
    memcpy((void*)what, (void*)&data[read_offset], sizeof(T));
    read_offset += sizeof(T);
}
template<typename T>
inline void ByteStream::Read(T what, int len)
{
    memcpy((void*)what, (void*)&data[read_offset], len);
    read_offset += len;
    }
template<typename T>
inline void ByteStream::Write(T what)
{
    int free_bytes = bytes_allocated - write_offset - sizeof(T);
    if (free_bytes < 0) {
        int new_size = bytes_allocated + abs(free_bytes);
        char *dump = (char*)malloc(new_size);
        memcpy(dump, data, bytes_allocated);
        data = (char*)malloc(new_size);
        memcpy(data, dump, bytes_allocated);
        bytes_allocated = new_size;
        free(dump);
    }
    *(T*)&data[write_offset] = what;
    write_offset += sizeof(T);
}

