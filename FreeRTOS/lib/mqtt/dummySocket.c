
#include "aws_secure_sockets.h"


int32_t SOCKETS_Close( Socket_t xSocket )
{
	//dummy
}


int32_t SOCKETS_Connect( Socket_t xSocket,
                         SocketsSockaddr_t * pxAddress,
                         Socklen_t xAddressLength )
{

}


uint32_t SOCKETS_GetHostByName( const char * pcHostName ){}


int32_t SOCKETS_Recv( Socket_t xSocket,
                      void * pvBuffer,
                      size_t xBufferLength,
                      uint32_t ulFlags ){}

int32_t SOCKETS_Send( Socket_t xSocket,
						  const void * pvBuffer,
						  size_t xDataLength,
						  uint32_t ulFlags ){}


int32_t SOCKETS_SetSockOpt( Socket_t xSocket,
									int32_t lLevel,
									int32_t lOptionName,
									const void * pvOptionValue,
									size_t xOptionLength ){}

int32_t SOCKETS_Shutdown( Socket_t xSocket,
                          uint32_t ulHow ){}


Socket_t SOCKETS_Socket( int32_t lDomain,
                         int32_t lType,
                         int32_t lProtocol ){}












