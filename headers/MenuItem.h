//
// Created by Alex on 4/15/2024.
//



#ifndef OOP_MENUITEM_H
#define OOP_MENUITEM_H

#include <iostream>

class MenuItem {
protected:
    std::string key;
public:
    MenuItem() = default;
    virtual ~MenuItem() = default;

    explicit MenuItem(const std::string &key);
    virtual void executeAction();
};


#endif //OOP_MENUITEM_H
