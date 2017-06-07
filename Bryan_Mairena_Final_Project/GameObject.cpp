#include "GameObject.h"
GameObject::GameObject()
{
	children = new std::vector<GameObject*>();
}
GameObject::GameObject(std::string name)
{
	this->name = name;
}
GameObject::GameObject(GameObject*parent)
{
	if (parent != NULL)
	{
		this->parent = parent;
		parent->addChild(this);
	}
}
GameObject::GameObject(std::string name, GameObject*parent)
{
	this->name = name;
	if(parent != NULL)
	{
		this->parent = parent;
		parent->addChild(this);
	}

}
void GameObject::addChild(GameObject*child)
{

	if (children != nullptr)
	{
		if (children->size() > 0)
		{
			for (int i = 0; i < children->size(); i++)
			{
				if (child == children->at(i))
				{
					return;
				}
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	if (child != nullptr)
	{
		children->push_back(child);

	}
}
void GameObject::setParent(GameObject*parent)
{
	if (parent != 0)
	{
		this->parent = parent;
		parent->addChild(this);
	}
}
void GameObject::setName(std::string name)
{
	this->name = name;
}
std::vector<GameObject*> GameObject::getChildren()
{
	return *children;
}
void GameObject::update()
{
	return;
}