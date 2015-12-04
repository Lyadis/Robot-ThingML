/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application CPUWSControllerCfg
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "CPUForwarder.h"
#include "c_MCU_Serial1.h"
#include "c_WS_Websocket.h"





/*****************************************************************************
 * Definitions for configuration : CPUWSControllerCfg
 *****************************************************************************/

//Declaration of connexion array
#define NB_MAX_CONNEXION 2
struct Msg_Handler * CPUWSControllerCfg_receivers[NB_MAX_CONNEXION];

//Declaration of instance variables
//Instance CPUWSControllerCfg_c
// Variables for the properties of the instance
struct CPUForwarder_Instance CPUWSControllerCfg_c_var;
struct Msg_Handler CPUWSControllerCfg_c_MCU_handlers;
uint16_t CPUWSControllerCfg_c_MCU_msgs[1];
void * CPUWSControllerCfg_c_MCU_handlers_tab[1];

struct Msg_Handler CPUWSControllerCfg_c_WS_handlers;
uint16_t CPUWSControllerCfg_c_WS_msgs[5];
void * CPUWSControllerCfg_c_WS_handlers_tab[5];




//Dynamic dispatcher for message Left
void dispatch_Left(uint16_t sender) {
void executor_dispatch_Left(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
struct Msg_Handler ** cur = head;
while (cur != NULL) {
   void (*handler)(void *) = NULL;
   int i;
   for(i = 0; i < (**cur).nb_msg; i++) {
       if((**cur).msg[i] == 11) {
           handler = (void (*) (void *)) (**cur).msg_handler[i];
           break;
       }
   }
   if(handler != NULL) {
       handler((**cur).instance);
}
   if(cur == tail){
       cur = NULL;}
   else {
   cur++;}
}
}
if (sender == CPUWSControllerCfg_c_var.id_MCU) {
executor_dispatch_Left(CPUWSControllerCfg_c_var.MCU_receiver_list_head, CPUWSControllerCfg_c_var.MCU_receiver_list_tail);}
if (sender == Websocket_instance.listener_id) {
executor_dispatch_Left(Websocket_instance.WS_receiver_list_head,Websocket_instance.WS_receiver_list_tail);}
}

//Dynamic dispatcher for message Forward
void dispatch_Forward(uint16_t sender) {
void executor_dispatch_Forward(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
struct Msg_Handler ** cur = head;
while (cur != NULL) {
   void (*handler)(void *) = NULL;
   int i;
   for(i = 0; i < (**cur).nb_msg; i++) {
       if((**cur).msg[i] == 10) {
           handler = (void (*) (void *)) (**cur).msg_handler[i];
           break;
       }
   }
   if(handler != NULL) {
       handler((**cur).instance);
}
   if(cur == tail){
       cur = NULL;}
   else {
   cur++;}
}
}
if (sender == CPUWSControllerCfg_c_var.id_MCU) {
executor_dispatch_Forward(CPUWSControllerCfg_c_var.MCU_receiver_list_head, CPUWSControllerCfg_c_var.MCU_receiver_list_tail);}
if (sender == Websocket_instance.listener_id) {
executor_dispatch_Forward(Websocket_instance.WS_receiver_list_head,Websocket_instance.WS_receiver_list_tail);}
}

//Dynamic dispatcher for message Right
void dispatch_Right(uint16_t sender) {
void executor_dispatch_Right(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
struct Msg_Handler ** cur = head;
while (cur != NULL) {
   void (*handler)(void *) = NULL;
   int i;
   for(i = 0; i < (**cur).nb_msg; i++) {
       if((**cur).msg[i] == 12) {
           handler = (void (*) (void *)) (**cur).msg_handler[i];
           break;
       }
   }
   if(handler != NULL) {
       handler((**cur).instance);
}
   if(cur == tail){
       cur = NULL;}
   else {
   cur++;}
}
}
if (sender == CPUWSControllerCfg_c_var.id_MCU) {
executor_dispatch_Right(CPUWSControllerCfg_c_var.MCU_receiver_list_head, CPUWSControllerCfg_c_var.MCU_receiver_list_tail);}
if (sender == Websocket_instance.listener_id) {
executor_dispatch_Right(Websocket_instance.WS_receiver_list_head,Websocket_instance.WS_receiver_list_tail);}
}

