//DISCLAIMER - THIS WAS NOT BUILT FOR THE DISSERTATION

#include "Component.h"

Component::~Component()
{
}

std::weak_ptr<GameObject> Component::getGameObject()
{
	return gameObject;
}

void Component::onAwake()
{

}

void Component::onUpdate()
{

}

void Component::onRender()
{

}

void Component::onDestroy()
{

}

