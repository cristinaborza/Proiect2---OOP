#include <exception>

using namespace std;

class SelfLoop: public exception {
public:
    SelfLoop () noexcept {}
    SelfLoop (const SelfLoop&) noexcept = default;
    SelfLoop& operator= (const SelfLoop&) noexcept = default;
    virtual ~SelfLoop() noexcept = default;
    virtual const char* what() const noexcept {
        return "Graful dat are self loop - uri!\n";
    }
};
