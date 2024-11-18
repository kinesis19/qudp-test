# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_udp_connection_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED udp_connection_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(udp_connection_FOUND FALSE)
  elseif(NOT udp_connection_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(udp_connection_FOUND FALSE)
  endif()
  return()
endif()
set(_udp_connection_CONFIG_INCLUDED TRUE)

# output package information
if(NOT udp_connection_FIND_QUIETLY)
  message(STATUS "Found udp_connection: 0.1.0 (${udp_connection_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'udp_connection' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${udp_connection_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(udp_connection_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${udp_connection_DIR}/${_extra}")
endforeach()