//Dynamic dispatcher for message MotorsReady
void dispatch_MotorsReady(uint16_t sender) {
void executor_dispatch_MotorsReady(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
struct Msg_Handler ** cur = head;
while (cur != NULL) {
   void (*handler)(void *) = NULL;
   int i;
   for(i = 0; i < (**cur).nb_msg; i++) {
       if((**cur).msg[i] == 15) {
           handler = (void (*) (void *)) (**cur).msg_handler[i];
           break;
       }
   }
   if(handler != NULL) {
       handler((**cur).instance);
}
   if(cur == tail){
       cur = NULL;}
   else {
   cur++;}
}
}
if (sender == CPUWSControllerCfg_c_var.id_WS) {
executor_dispatch_MotorsReady(CPUWSControllerCfg_c_var.WS_receiver_list_head, CPUWSControllerCfg_c_var.WS_receiver_list_tail);}
if (sender == Serial1_instance.listener_id) {
executor_dispatch_MotorsReady(Serial1_instance.MCU_receiver_list_head,Serial1_instance.MCU_receiver_list_tail);}
}

//Dynamic dispatcher for message Backward
void dispatch_Backward(uint16_t sender) {
void executor_dispatch_Backward(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
struct Msg_Handler ** cur = head;
while (cur != NULL) {
   void (*handler)(void *) = NULL;
   int i;
   for(i = 0; i < (**cur).nb_msg; i++) {
       if((**cur).msg[i] == 13) {
           handler = (void (*) (void *)) (**cur).msg_handler[i];
           break;
       }
   }
   if(handler != NULL) {
       handler((**cur).instance);
}
   if(cur == tail){
       cur = NULL;}
   else {
   cur++;}
}
}
if (sender == CPUWSControllerCfg_c_var.id_MCU) {
executor_dispatch_Backward(CPUWSControllerCfg_c_var.MCU_receiver_list_head, CPUWSControllerCfg_c_var.MCU_receiver_list_tail);}
if (sender == Websocket_instance.listener_id) {
executor_dispatch_Backward(Websocket_instance.WS_receiver_list_head,Websocket_instance.WS_receiver_list_tail);}
}

//Dynamic dispatcher for message Stop
void dispatch_Stop(uint16_t sender) {
void executor_dispatch_Stop(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
struct Msg_Handler ** cur = head;
while (cur != NULL) {
   void (*handler)(void *) = NULL;
   int i;
   for(i = 0; i < (**cur).nb_msg; i++) {
       if((**cur).msg[i] == 14) {
           handler = (void (*) (void *)) (**cur).msg_handler[i];
           break;
       }
   }
   if(handler != NULL) {
       handler((**cur).instance);
}
   if(cur == tail){
       cur = NULL;}
   else {
   cur++;}
}
}
if (sender == CPUWSControllerCfg_c_var.id_MCU) {
executor_dispatch_Stop(CPUWSControllerCfg_c_var.MCU_receiver_list_head, CPUWSControllerCfg_c_var.MCU_receiver_list_tail);}
if (sender == Websocket_instance.listener_id) {
executor_dispatch_Stop(Websocket_instance.WS_receiver_list_head,Websocket_instance.WS_receiver_list_tail);}
}

