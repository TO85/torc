#include "ModuleObject.h"

ModuleObject::ModuleObject(const Type aType, QObject *parent)
    : QObject(parent)
{
    (void)(aType); // MUSTUSE(aType)
}
