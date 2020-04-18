#include <exception>

using namespace std;

class NonAntisimetric: public exception {
public:
    NonAntisimetric () noexcept {}
    NonAntisimetric (const NonAntisimetric&) noexcept = default;
    NonAntisimetric& operator= (const NonAntisimetric&) noexcept = default;
    virtual ~NonAntisimetric() noexcept = default;
    virtual const char* what() const noexcept {
        return "Graful dat nu este antisimetric\n";
    }
};
