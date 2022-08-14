#include <string>
#include <functional>

class GenericState {
public:
    std::string name;
    virtual ~GenericState() = default;
    virtual void visitValue(std::function<void (void*)> func) = 0;
protected:
    GenericState(std::string name): name(name) {}
};

template<typename T>
class State: public GenericState {
    T value;

public:
    State(const std::string& name, const T& value): GenericState(name), value(value) {}
    const std::string getName() {return name; }
    const T getValue() { return value; }

    void visitValue(std::function<void (void*)> func) override {
        func(&value);
    }
};

template<typename T>
class SetableState: public State<T> {

public:
    SetableState(const std::string& name, const T& value): State<T>(name, value) {}
    void setValue(const T& value) {
        this->value = value;
    }
};
