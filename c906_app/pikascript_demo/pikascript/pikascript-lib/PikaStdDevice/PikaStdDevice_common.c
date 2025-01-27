#include "PikaStdDevice_common.h"

extern PikaEventListener* g_pika_device_event_listener;
void _PikaStdDevice_event_handler(pika_dev* dev, int signal) {
    pks_eventListener_sendSignal(g_pika_device_event_listener, (uintptr_t)dev,
                                signal);
}

void _PikaStdDevice_setCallBack(PikaObj* self,
                                Arg* eventCallback,
                                uint32_t eventId) {
    obj_setArg(self, "eventCallBack", eventCallback);
    /* init event_listener for the first time */
    if (NULL == g_pika_device_event_listener) {
        pks_eventListener_init(&g_pika_device_event_listener);
    }
    /* regist event to event listener */
    pks_eventListener_registEvent(g_pika_device_event_listener, eventId, self);
}
