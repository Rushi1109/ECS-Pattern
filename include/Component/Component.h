#pragma once

#include <array>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <memory>
#include <cassert>
#include "Entity.h"

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void EntityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
public:
    void InsertData(Entity entity, T component);
    void RemoveData(Entity entity);

    T& GetData(Entity entity);

    void EntityDestroyed(Entity entity) override;

private:
    std::array<T, MAX_ENTITIES> componentArray;
    std::unordered_map<Entity, size_t> entityToIndexMap;
    std::unordered_map<size_t, Entity> indexToEntityMap;
    size_t size = 0;
};

template <typename T>
void ComponentArray<T>::InsertData(Entity entity, T component) {
    assert(entityToIndexMap.find(entity) == entityToIndexMap.end() && "Component added to same entity more than once.");
    size_t newIndex = size;
    entityToIndexMap[entity] = newIndex;
    indexToEntityMap[newIndex] = entity;
    componentArray[newIndex] = component;
    size++;
}

template <typename T>
void ComponentArray<T>::RemoveData(Entity entity) {
    assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Removing non-existent component.");
    size_t indexOfRemovedEntity = entityToIndexMap[entity];
    size_t indexOfLastElement = size - 1;
    componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

    Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
    entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

    entityToIndexMap.erase(entity);
    indexToEntityMap.erase(indexOfLastElement);

    size--;
}

template <typename T>
T& ComponentArray<T>::GetData(Entity entity) {
    assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Retrieving non-existent component.");
    return componentArray[entityToIndexMap[entity]];
}

template <typename T>
void ComponentArray<T>::EntityDestroyed(Entity entity) {
    if (entityToIndexMap.find(entity) != entityToIndexMap.end()) {
        RemoveData(entity);
    }
}