CC=g++

## Library
XMLRPC_LIB=-l xmlrpc++
XMLRPC_CLIENT_LIB=-l xmlrpc_client++
XMLRPC_SERVER_LIB=-l xmlrpc_server++
XMLRPC_SERVER_ABYSS_LIB=-l xmlrpc_server_abyss++
SERVER_LIBS=$(XMLRPC_SERVER_LIB) $(XMLRPC_SERVER_ABYSS_LIB)
CLIENT_LIBS=$(XMLRPC_LIB) $(XMLRPC_CLIENT_LIB)

all: server client

server: clean_server
	$(CC) -o $@ $@.cc $(SERVER_LIBS)

client: clean_client
	$(CC) -o $@ $@.cc $(CLIENT_LIBS)

## clean
clean: clean_server clean_client

clean_server:
	rm -rf server

clean_client:
	rm -rf client
