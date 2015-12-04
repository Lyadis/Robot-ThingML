/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing CPUForwarder
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef CPUForwarder_H_
#define CPUForwarder_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : CPUForwarder
 *****************************************************************************/

// Definition of the instance stuct:
struct CPUForwarder_Instance {
// Variables for the ID of the ports of the instance
uint16_t id_MCU;
// Pointer to receiver list
struct Msg_Handler ** MCU_receiver_list_head;
struct Msg_Handler ** MCU_receiver_list_tail;
// Handler Array
struct Msg_Handler * MCU_handlers;
uint16_t id_WS;
// Pointer to receiver list
struct Msg_Handler ** WS_receiver_list_head;
struct Msg_Handler ** WS_receiver_list_tail;
// Handler Array
struct Msg_Handler * WS_handlers;
// Variables for the current instance state
int CPUForwarder_CPUForwarder_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages:
void CPUForwarder_CPUForwarder_OnEntry(int state, struct CPUForwarder_Instance *_instance);
void CPUForwarder_handle_MCU_MotorsReady(struct CPUForwarder_Instance *_instance);
void CPUForwarder_handle_WS_Left(struct CPUForwarder_Instance *_instance);
void CPUForwarder_handle_WS_Forward(struct CPUForwarder_Instance *_instance);
void CPUForwarder_handle_WS_Right(struct CPUForwarder_Instance *_instance);
void CPUForwarder_handle_WS_Backward(struct CPUForwarder_Instance *_instance);
void CPUForwarder_handle_WS_Stop(struct CPUForwarder_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_CPUForwarder_send_MCU_Forward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_MCU_Forward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_MCU_Left_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_MCU_Left_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_MCU_Right_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_MCU_Right_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_MCU_Backward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_MCU_Backward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_MCU_Stop_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_MCU_Stop_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_WS_MotorsReady_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_WS_MotorsReady_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_WS_GoingForward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_WS_GoingForward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_WS_RotatingLeft_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_WS_RotatingLeft_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_WS_GoingBackward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_WS_GoingBackward_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_WS_RotatingRight_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_WS_RotatingRight_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_CPUForwarder_send_WS_Stopped_listener(void (*_listener)(struct CPUForwarder_Instance *));
void register_external_CPUForwarder_send_WS_Stopped_listener(void (*_listener)(struct CPUForwarder_Instance *));

// Definition of the states:
#define CPUFORWARDER_CPUFORWARDER_STATE 0
#define CPUFORWARDER_CPUFORWARDER_INIT_STATE 1
#define CPUFORWARDER_CPUFORWARDER_RUNNING_STATE 2



#ifdef __cplusplus
}
#endif

#endif //CPUForwarder_H_
