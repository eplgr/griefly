#pragma once

#include "Gun.h"

class Revolver: public Gun
{
public:
    DECLARE_SAVED(Revolver, Gun);
    DECLARE_GET_TYPE_ITEM(Revolver);
    Revolver(size_t id);
    virtual void Shoot(VDir target,id_ptr_on<Human> shooter) override;
    virtual void AttackBy(id_ptr_on<Item> item) override;
};
ADD_TO_TYPELIST(Revolver);
