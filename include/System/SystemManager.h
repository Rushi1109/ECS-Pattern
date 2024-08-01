#include "System.h"
#include <memory>
#include <unordered_map>
#include "Component.h"

class SystemManager {
public:
    template<typename T, typename... Args>
    std::shared_ptr<T> RegisterSystem(Args&&... args) {
        const char* typeName = typeid(T).name();

        assert(systems.find(typeName) == systems.end() && "Registering system more than once.");

        auto system = std::make_shared<T>(std::forward<decltype(args)>(args)...);
        systems.insert({typeName, system});
        return system;
    }

    template<typename T>
    void SetSignature(Signature signature) {
        const char* typeName = typeid(T).name();

        assert(systems.find(typeName) != systems.end() && "System used before registered.");

        signatures.insert({typeName, signature});
    }

    void EntityDestroyed(Entity entity);
    void EntitySignatureChanged(Entity entity, Signature entitySignature);

private:
    std::unordered_map<const char*, Signature> signatures{};
    std::unordered_map<const char*, std::shared_ptr<System>> systems{};
};
