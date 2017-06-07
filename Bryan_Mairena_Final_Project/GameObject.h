#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
class GameObject
{
protected:
	std::string name;
	GameObject * parent = nullptr;
	std::vector<GameObject*> *children;
	void addChild(GameObject*);
public:
	GameObject();
	GameObject(std::string);
	GameObject(GameObject*parent = 0);
	GameObject(std::string, GameObject*parent = 0);
	void setParent(GameObject*);
	void setName(std::string);
	std::vector<GameObject*> getChildren();
	virtual void update() = 0;
};
#endif