#include "StateContext.h"
#include <iostream>

int main()
{
    StateContext* st = new StateContext();
    st->WriteState("Door"); // unlock
    st->WriteState("Door"); // open
    st->WriteState("Door"); // close
    st->WriteState("Door"); // lock
    return 0;
}
