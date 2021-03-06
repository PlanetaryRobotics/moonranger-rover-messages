#include "message_builder.h"

#ifdef _WIN32

#include <stdlib.h>
#define bswap_32(x) _byteswap_ulong(x)
#define bswap_64(x) _byteswap_uint64(x)

#elif defined(__APPLE__)

// Mac OS X / Darwin features
#include <libkern/OSByteOrder.h>
#define bswap_32(x) OSSwapInt32(x)
#define bswap_64(x) OSSwapInt64(x)

#else

//#include <byteswap.h>

#endif
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int messageExtract(void* MsgPtr, int msg_len_bytes,
                   message_builder_u* msg_container) {
    // Sanity check what we are about to do
    if (msg_len_bytes <= sizeof(message_builder_u)) {
        memcpy(&msg_container->msg_buf_ptr, MsgPtr, msg_len_bytes);
    } else
        return FAILURE;

    return SUCCESS;
}

int messageBuildTlm(void* dataPtr, message_builder_u* msg_container,
                    int data_len_bytes, int32 msgId) {
    int header_length = CFE_SB_TLM_HDR_SIZE;

    // Fill the header
    CFE_SB_InitMsg(&msg_container->msg_buf_ptr, (CFE_SB_MsgId_t)msgId,
                   header_length + data_len_bytes, true);

    // Fill the data
    // Sanity check what we are about to do
    if (data_len_bytes + header_length <= sizeof(message_builder_u)) {
        memcpy(&msg_container->tlm_data_buf_ptr, dataPtr, data_len_bytes);
    } else
        return FAILURE;

    // Size of built message
    return header_length + data_len_bytes;
}

int messageBuildCmd(void* dataPtr, message_builder_u* msg_container,
                    int data_len_bytes, int32 msgId) {
    // force command code to be 0 if unspecified
    return messageBuildCmdWithCode(dataPtr, msg_container, data_len_bytes,
                                   msgId, 0);
}

int messageBuildCmdWithCode(void* dataPtr, message_builder_u* msg_container,
                            int data_len_bytes, int32 msgId, uint16 cmdCode) {
    int header_length = CFE_SB_CMD_HDR_SIZE;

    // Fill the header
    CFE_SB_InitMsg(&msg_container->msg_buf_ptr, (CFE_SB_MsgId_t)msgId,
                   header_length + data_len_bytes, true);

    // set command code
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&msg_container->msg_buf_ptr, cmdCode);

    // Fill the data
    // Sanity check what we are about to do
    if (data_len_bytes + header_length <= sizeof(message_builder_u)) {
        memcpy(&msg_container->cmd_data_buf_ptr, dataPtr, data_len_bytes);
    } else
        return FAILURE;

    // Size of built message
    return header_length + data_len_bytes;
}
