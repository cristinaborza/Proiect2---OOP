#include <exception>

using namespace std;

class MultipleArrows: public exception {
public:
    MultipleArrows () noexcept {}
    MultipleArrows (const MultipleArrows&) noexcept = default;
    MultipleArrows& operator= (const MultipleArrows&) noexcept = default;
    virtual ~MultipleArrows() noexcept = default;
    virtual const char* what() const noexcept {
        return "Graful dat are arce multiple!\n";
    }
};
