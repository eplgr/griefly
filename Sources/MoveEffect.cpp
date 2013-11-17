#include "MoveEffect.h"
#include "MapClass.h"

Move::Move()
{
    way = 0;
    master = 0;
    direct = D_UP;
    back = false;
    pixel_speed = 1;
}

void Move::Init(int way_n, Dir direct_n, int pixel_speed_n, id_ptr_on<IOnMapItem> master_n, bool back_n)
{
    way = way_n;
    direct = direct_n;
    back = back_n;
    master = master_n;
    pixel_speed = pixel_speed_n;
}

void Move::start()
{
    MapMaster::switchDir(master->step_x, master->step_y, direct, way, back);
}

void Move::process()
{
    if (master.ret_id() == 0 || master.ret_item() == nullptr || way == 0)
    {
        Release();
        return;
    }
    int l = (pixel_speed <= way) ? (pixel_speed) : (pixel_speed - way);
    MapMaster::switchDir(master->step_x, master->step_y, direct, -l, back);
    way -= l;
}

void Move::end()
{
}

void Move::release()
{
    if (!(master.ret_id() == 0 || master.ret_item() == nullptr || way == 0))
        MapMaster::switchDir(master->step_x, master->step_y, direct, -way, back);
    way = 0;
    master = 0;
    direct = D_UP;
    back = false;
    pixel_speed = 1;
}