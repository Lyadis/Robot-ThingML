//#ifndef ArduinoSerialForward_h
//
//#define ArduinoSerialForward_h
//#include <Arduino.h>
//#include "ArduinoSerialForward.c"
//
//void Serial1_setup(long bps);
//void Serial1_setListenerID(uint16_t id);
//void Serial1_forwardMessage(byte * msg, uint8_t size);
//void Serial1_read();

//#endif
/*****************************************************************************
 * Headers for type : MotorsController
 *****************************************************************************/

// Definition of the instance stuct:
struct MotorsController_Instance {
// Variables for the ID of the ports of the instance
uint16_t id_CPU;
// Pointer to receiver list
struct Msg_Handler ** CPU_receiver_list_head;
struct Msg_Handler ** CPU_receiver_list_tail;
// Handler Array
struct Msg_Handler * CPU_handlers;
// Variables for the current instance state
int MotorsController_MotorsControllerChart_State;
// Variables for the properties of the instance
uint8_t MotorsController_EnableA__var;
uint8_t MotorsController_InputA1__var;
uint8_t MotorsController_InputA2__var;
uint8_t MotorsController_EnableB__var;
uint8_t MotorsController_InputB1__var;
uint8_t MotorsController_InputB2__var;

};
// Declaration of prototypes outgoing messages:
void MotorsController_MotorsControllerChart_OnEntry(int state, struct MotorsController_Instance *_instance);
void MotorsController_handle_CPU_Stop(struct MotorsController_Instance *_instance);
void MotorsController_handle_CPU_Forward(struct MotorsController_Instance *_instance);
void MotorsController_handle_CPU_Right(struct MotorsController_Instance *_instance);
void MotorsController_handle_CPU_Left(struct MotorsController_Instance *_instance);
void MotorsController_handle_CPU_Backward(struct MotorsController_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_MotorsController_send_CPU_MotorsReady_listener(void (*_listener)(struct MotorsController_Instance *));
void register_external_MotorsController_send_CPU_MotorsReady_listener(void (*_listener)(struct MotorsController_Instance *));

// Definition of the states:
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STATE 0
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE 1
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE 2
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE 3
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE 4
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE 5
#define MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE 6


//Port message handler structure
typedef struct Msg_Handler {
	int nb_msg;
	uint16_t * msg;
	void ** msg_handler;
	void * instance;
};


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();

#define MAX_INSTANCES 2
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}


/*SOFTWARE_SERIAL*/

#define Serial1_LISTENER_STATE_IDLE 0
#define Serial1_LISTENER_STATE_READING 1
#define Serial1_LISTENER_STATE_ESCAPE 2
#define Serial1_LISTENER_STATE_ERROR 3


#define Serial1_START_BYTE 18
#define Serial1_STOP_BYTE 19
#define Serial1_ESCAPE_BYTE 125

#define Serial1_LIMIT_BYTE_PER_LOOP 4
#define Serial1_MAX_MSG_SIZE 2
#define Serial1_MSG_BUFFER_SIZE 4


byte Serial1_serialBuffer[Serial1_MSG_BUFFER_SIZE];
uint8_t Serial1_serialMsgSize = 0;
byte Serial1_incoming = 0;
uint8_t Serial1_serialListenerState = Serial1_LISTENER_STATE_IDLE;


struct Serial1_instance_type {
    uint16_t listener_id;
    //Connector// Pointer to receiver list
struct Msg_Handler ** CPU_receiver_list_head;
struct Msg_Handler ** CPU_receiver_list_tail;
// Handler Array
struct Msg_Handler * CPU_handlers;

} Serial1_instance;

int fifo_byte_available();
int _fifo_enqueue(byte b);

void Serial1_setup() {
	Serial1.begin(115200);
}

void Serial1_set_listener_id(uint16_t id) {
	Serial1_instance.listener_id = id;
}


void Serial1_forwardMessage(byte * msg, uint8_t size) {
  
  Serial1.write(Serial1_START_BYTE);
  for(uint8_t i = 0; i < size; i++) {
    if((msg[i] == Serial1_START_BYTE) 
		|| (msg[i] == Serial1_STOP_BYTE) 
		|| (msg[i] == Serial1_ESCAPE_BYTE)) {
      Serial1.write(Serial1_ESCAPE_BYTE);
    }
    Serial1.write(msg[i]);
  }
  Serial1.write(Serial1_STOP_BYTE);
}

