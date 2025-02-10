#include "xdgactivationv1.h"
XdgActivationV1::XdgActivationV1()
    : QWaylandClientExtensionTemplate<XdgActivationV1>(1)
    , QtWayland::xdg_activation_v1()
{
}
