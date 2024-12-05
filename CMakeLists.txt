cmake_minimum_required(VERSION 3.28)
project(ConversaoDeBasesEmC C)

# Definindo a versão do padrão C
set(CMAKE_C_STANDARD 23)

# Definindo caminhos para os diretórios de inclusão e bibliotecas do libcurl
set(CURL_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/curl-8.11.0_4-win64-mingw/include")
set(CURL_LIBRARY "${CMAKE_SOURCE_DIR}/curl-8.11.0_4-win64-mingw/lib/libcurl.a")
set(NGHTTP2_LIBRARY "${CMAKE_SOURCE_DIR}/curl-8.11.0_4-win64-mingw/lib/libnghttp2.a")

# Adicionando diretórios de inclusão
include_directories(${CURL_INCLUDE_DIRS})

# Adicionando diretórios de linkagem
link_directories(${CMAKE_SOURCE_DIR}/curl-8.11.0_4-win64-mingw/lib)

# Adicionando o executável do projeto
add_executable(ConversaoDeBasesEmC main.c structs/pessoa.h util/enviaemail.h)

# Definindo CURL_STATICLIB
add_definitions(-DCURL_STATICLIB)

# Linkando as bibliotecas libcurl, nghttp2, ws2_32 e wldap32
target_link_libraries(ConversaoDeBasesEmC PRIVATE ${CURL_LIBRARY} ${NGHTTP2_LIBRARY} ws2_32 wldap32)

# Mensagem para confirmar a configuração do caminho da biblioteca
message(STATUS "CURL_INCLUDE_DIRS: ${CURL_INCLUDE_DIRS}")
message(STATUS "CURL_LIBRARY: ${CURL_LIBRARY}")
message(STATUS "NGHTTP2_LIBRARY: ${NGHTTP2_LIBRARY}")
