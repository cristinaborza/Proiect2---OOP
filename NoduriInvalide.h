#include <exception>

using namespace std;

class NoduriInvalide: public exception {
public:
    NoduriInvalide () noexcept {}
    NoduriInvalide (const NoduriInvalide&) noexcept = default;
    NoduriInvalide& operator= (const NoduriInvalide&) noexcept = default;
    virtual ~NoduriInvalide() noexcept = default;
    virtual const char* what() const noexcept {
        return "Una dintre nodurile date nu este in intervalul corect!\n";
    }
};
