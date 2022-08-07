# Install script for directory: D:/DoItCPP/sample_code/appendix/simple_game/cocos2d/external

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/simple_game")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/Box2D/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/chipmunk/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/freetype2/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/recast/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/bullet/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/jpeg/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/openssl/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/uv/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/webp/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/websockets/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/tinyxml2/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/xxhash/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/xxtea/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/clipper/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/edtaa3func/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/ConvertUTF/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/poly2tri/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/md5/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/curl/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/png/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/win32-specific/gles/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/win32-specific/icon/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/win32-specific/MP3Decoder/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/win32-specific/OggDecoder/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/win32-specific/OpenalSoft/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/glfw3/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/zlib/cmake_install.cmake")
  include("D:/DoItCPP/sample_code/appendix/simple_game/win32-build/engine/external/unzip/cmake_install.cmake")

endif()

