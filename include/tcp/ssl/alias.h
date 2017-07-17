/*
* alias.h
*
*  Created on: 2017-7-17
*      Author: youngwolf
*		email: mail2tao@163.com
*		QQ: 676218192
*		Community on QQ: 198941541
*
* some alias, they are deprecated.
*/

#ifndef ST_ASIO_SSL_ALIAS_H_
#define ST_ASIO_SSL_ALIAS_H_

#include "ssl.h"

namespace st_asio_wrapper { namespace ssl {

template <typename Packer, typename Unpacker, typename Socket = boost::asio::ssl::stream<asio::ip::tcp::socket>,
	template<typename, typename> class InQueue = ASCS_INPUT_QUEUE, template<typename> class InContainer = ASCS_INPUT_CONTAINER,
	template<typename, typename> class OutQueue = ASCS_OUTPUT_QUEUE, template<typename> class OutContainer = ASCS_OUTPUT_CONTAINER>
class connector_base : public tcp::client_socket_base<Packer, Unpacker, Socket, InQueue, InContainer, OutQueue, OutContainer>
{
private:
	typedef tcp::client_socket_base<Packer, Unpacker, Socket, InQueue, InContainer, OutQueue, OutContainer> super;

public:
	connector_base(asio::io_service& io_service_, asio::ssl::context& ctx) : super(io_service_, ctx) {}
};
template<typename Socket, typename Pool = object_pool<Socket>> class client_base : public tcp::multi_client_base<Socket, Pool>
{
public:
	client_base(service_pump& service_pump_, boost::asio::ssl::context::method m) : tcp::multi_client_base<Socket, Pool>(service_pump_, m) {}
};

}} //namespace

#endif /* ST_ASIO_SSL_ALIAS_H_ */