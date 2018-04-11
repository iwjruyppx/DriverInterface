
#ifndef __CWM_STATE_MACHINE_H__
#define __CWM_STATE_MACHINE_H__

int osEnqueuePrivateEvt(uint32_t evtType, void* evtData, uint32_t taskID);
int osEnqueuePrivateEvtFromIsr(uint32_t evtType, void* evtData, uint32_t taskID);

int osEnqueueCommon(uint32_t evtType, void* evtData);
int osEnqueueCommonFromIsr(uint32_t evtType, void* evtData);

void osSubscribeEvent(uint32_t evtType, uint32_t taskID);
void osUnSubscribeEvent(uint32_t evtType, uint32_t taskID);

int MainDequeueLoop(void);
void CWM_StateMachineInit(void);

#endif /* __CWM_STATE_MACHINE_H__ */
