cmake_minimum_required(VERSION 3.28)
project(ConversaoDeBasesEmC C)

set(CMAKE_C_STANDARD 23)


# Caminhos personalizados para os arquivos de include e biblioteca do curl
set(CURL_INCLUDE_DIR "C:/Users/eteixeira/Documents/GitUnesp/ConversaoDeBasesEmC/curl-8.11.0_4-win64-mingw/include")
set(CURL_LIBRARY "C:/Users/eteixeira/Documents/GitUnesp/ConversaoDeBasesEmC/curl-8.11.0_4-win64-mingw/lib/libcurl.a")

# Encontre o pacote CURL com os caminhos especificados
find_package(CURL REQUIRED)

# Adicione o executável do projeto
add_executable(ConversaoDeBasesEmC main.c)

# Inclua o diretório de cabeçalhos do CURL
include_directories(${CURL_INCLUDE_DIR})

# Vincule a biblioteca curl ao projeto
target_link_libraries(ConversaoDeBasesEmC ${CURL_LIBRARY})