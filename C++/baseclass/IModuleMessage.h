#pragma once

#include <Windows.h>
#include "ThreadMessageBuffer.h"

/*
* 定义模块ID
*/
enum module_id
{
	TaskMgr = 0,
	ClientMgr = 1,
	Max_Module_Count
};

struct message_header
{
	message_header() { memset(this, 0, sizeof(*this)); cbSize = sizeof(*this); }
	int cbSize;			   // 结构大小
	unsigned int	msg_id;	  // 消息ID
	module_id       from_module_id;	// 发送消息的模块ID
};

/*
*	定义模块的消息范围.四个字节：from|to|消息值
*		1| 1| 2
*/
const unsigned int TaskMgr2Client = (TaskMgr << 24) | (ClientMgr << 16);
const unsigned int Client2TaskMgr = (ClientMgr << 24) | (TaskMgr << 16);


/*
*	定义模块之间的通用接口
*/
class IModuleMessage
{
public:
	IModuleMessage() {}
	virtual ~IModuleMessage() {}

	/*
	*	绑定和释放接口
	*/
	virtual void AdviseMsgSink(module_id from_module_id, IModuleMessage* sink) = 0;
	virtual void UnadviseMsgSink(module_id from_module_id) = 0;

	/*
	*	desc:	发送一个消息到另一个模块
	*/
	virtual bool PostMessage(const message_header msg_hdr, MessageBufferPtr msg_ptr) = 0;
};