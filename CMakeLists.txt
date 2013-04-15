project(cscope)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
)

find_package(KDE4 REQUIRED)
find_package(KDevPlatform REQUIRED)

include_directories(
    ${KDE4_INCLUDES}
    ${KDEVPLATFORM_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

#add_definitions(-DKDE_DEFAULT_DEBUG_AREA=)

set(projectview_SRCS
	projectviewplugin.cpp
)

kde4_add_plugin(kdevcscopeplugin ${projectview_SRCS})
target_link_libraries(kdevcscopeplugin ${KDEVPLATFORM_INTERFACES_LIBRARIES} ${KDEVPLATFORM_LANGUAGE_LIBRARIES})

install(TARGETS kdevcscopeplugin DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES kdevcscope.desktop DESTINATION ${SERVICES_INSTALL_DIR})

ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}"
-P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)
