#pragma once
#include <qwaylandclientextension.h>
#include "qwayland-xdg-activation-v1.h"

class XdgActivationV1 : public QWaylandClientExtensionTemplate<XdgActivationV1>, public QtWayland::xdg_activation_v1
{
public:
    XdgActivationV1();
};