void Serial1_read() {
  byte limit = 0;
  while ((Serial1.available()) && (limit < Serial1_LIMIT_BYTE_PER_LOOP)) {
   limit++;
    Serial1_incoming = Serial1.read();
    
    switch(Serial1_serialListenerState) {
      case Serial1_LISTENER_STATE_IDLE:
        if(Serial1_incoming == Serial1_START_BYTE) {
          Serial1_serialListenerState = Serial1_LISTENER_STATE_READING;
          Serial1_serialMsgSize = 0;
        }
      break;
      
      case Serial1_LISTENER_STATE_READING:
        if (Serial1_serialMsgSize > Serial1_MAX_MSG_SIZE) {
          Serial1_serialListenerState = Serial1_LISTENER_STATE_ERROR;
        } else {
          if(Serial1_incoming == Serial1_STOP_BYTE) {
            Serial1_serialListenerState = Serial1_LISTENER_STATE_IDLE;
            externalMessageEnqueue(Serial1_serialBuffer, Serial1_serialMsgSize, Serial1_instance.listener_id);
            
          } else if (Serial1_incoming == Serial1_ESCAPE_BYTE) {
            Serial1_serialListenerState = Serial1_LISTENER_STATE_ESCAPE;
          } else {
            Serial1_serialBuffer[Serial1_serialMsgSize] = Serial1_incoming;
            Serial1_serialMsgSize++;
          }
        }
      break;
      
      case Serial1_LISTENER_STATE_ESCAPE:
        if (Serial1_serialMsgSize >= Serial1_MAX_MSG_SIZE) {
          Serial1_serialListenerState = Serial1_LISTENER_STATE_ERROR;
        } else {
          Serial1_serialBuffer[Serial1_serialMsgSize] = Serial1_incoming;
          Serial1_serialMsgSize++;
          Serial1_serialListenerState = Serial1_LISTENER_STATE_READING;
        }
      break;
      
      case Serial1_LISTENER_STATE_ERROR:
        Serial1_serialListenerState = Serial1_LISTENER_STATE_IDLE;
        Serial1_serialMsgSize = 0;
      break;
    }
  }
  
}
/*****************************************************************************
 * Implementation for type : MotorsController
 *****************************************************************************/

// Declaration of prototypes:
void MotorsController_MotorsControllerChart_OnExit(int state, struct MotorsController_Instance *_instance);
void MotorsController_send_CPU_MotorsReady(struct MotorsController_Instance *_instance);
// Declaration of functions:

// On Entry Actions:
void MotorsController_MotorsControllerChart_OnEntry(int state, struct MotorsController_Instance *_instance) {
switch(state) {
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STATE:
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE;
pinMode(_instance->MotorsController_EnableA__var,OUTPUT);
pinMode(_instance->MotorsController_InputA1__var,OUTPUT);
pinMode(_instance->MotorsController_InputA2__var,OUTPUT);
pinMode(_instance->MotorsController_EnableB__var,OUTPUT);
pinMode(_instance->MotorsController_InputB1__var,OUTPUT);
pinMode(_instance->MotorsController_InputB2__var,OUTPUT);
MotorsController_send_CPU_MotorsReady(_instance);
MotorsController_MotorsControllerChart_OnEntry(_instance->MotorsController_MotorsControllerChart_State, _instance);
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE:
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE:
digitalWrite(_instance->MotorsController_EnableA__var, LOW);
digitalWrite(_instance->MotorsController_EnableB__var, LOW);
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE:
digitalWrite(_instance->MotorsController_EnableA__var, HIGH);
digitalWrite(_instance->MotorsController_InputA1__var, LOW);
digitalWrite(_instance->MotorsController_InputA2__var, HIGH);
digitalWrite(_instance->MotorsController_EnableB__var, HIGH);
digitalWrite(_instance->MotorsController_InputB1__var, LOW);
digitalWrite(_instance->MotorsController_InputB2__var, HIGH);
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE:
digitalWrite(_instance->MotorsController_EnableA__var, HIGH);
digitalWrite(_instance->MotorsController_InputA1__var, HIGH);
digitalWrite(_instance->MotorsController_InputA2__var, LOW);
digitalWrite(_instance->MotorsController_EnableB__var, HIGH);
digitalWrite(_instance->MotorsController_InputB1__var, LOW);
digitalWrite(_instance->MotorsController_InputB2__var, HIGH);
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE:
digitalWrite(_instance->MotorsController_EnableA__var, HIGH);
digitalWrite(_instance->MotorsController_InputA1__var, LOW);
digitalWrite(_instance->MotorsController_InputA2__var, HIGH);
digitalWrite(_instance->MotorsController_EnableB__var, HIGH);
digitalWrite(_instance->MotorsController_InputB1__var, HIGH);
digitalWrite(_instance->MotorsController_InputB2__var, LOW);
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE:
digitalWrite(_instance->MotorsController_EnableA__var, HIGH);
digitalWrite(_instance->MotorsController_InputA1__var, HIGH);
digitalWrite(_instance->MotorsController_InputA2__var, LOW);
digitalWrite(_instance->MotorsController_EnableB__var, HIGH);
digitalWrite(_instance->MotorsController_InputB1__var, HIGH);
digitalWrite(_instance->MotorsController_InputB2__var, LOW);
break;
default: break;
}
}

// On Exit Actions:
void MotorsController_MotorsControllerChart_OnExit(int state, struct MotorsController_Instance *_instance) {
switch(state) {
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STATE:
MotorsController_MotorsControllerChart_OnExit(_instance->MotorsController_MotorsControllerChart_State, _instance);
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE:
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE:
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE:
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE:
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE:
break;
case MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void MotorsController_handle_CPU_Stop(struct MotorsController_Instance *_instance) {
uint8_t MotorsController_MotorsControllerChart_State_event_consumed = 0;
if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE) {
if (MotorsController_MotorsControllerChart_State_event_consumed == 0 && 1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE, _instance);
MotorsController_MotorsControllerChart_State_event_consumed = 1;
}
}
}
void MotorsController_handle_CPU_Forward(struct MotorsController_Instance *_instance) {
uint8_t MotorsController_MotorsControllerChart_State_event_consumed = 0;
if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE) {
if (MotorsController_MotorsControllerChart_State_event_consumed == 0 && 1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE, _instance);
MotorsController_MotorsControllerChart_State_event_consumed = 1;
}
}
}
void MotorsController_handle_CPU_Right(struct MotorsController_Instance *_instance) {
uint8_t MotorsController_MotorsControllerChart_State_event_consumed = 0;
if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE) {
if (MotorsController_MotorsControllerChart_State_event_consumed == 0 && 1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE, _instance);
MotorsController_MotorsControllerChart_State_event_consumed = 1;
}
}
}
void MotorsController_handle_CPU_Left(struct MotorsController_Instance *_instance) {
uint8_t MotorsController_MotorsControllerChart_State_event_consumed = 0;
if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE) {
if (MotorsController_MotorsControllerChart_State_event_consumed == 0 && 1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE, _instance);
MotorsController_MotorsControllerChart_State_event_consumed = 1;
}
}
}
void MotorsController_handle_CPU_Backward(struct MotorsController_Instance *_instance) {
uint8_t MotorsController_MotorsControllerChart_State_event_consumed = 0;
if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE) {
if (MotorsController_MotorsControllerChart_State_event_consumed == 0 && 1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE, _instance);
MotorsController_MotorsControllerChart_State_event_consumed = 1;
}
}
}
int MotorsController_handle_empty_event(struct MotorsController_Instance *_instance) {
if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE) {
if (1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
return 1;
}
}
else if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE) {
if (1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_FORWARD_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
return 1;
}
}
else if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE) {
if (1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LEFT_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
return 1;
}
}
else if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE) {
if (1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_RIGHT_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
return 1;
}
}
else if (_instance->MotorsController_MotorsControllerChart_State == MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE) {
if (1) {
MotorsController_MotorsControllerChart_OnExit(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_BACKWARD_STATE, _instance);
_instance->MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE;
MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_LISTENING_STATE, _instance);
return 1;
}
}
return 0;
}

// Observers for outgoing messages:
void (*external_MotorsController_send_CPU_MotorsReady_listener)(struct MotorsController_Instance *)= 0x0;
void register_external_MotorsController_send_CPU_MotorsReady_listener(void (*_listener)(struct MotorsController_Instance *)){
external_MotorsController_send_CPU_MotorsReady_listener = _listener;
}
void (*MotorsController_send_CPU_MotorsReady_listener)(struct MotorsController_Instance *)= 0x0;
void register_MotorsController_send_CPU_MotorsReady_listener(void (*_listener)(struct MotorsController_Instance *)){
MotorsController_send_CPU_MotorsReady_listener = _listener;
}
void MotorsController_send_CPU_MotorsReady(struct MotorsController_Instance *_instance){
if (MotorsController_send_CPU_MotorsReady_listener != 0x0) MotorsController_send_CPU_MotorsReady_listener(_instance);
if (external_MotorsController_send_CPU_MotorsReady_listener != 0x0) external_MotorsController_send_CPU_MotorsReady_listener(_instance);
;
}






/*****************************************************************************
 * Definitions for configuration : MotorsControllerCfg
 *****************************************************************************/

//Declaration of connexion array
#define NB_MAX_CONNEXION 1
struct Msg_Handler * MotorsControllerCfg_receivers[NB_MAX_CONNEXION];

//Declaration of instance variables
//Instance MotorsControllerCfg_motors
// Variables for the properties of the instance
struct MotorsController_Instance MotorsControllerCfg_motors_var;
struct Msg_Handler MotorsControllerCfg_motors_CPU_handlers;
uint16_t MotorsControllerCfg_motors_CPU_msgs[5];
void * MotorsControllerCfg_motors_CPU_handlers_tab[5];




