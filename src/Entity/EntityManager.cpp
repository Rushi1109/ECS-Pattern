#include "EntityManager.h"

Entity EntityManager::CreateEntity() {
    assert(livingEntityCount < MAX_ENTITIES &&
           "Too many entities in existence.");

    Entity id = availableEntities.front();
    availableEntities.pop();
    ++livingEntityCount;

    return id;
}

void EntityManager::DestroyEntity(Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    signatures[entity].reset();
    availableEntities.push(entity);
    --livingEntityCount;
}

void EntityManager::SetSignature(Entity entity, Signature signature) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    signatures[entity] = signature;
}

Signature EntityManager::GetSignature(Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    return signatures[entity];
}