void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[2];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 11:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Left((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 10:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Forward((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 12:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Right((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 15:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_MotorsReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 13:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Backward((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 14:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Stop((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}

// Forwarding of messages Websocket::CPUForwarder::WS::MotorsReady
void forward_Websocket_CPUForwarder_send_WS_MotorsReady(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (15 >> 8) & 0xFF;
forward_buf[1] =  15 & 0xFF;


//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Websocket::CPUForwarder::WS::GoingForward
void forward_Websocket_CPUForwarder_send_WS_GoingForward(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (16 >> 8) & 0xFF;
forward_buf[1] =  16 & 0xFF;


//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Websocket::CPUForwarder::WS::RotatingLeft
void forward_Websocket_CPUForwarder_send_WS_RotatingLeft(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (17 >> 8) & 0xFF;
forward_buf[1] =  17 & 0xFF;


//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Websocket::CPUForwarder::WS::GoingBackward
void forward_Websocket_CPUForwarder_send_WS_GoingBackward(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (18 >> 8) & 0xFF;
forward_buf[1] =  18 & 0xFF;


//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Websocket::CPUForwarder::WS::RotatingRight
void forward_Websocket_CPUForwarder_send_WS_RotatingRight(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (19 >> 8) & 0xFF;
forward_buf[1] =  19 & 0xFF;


//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Websocket::CPUForwarder::WS::Stopped
void forward_Websocket_CPUForwarder_send_WS_Stopped(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (20 >> 8) & 0xFF;
forward_buf[1] =  20 & 0xFF;


//Forwarding with specified function 
Websocket_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::CPUForwarder::MCU::Forward
void forward_Serial1_CPUForwarder_send_MCU_Forward(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (10 >> 8) & 0xFF;
forward_buf[1] =  10 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::CPUForwarder::MCU::Left
void forward_Serial1_CPUForwarder_send_MCU_Left(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (11 >> 8) & 0xFF;
forward_buf[1] =  11 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::CPUForwarder::MCU::Right
void forward_Serial1_CPUForwarder_send_MCU_Right(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (12 >> 8) & 0xFF;
forward_buf[1] =  12 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::CPUForwarder::MCU::Backward
void forward_Serial1_CPUForwarder_send_MCU_Backward(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (13 >> 8) & 0xFF;
forward_buf[1] =  13 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

// Forwarding of messages Serial1::CPUForwarder::MCU::Stop
void forward_Serial1_CPUForwarder_send_MCU_Stop(struct CPUForwarder_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (14 >> 8) & 0xFF;
forward_buf[1] =  14 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

void forward_CPUForwarder_send_MCU_Left(struct CPUForwarder_Instance *_instance){
if(_instance->id_MCU == CPUWSControllerCfg_c_var.id_MCU) {
forward_Serial1_CPUForwarder_send_MCU_Left(_instance);
}
}
void forward_CPUForwarder_send_WS_RotatingLeft(struct CPUForwarder_Instance *_instance){
if(_instance->id_WS == CPUWSControllerCfg_c_var.id_WS) {
forward_Websocket_CPUForwarder_send_WS_RotatingLeft(_instance);
}
}
void forward_CPUForwarder_send_MCU_Forward(struct CPUForwarder_Instance *_instance){
if(_instance->id_MCU == CPUWSControllerCfg_c_var.id_MCU) {
forward_Serial1_CPUForwarder_send_MCU_Forward(_instance);
}
}
void forward_CPUForwarder_send_MCU_Right(struct CPUForwarder_Instance *_instance){
if(_instance->id_MCU == CPUWSControllerCfg_c_var.id_MCU) {
forward_Serial1_CPUForwarder_send_MCU_Right(_instance);
}
}
void forward_CPUForwarder_send_WS_RotatingRight(struct CPUForwarder_Instance *_instance){
if(_instance->id_WS == CPUWSControllerCfg_c_var.id_WS) {
forward_Websocket_CPUForwarder_send_WS_RotatingRight(_instance);
}
}
void forward_CPUForwarder_send_WS_MotorsReady(struct CPUForwarder_Instance *_instance){
if(_instance->id_WS == CPUWSControllerCfg_c_var.id_WS) {
forward_Websocket_CPUForwarder_send_WS_MotorsReady(_instance);
}
}
void forward_CPUForwarder_send_MCU_Backward(struct CPUForwarder_Instance *_instance){
if(_instance->id_MCU == CPUWSControllerCfg_c_var.id_MCU) {
forward_Serial1_CPUForwarder_send_MCU_Backward(_instance);
}
}
void forward_CPUForwarder_send_MCU_Stop(struct CPUForwarder_Instance *_instance){
if(_instance->id_MCU == CPUWSControllerCfg_c_var.id_MCU) {
forward_Serial1_CPUForwarder_send_MCU_Stop(_instance);
}
}
void forward_CPUForwarder_send_WS_GoingBackward(struct CPUForwarder_Instance *_instance){
if(_instance->id_WS == CPUWSControllerCfg_c_var.id_WS) {
forward_Websocket_CPUForwarder_send_WS_GoingBackward(_instance);
}
}
void forward_CPUForwarder_send_WS_GoingForward(struct CPUForwarder_Instance *_instance){
if(_instance->id_WS == CPUWSControllerCfg_c_var.id_WS) {
forward_Websocket_CPUForwarder_send_WS_GoingForward(_instance);
}
}
void forward_CPUForwarder_send_WS_Stopped(struct CPUForwarder_Instance *_instance){
if(_instance->id_WS == CPUWSControllerCfg_c_var.id_WS) {
forward_Websocket_CPUForwarder_send_WS_Stopped(_instance);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 11:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 10:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 12:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 15:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 13:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 14:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
fifo_lock();
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
fifo_unlock_and_notify();
}
}
}

void initialize_configuration_CPUWSControllerCfg() {
// Initialize connectors
register_external_CPUForwarder_send_MCU_Forward_listener(forward_CPUForwarder_send_MCU_Forward);
register_external_CPUForwarder_send_MCU_Left_listener(forward_CPUForwarder_send_MCU_Left);
register_external_CPUForwarder_send_MCU_Right_listener(forward_CPUForwarder_send_MCU_Right);
register_external_CPUForwarder_send_MCU_Backward_listener(forward_CPUForwarder_send_MCU_Backward);
register_external_CPUForwarder_send_MCU_Stop_listener(forward_CPUForwarder_send_MCU_Stop);
register_external_CPUForwarder_send_WS_MotorsReady_listener(forward_CPUForwarder_send_WS_MotorsReady);
register_external_CPUForwarder_send_WS_GoingForward_listener(forward_CPUForwarder_send_WS_GoingForward);
register_external_CPUForwarder_send_WS_RotatingLeft_listener(forward_CPUForwarder_send_WS_RotatingLeft);
register_external_CPUForwarder_send_WS_GoingBackward_listener(forward_CPUForwarder_send_WS_GoingBackward);
register_external_CPUForwarder_send_WS_RotatingRight_listener(forward_CPUForwarder_send_WS_RotatingRight);
register_external_CPUForwarder_send_WS_Stopped_listener(forward_CPUForwarder_send_WS_Stopped);

// Init the ID, state variables and properties for external connector Serial1
Serial1_instance.listener_id = add_instance( (void*) &Serial1_instance);
CPUWSControllerCfg_receivers[0] = &CPUWSControllerCfg_c_MCU_handlers;
Serial1_instance.MCU_receiver_list_head = &CPUWSControllerCfg_receivers[0];
Serial1_instance.MCU_receiver_list_tail = &CPUWSControllerCfg_receivers[0];
// Init the ID, state variables and properties for external connector Websocket
Websocket_instance.listener_id = add_instance( (void*) &Websocket_instance);
CPUWSControllerCfg_receivers[1] = &CPUWSControllerCfg_c_WS_handlers;
Websocket_instance.WS_receiver_list_head = &CPUWSControllerCfg_receivers[1];
Websocket_instance.WS_receiver_list_tail = &CPUWSControllerCfg_receivers[1];

// Network Initilization 
//Serial1:
Serial1_setup();
pthread_t thread_c_MCU_Serial1;
pthread_create( &thread_c_MCU_Serial1, NULL, Serial1_start_receiver_process, NULL);
//Websocket:
Websocket_setup();
pthread_t thread_c_WS_Websocket;
pthread_create( &thread_c_WS_Websocket, NULL, Websocket_start_receiver_process, NULL);


// End Network Initilization 

// Init the ID, state variables and properties for instance CPUWSControllerCfg_c
CPUWSControllerCfg_c_var.id_MCU = add_instance( (void*) &CPUWSControllerCfg_c_var);
CPUWSControllerCfg_c_MCU_msgs[0] = 15;
CPUWSControllerCfg_c_MCU_handlers_tab[0] = (void*) &CPUForwarder_handle_MCU_MotorsReady;
CPUWSControllerCfg_c_MCU_handlers.nb_msg = 1;
CPUWSControllerCfg_c_MCU_handlers.msg = (uint16_t *) &CPUWSControllerCfg_c_MCU_msgs;
CPUWSControllerCfg_c_MCU_handlers.msg_handler = (void **) &CPUWSControllerCfg_c_MCU_handlers_tab;
CPUWSControllerCfg_c_MCU_handlers.instance = &CPUWSControllerCfg_c_var;
CPUWSControllerCfg_c_var.MCU_handlers = &CPUWSControllerCfg_c_MCU_handlers;
CPUWSControllerCfg_c_var.MCU_receiver_list_head = NULL;
CPUWSControllerCfg_c_var.MCU_receiver_list_tail = &CPUWSControllerCfg_receivers[2];
CPUWSControllerCfg_c_var.id_WS = add_instance( (void*) &CPUWSControllerCfg_c_var);
CPUWSControllerCfg_c_WS_msgs[0] = 10;
CPUWSControllerCfg_c_WS_handlers_tab[0] = (void*) &CPUForwarder_handle_WS_Forward;
CPUWSControllerCfg_c_WS_msgs[1] = 11;
CPUWSControllerCfg_c_WS_handlers_tab[1] = (void*) &CPUForwarder_handle_WS_Left;
CPUWSControllerCfg_c_WS_msgs[2] = 12;
CPUWSControllerCfg_c_WS_handlers_tab[2] = (void*) &CPUForwarder_handle_WS_Right;
CPUWSControllerCfg_c_WS_msgs[3] = 13;
CPUWSControllerCfg_c_WS_handlers_tab[3] = (void*) &CPUForwarder_handle_WS_Backward;
CPUWSControllerCfg_c_WS_msgs[4] = 14;
CPUWSControllerCfg_c_WS_handlers_tab[4] = (void*) &CPUForwarder_handle_WS_Stop;
CPUWSControllerCfg_c_WS_handlers.nb_msg = 5;
CPUWSControllerCfg_c_WS_handlers.msg = (uint16_t *) &CPUWSControllerCfg_c_WS_msgs;
CPUWSControllerCfg_c_WS_handlers.msg_handler = (void **) &CPUWSControllerCfg_c_WS_handlers_tab;
CPUWSControllerCfg_c_WS_handlers.instance = &CPUWSControllerCfg_c_var;
CPUWSControllerCfg_c_var.WS_handlers = &CPUWSControllerCfg_c_WS_handlers;
CPUWSControllerCfg_c_var.WS_receiver_list_head = NULL;
CPUWSControllerCfg_c_var.WS_receiver_list_tail = &CPUWSControllerCfg_receivers[2];
CPUWSControllerCfg_c_var.CPUForwarder_CPUForwarder_State = CPUFORWARDER_CPUFORWARDER_INIT_STATE;

CPUForwarder_CPUForwarder_OnEntry(CPUFORWARDER_CPUFORWARDER_STATE, &CPUWSControllerCfg_c_var);
}




int main(int argc, char *argv[]) {
  init_runtime();
  
  initialize_configuration_CPUWSControllerCfg();

  while (1) {
    
// Network Listener
int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += CPUForwarder_handle_empty_event(&CPUWSControllerCfg_c_var);
}

    processMessageQueue();
  }
}