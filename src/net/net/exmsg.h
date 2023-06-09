/**
 * @file exmsg.h
 * @author 工作线程
 * @brief 
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef EXMSG_H
#define EXMSG_H

#include "net_err.h"
#include "nlist.h"
#include "netif.h"

/**
 * @brief 消息来自于哪个网络接口(即网卡)
 * 
 */
typedef struct _msg_netif_t {
	netif_t * netif;
}msg_netif_t;

// 通用消息结构
typedef struct _exmsg_t {
	// 临时调试用
	nlist_node_t node;

	// 消息类型
	enum {
		NET_EXMSG_NETIF_IN,  	// 网络接口消息数据
	} type;

	union {
		msg_netif_t netif;
	};

}exmsg_t;


net_err_t exmsg_init(void);
net_err_t exmsg_start(void);
net_err_t exmsg_netif_in(netif_t * netif);

#endif