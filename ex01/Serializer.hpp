#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_data {
    unsigned int n;
}               Data;

class Serializer
{
protected:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif
