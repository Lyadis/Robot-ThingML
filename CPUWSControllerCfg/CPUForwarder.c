/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing CPUForwarder
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "CPUForwarder.h"

/*****************************************************************************
 * Implementation for type : CPUForwarder
 *****************************************************************************/

// Declaration of prototypes:
void CPUForwarder_CPUForwarder_OnExit(int state, struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_MCU_Forward(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_MCU_Left(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_MCU_Right(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_MCU_Backward(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_MCU_Stop(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_WS_MotorsReady(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_WS_GoingForward(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_WS_RotatingLeft(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_WS_GoingBackward(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_WS_RotatingRight(struct CPUForwarder_Instance *_instance);
void CPUForwarder_send_WS_Stopped(struct CPUForwarder_Instance *_instance);
// Declaration of functions:

// On Entry Actions:
void CPUForwarder_CPUForwarder_OnEntry(int state, struct CPUForwarder_Instance *_instance) {
switch(state) {
case CPUFORWARDER_CPUFORWARDER_STATE:
_instance->CPUForwarder_CPUForwarder_State = CPUFORWARDER_CPUFORWARDER_INIT_STATE;
CPUForwarder_CPUForwarder_OnEntry(_instance->CPUForwarder_CPUForwarder_State, _instance);
break;
case CPUFORWARDER_CPUFORWARDER_INIT_STATE:
fprintf(stdout, "[CPU] Init\n");
break;
case CPUFORWARDER_CPUFORWARDER_RUNNING_STATE:
break;
default: break;
}
}

// On Exit Actions:
void CPUForwarder_CPUForwarder_OnExit(int state, struct CPUForwarder_Instance *_instance) {
switch(state) {
case CPUFORWARDER_CPUFORWARDER_STATE:
CPUForwarder_CPUForwarder_OnExit(_instance->CPUForwarder_CPUForwarder_State, _instance);
break;
case CPUFORWARDER_CPUFORWARDER_INIT_STATE:
break;
case CPUFORWARDER_CPUFORWARDER_RUNNING_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void CPUForwarder_handle_MCU_MotorsReady(struct CPUForwarder_Instance *_instance) {
uint8_t CPUForwarder_CPUForwarder_State_event_consumed = 0;
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_RUNNING_STATE) {
if (CPUForwarder_CPUForwarder_State_event_consumed == 0 && 1) {
CPUForwarder_send_WS_MotorsReady(_instance);
fprintf(stdout, "[CPU] MotorsReady\n");
CPUForwarder_CPUForwarder_State_event_consumed = 1;
}
}
}
void CPUForwarder_handle_WS_Left(struct CPUForwarder_Instance *_instance) {
uint8_t CPUForwarder_CPUForwarder_State_event_consumed = 0;
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_RUNNING_STATE) {
if (CPUForwarder_CPUForwarder_State_event_consumed == 0 && 1) {
CPUForwarder_send_MCU_Left(_instance);
CPUForwarder_send_WS_RotatingLeft(_instance);
fprintf(stdout, "[CPU] Left\n");
CPUForwarder_CPUForwarder_State_event_consumed = 1;
}
}
}
void CPUForwarder_handle_WS_Forward(struct CPUForwarder_Instance *_instance) {
uint8_t CPUForwarder_CPUForwarder_State_event_consumed = 0;
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_RUNNING_STATE) {
if (CPUForwarder_CPUForwarder_State_event_consumed == 0 && 1) {
CPUForwarder_send_MCU_Forward(_instance);
CPUForwarder_send_WS_GoingForward(_instance);
fprintf(stdout, "[CPU] Forward\n");
CPUForwarder_CPUForwarder_State_event_consumed = 1;
}
}
}
void CPUForwarder_handle_WS_Right(struct CPUForwarder_Instance *_instance) {
uint8_t CPUForwarder_CPUForwarder_State_event_consumed = 0;
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_RUNNING_STATE) {
if (CPUForwarder_CPUForwarder_State_event_consumed == 0 && 1) {
CPUForwarder_send_MCU_Right(_instance);
CPUForwarder_send_WS_RotatingRight(_instance);
fprintf(stdout, "[CPU] Right\n");
CPUForwarder_CPUForwarder_State_event_consumed = 1;
}
}
}
void CPUForwarder_handle_WS_Backward(struct CPUForwarder_Instance *_instance) {
uint8_t CPUForwarder_CPUForwarder_State_event_consumed = 0;
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_RUNNING_STATE) {
if (CPUForwarder_CPUForwarder_State_event_consumed == 0 && 1) {
CPUForwarder_send_MCU_Backward(_instance);
CPUForwarder_send_WS_GoingBackward(_instance);
fprintf(stdout, "[CPU] Backward\n");
CPUForwarder_CPUForwarder_State_event_consumed = 1;
}
}
}
void CPUForwarder_handle_WS_Stop(struct CPUForwarder_Instance *_instance) {
uint8_t CPUForwarder_CPUForwarder_State_event_consumed = 0;
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_RUNNING_STATE) {
if (CPUForwarder_CPUForwarder_State_event_consumed == 0 && 1) {
CPUForwarder_send_MCU_Stop(_instance);
CPUForwarder_send_WS_Stopped(_instance);
fprintf(stdout, "[CPU] Stop\n");
CPUForwarder_CPUForwarder_State_event_consumed = 1;
}
}
}
int CPUForwarder_handle_empty_event(struct CPUForwarder_Instance *_instance) {
if (_instance->CPUForwarder_CPUForwarder_State == CPUFORWARDER_CPUFORWARDER_INIT_STATE) {
if (1) {
CPUForwarder_CPUForwarder_OnExit(CPUFORWARDER_CPUFORWARDER_INIT_STATE, _instance);
_instance->CPUForwarder_CPUForwarder_State = CPUFORWARDER_CPUFORWARDER_RUNNING_STATE;
CPUForwarder_CPUForwarder_OnEntry(CPUFORWARDER_CPUFORWARDER_RUNNING_STATE, _instance);
return 1;
}
}
return 0;
}

// Observers for outgoing messages:
void (*external_CPUForwarder_send_MCU_Forward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_MCU_Forward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_MCU_Forward_listener = _listener;
}
void (*CPUForwarder_send_MCU_Forward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_MCU_Forward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_MCU_Forward_listener = _listener;
}
void CPUForwarder_send_MCU_Forward(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_MCU_Forward_listener != 0x0) CPUForwarder_send_MCU_Forward_listener(_instance);
if (external_CPUForwarder_send_MCU_Forward_listener != 0x0) external_CPUForwarder_send_MCU_Forward_listener(_instance);
;
}
void (*external_CPUForwarder_send_MCU_Left_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_MCU_Left_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_MCU_Left_listener = _listener;
}
void (*CPUForwarder_send_MCU_Left_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_MCU_Left_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_MCU_Left_listener = _listener;
}
void CPUForwarder_send_MCU_Left(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_MCU_Left_listener != 0x0) CPUForwarder_send_MCU_Left_listener(_instance);
if (external_CPUForwarder_send_MCU_Left_listener != 0x0) external_CPUForwarder_send_MCU_Left_listener(_instance);
;
}
void (*external_CPUForwarder_send_MCU_Right_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_MCU_Right_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_MCU_Right_listener = _listener;
}
void (*CPUForwarder_send_MCU_Right_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_MCU_Right_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_MCU_Right_listener = _listener;
}
void CPUForwarder_send_MCU_Right(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_MCU_Right_listener != 0x0) CPUForwarder_send_MCU_Right_listener(_instance);
if (external_CPUForwarder_send_MCU_Right_listener != 0x0) external_CPUForwarder_send_MCU_Right_listener(_instance);
;
}
void (*external_CPUForwarder_send_MCU_Backward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_MCU_Backward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_MCU_Backward_listener = _listener;
}
void (*CPUForwarder_send_MCU_Backward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_MCU_Backward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_MCU_Backward_listener = _listener;
}
void CPUForwarder_send_MCU_Backward(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_MCU_Backward_listener != 0x0) CPUForwarder_send_MCU_Backward_listener(_instance);
if (external_CPUForwarder_send_MCU_Backward_listener != 0x0) external_CPUForwarder_send_MCU_Backward_listener(_instance);
;
}
void (*external_CPUForwarder_send_MCU_Stop_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_MCU_Stop_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_MCU_Stop_listener = _listener;
}
void (*CPUForwarder_send_MCU_Stop_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_MCU_Stop_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_MCU_Stop_listener = _listener;
}
void CPUForwarder_send_MCU_Stop(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_MCU_Stop_listener != 0x0) CPUForwarder_send_MCU_Stop_listener(_instance);
if (external_CPUForwarder_send_MCU_Stop_listener != 0x0) external_CPUForwarder_send_MCU_Stop_listener(_instance);
;
}
void (*external_CPUForwarder_send_WS_MotorsReady_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_WS_MotorsReady_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_WS_MotorsReady_listener = _listener;
}
void (*CPUForwarder_send_WS_MotorsReady_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_WS_MotorsReady_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_WS_MotorsReady_listener = _listener;
}
void CPUForwarder_send_WS_MotorsReady(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_WS_MotorsReady_listener != 0x0) CPUForwarder_send_WS_MotorsReady_listener(_instance);
if (external_CPUForwarder_send_WS_MotorsReady_listener != 0x0) external_CPUForwarder_send_WS_MotorsReady_listener(_instance);
;
}
void (*external_CPUForwarder_send_WS_GoingForward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_WS_GoingForward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_WS_GoingForward_listener = _listener;
}
void (*CPUForwarder_send_WS_GoingForward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_WS_GoingForward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_WS_GoingForward_listener = _listener;
}
void CPUForwarder_send_WS_GoingForward(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_WS_GoingForward_listener != 0x0) CPUForwarder_send_WS_GoingForward_listener(_instance);
if (external_CPUForwarder_send_WS_GoingForward_listener != 0x0) external_CPUForwarder_send_WS_GoingForward_listener(_instance);
;
}
void (*external_CPUForwarder_send_WS_RotatingLeft_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_WS_RotatingLeft_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_WS_RotatingLeft_listener = _listener;
}
void (*CPUForwarder_send_WS_RotatingLeft_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_WS_RotatingLeft_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_WS_RotatingLeft_listener = _listener;
}
void CPUForwarder_send_WS_RotatingLeft(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_WS_RotatingLeft_listener != 0x0) CPUForwarder_send_WS_RotatingLeft_listener(_instance);
if (external_CPUForwarder_send_WS_RotatingLeft_listener != 0x0) external_CPUForwarder_send_WS_RotatingLeft_listener(_instance);
;
}
void (*external_CPUForwarder_send_WS_GoingBackward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_WS_GoingBackward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_WS_GoingBackward_listener = _listener;
}
void (*CPUForwarder_send_WS_GoingBackward_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_WS_GoingBackward_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_WS_GoingBackward_listener = _listener;
}
void CPUForwarder_send_WS_GoingBackward(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_WS_GoingBackward_listener != 0x0) CPUForwarder_send_WS_GoingBackward_listener(_instance);
if (external_CPUForwarder_send_WS_GoingBackward_listener != 0x0) external_CPUForwarder_send_WS_GoingBackward_listener(_instance);
;
}
void (*external_CPUForwarder_send_WS_RotatingRight_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_WS_RotatingRight_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_WS_RotatingRight_listener = _listener;
}
void (*CPUForwarder_send_WS_RotatingRight_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_WS_RotatingRight_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_WS_RotatingRight_listener = _listener;
}
void CPUForwarder_send_WS_RotatingRight(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_WS_RotatingRight_listener != 0x0) CPUForwarder_send_WS_RotatingRight_listener(_instance);
if (external_CPUForwarder_send_WS_RotatingRight_listener != 0x0) external_CPUForwarder_send_WS_RotatingRight_listener(_instance);
;
}
void (*external_CPUForwarder_send_WS_Stopped_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_external_CPUForwarder_send_WS_Stopped_listener(void (*_listener)(struct CPUForwarder_Instance *)){
external_CPUForwarder_send_WS_Stopped_listener = _listener;
}
void (*CPUForwarder_send_WS_Stopped_listener)(struct CPUForwarder_Instance *)= 0x0;
void register_CPUForwarder_send_WS_Stopped_listener(void (*_listener)(struct CPUForwarder_Instance *)){
CPUForwarder_send_WS_Stopped_listener = _listener;
}
void CPUForwarder_send_WS_Stopped(struct CPUForwarder_Instance *_instance){
if (CPUForwarder_send_WS_Stopped_listener != 0x0) CPUForwarder_send_WS_Stopped_listener(_instance);
if (external_CPUForwarder_send_WS_Stopped_listener != 0x0) external_CPUForwarder_send_WS_Stopped_listener(_instance);
;
}



