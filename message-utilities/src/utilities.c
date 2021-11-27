#include "message_builder.h"

CFE_SB_MsgId_t GetMsgId(void *ptr){
  CFE_SB_Msg_t *MsgPtr = ptr;
  return CFE_SB_GetMsgId(MsgPtr);
}
