# include "Serializer.hpp"

int main() {
	Data data;
	data.n = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Original Data address: " << &data << ", n: " << data.n << std::endl;
	std::cout << "Serialized raw value: " << raw << std::endl;
	std::cout << "Deserialized Data address: " << deserializedData << ", n: " << deserializedData->n << std::endl;
	return 0;
}