//Dynamic dispatcher for message Stop
void dispatch_Stop(uint16_t sender) {
struct executor {
static void executor_dispatch_Stop(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
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
};
if (sender == Serial1_instance.listener_id) {
executor::executor_dispatch_Stop(Serial1_instance.CPU_receiver_list_head,Serial1_instance.CPU_receiver_list_tail);}
}

//Dynamic dispatcher for message Forward
void dispatch_Forward(uint16_t sender) {
struct executor {
static void executor_dispatch_Forward(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
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
};
if (sender == Serial1_instance.listener_id) {
executor::executor_dispatch_Forward(Serial1_instance.CPU_receiver_list_head,Serial1_instance.CPU_receiver_list_tail);}
}

//Dynamic dispatcher for message Right
void dispatch_Right(uint16_t sender) {
struct executor {
static void executor_dispatch_Right(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
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
};
if (sender == Serial1_instance.listener_id) {
executor::executor_dispatch_Right(Serial1_instance.CPU_receiver_list_head,Serial1_instance.CPU_receiver_list_tail);}
}

//Dynamic dispatcher for message Left
void dispatch_Left(uint16_t sender) {
struct executor {
static void executor_dispatch_Left(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
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
};
if (sender == Serial1_instance.listener_id) {
executor::executor_dispatch_Left(Serial1_instance.CPU_receiver_list_head,Serial1_instance.CPU_receiver_list_tail);}
}

//Dynamic dispatcher for message Backward
void dispatch_Backward(uint16_t sender) {
struct executor {
static void executor_dispatch_Backward(struct Msg_Handler ** head, struct Msg_Handler ** tail) {
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
};
if (sender == Serial1_instance.listener_id) {
executor::executor_dispatch_Backward(Serial1_instance.CPU_receiver_list_head,Serial1_instance.CPU_receiver_list_tail);}
}

void processMessageQueue() {
if (fifo_empty()) return; // return if there is nothing to do

byte mbuf[2];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 14:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_Stop((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 10:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_Forward((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 12:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_Right((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 11:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_Left((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
case 13:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
dispatch_Backward((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}

// Forwarding of messages Serial1::MotorsController::CPU::MotorsReady
void forward_Serial1_MotorsController_send_CPU_MotorsReady(struct MotorsController_Instance *_instance){
byte forward_buf[2];
forward_buf[0] = (15 >> 8) & 0xFF;
forward_buf[1] =  15 & 0xFF;


//Forwarding with specified function 
Serial1_forwardMessage(forward_buf, 2);
}

void forward_MotorsController_send_CPU_MotorsReady(struct MotorsController_Instance *_instance){
if(_instance->id_CPU == MotorsControllerCfg_motors_var.id_CPU) {
forward_Serial1_MotorsController_send_CPU_MotorsReady(_instance);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 14:
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
case 11:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
case 13:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
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
}
}
}

void initialize_configuration_MotorsControllerCfg() {
// Initialize connectors
register_external_MotorsController_send_CPU_MotorsReady_listener(forward_MotorsController_send_CPU_MotorsReady);

// Init the ID, state variables and properties for external connector Serial1
Serial1_instance.listener_id = add_instance( (void*) &Serial1_instance);
MotorsControllerCfg_receivers[0] = &MotorsControllerCfg_motors_CPU_handlers;
Serial1_instance.CPU_receiver_list_head = &MotorsControllerCfg_receivers[0];
Serial1_instance.CPU_receiver_list_tail = &MotorsControllerCfg_receivers[0];

// Network Initilization 
//Serial1:
Serial1_setup();


// End Network Initilization 

// Init the ID, state variables and properties for instance MotorsControllerCfg_motors
MotorsControllerCfg_motors_var.id_CPU = add_instance( (void*) &MotorsControllerCfg_motors_var);
MotorsControllerCfg_motors_CPU_msgs[0] = 10;
MotorsControllerCfg_motors_CPU_handlers_tab[0] = (void*) &MotorsController_handle_CPU_Forward;
MotorsControllerCfg_motors_CPU_msgs[1] = 11;
MotorsControllerCfg_motors_CPU_handlers_tab[1] = (void*) &MotorsController_handle_CPU_Left;
MotorsControllerCfg_motors_CPU_msgs[2] = 12;
MotorsControllerCfg_motors_CPU_handlers_tab[2] = (void*) &MotorsController_handle_CPU_Right;
MotorsControllerCfg_motors_CPU_msgs[3] = 13;
MotorsControllerCfg_motors_CPU_handlers_tab[3] = (void*) &MotorsController_handle_CPU_Backward;
MotorsControllerCfg_motors_CPU_msgs[4] = 14;
MotorsControllerCfg_motors_CPU_handlers_tab[4] = (void*) &MotorsController_handle_CPU_Stop;
MotorsControllerCfg_motors_CPU_handlers.nb_msg = 5;
MotorsControllerCfg_motors_CPU_handlers.msg = (uint16_t *) &MotorsControllerCfg_motors_CPU_msgs;
MotorsControllerCfg_motors_CPU_handlers.msg_handler = (void **) &MotorsControllerCfg_motors_CPU_handlers_tab;
MotorsControllerCfg_motors_CPU_handlers.instance = &MotorsControllerCfg_motors_var;
MotorsControllerCfg_motors_var.CPU_handlers = &MotorsControllerCfg_motors_CPU_handlers;
MotorsControllerCfg_motors_var.CPU_receiver_list_head = NULL;
MotorsControllerCfg_motors_var.CPU_receiver_list_tail = &MotorsControllerCfg_receivers[1];
MotorsControllerCfg_motors_var.MotorsController_MotorsControllerChart_State = MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STOP_STATE;
MotorsControllerCfg_motors_var.MotorsController_EnableA__var = 7;
MotorsControllerCfg_motors_var.MotorsController_InputA1__var = 9;
MotorsControllerCfg_motors_var.MotorsController_InputA2__var = 8;
MotorsControllerCfg_motors_var.MotorsController_EnableB__var = 10;
MotorsControllerCfg_motors_var.MotorsController_InputB1__var = 12;
MotorsControllerCfg_motors_var.MotorsController_InputB2__var = 11;

MotorsController_MotorsControllerChart_OnEntry(MOTORSCONTROLLER_MOTORSCONTROLLERCHART_STATE, &MotorsControllerCfg_motors_var);
}




void setup() {
initialize_configuration_MotorsControllerCfg();

}

void loop() {

// Network Listener
Serial1_read();
int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += MotorsController_handle_empty_event(&MotorsControllerCfg_motors_var);
}

    processMessageQueue();
}
