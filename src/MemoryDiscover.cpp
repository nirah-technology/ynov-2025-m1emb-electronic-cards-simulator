#include <iostream> // std::cout, std::cin,
#include <string> // std::string
#include <memory> // std::unique_ptr<>, std::make_ptr<>
#include <vector> // std::vector<>

template <typename T>
struct Optional
{
    std::shared_ptr<T> item = nullptr;

    bool is_empty() {
        return this->item == nullptr;
    }
    bool is_present() {
        return this->item != nullptr;
    }

    void set(T item) {
        this->item.swap();
    }
    void clear() {
        this->item = nullptr;
    }
};


void discover_pointers() {

    Optional<long>* optional = new Optional<long>();

    std::cout << optional->is_empty() << std::endl;
    optional->set(10000);


}