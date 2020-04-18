#include <exception>

using namespace std;

class NonComplete: public exception {
public:
    NonComplete () noexcept {}
    NonComplete (const NonComplete&) noexcept = default;
    NonComplete& operator= (const NonComplete&) noexcept = default;
    virtual ~NonComplete() noexcept = default;
    virtual const char* what() const noexcept {
        return "Graful dat nu este complet (nu are toate arcele)!\n";
    }
};
