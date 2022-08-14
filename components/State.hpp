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
protected:
    T value;

public:
    State(const std::string& name, const T& value): GenericState(name), value(value) {}
    const std::string getName() {return name; }
    const T getValue() { return value; }

    // Calls the provided function with a reference to a copy of the value so the caller can read but not write it
    void visitValue(std::function<void (void*)> func) override {
        T valueCopy = value;
        func(&valueCopy);
    }
};

template<typename T>
class SetableState: public State<T> {

public:
    SetableState(const std::string& name, const T& value): State<T>(name, value) {}
    void setValue(const T& value) {
        this->value = value;
    }

    // Calls the provided function with the reference of value so it can be modified by the caller
    void visitValue(std::function<void (void*)> func) override {
        func(&this->value);
    }
};
