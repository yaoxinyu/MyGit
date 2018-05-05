#pragma once

#include <Windows.h>
#include "ThreadMessageBuffer.h"

/*
* ����ģ��ID
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
	int cbSize;			   // �ṹ��С
	unsigned int	msg_id;	  // ��ϢID
	module_id       from_module_id;	// ������Ϣ��ģ��ID
};

/*
*	����ģ�����Ϣ��Χ.�ĸ��ֽڣ�from|to|��Ϣֵ
*		1| 1| 2
*/
const unsigned int TaskMgr2Client = (TaskMgr << 24) | (ClientMgr << 16);
const unsigned int Client2TaskMgr = (ClientMgr << 24) | (TaskMgr << 16);


/*
*	����ģ��֮���ͨ�ýӿ�
*/
class IModuleMessage
{
public:
	IModuleMessage() {}
	virtual ~IModuleMessage() {}

	/*
	*	�󶨺��ͷŽӿ�
	*/
	virtual void AdviseMsgSink(module_id from_module_id, IModuleMessage* sink) = 0;
	virtual void UnadviseMsgSink(module_id from_module_id) = 0;

	/*
	*	desc:	����һ����Ϣ����һ��ģ��
	*/
	virtual bool PostMessage(const message_header msg_hdr, MessageBufferPtr msg_ptr) = 0;
};