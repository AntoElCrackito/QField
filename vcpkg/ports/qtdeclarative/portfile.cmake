set(SCRIPT_PATH "${CURRENT_INSTALLED_DIR}/share/qtbase")
include("${SCRIPT_PATH}/qt_install_submodule.cmake")

vcpkg_buildpath_length_warning(44)

set(${PORT}_PATCHES "")

set(TOOL_NAMES
       qml
       qmlaotstats
       qmlcachegen
       qmleasing
       qmlformat
       qmlimportscanner
       qmllint
       qmlplugindump
       qmlpreview
       qmlprofiler
       qmlscene
       qmltestrunner
       qmltime
       qmltyperegistrar
       qmldom
       qmltc
       qmlls
       qmljsrootgen
       svgtoqml
   )

qt_install_submodule(PATCHES    ${${PORT}_PATCHES}
                     TOOL_NAMES ${TOOL_NAMES}
                     CONFIGURE_OPTIONS
                        -DFEATURE_quickcontrols2_fusion:BOOL=ON
                        -DFEATURE_quickcontrols2_material:BOOL=ON
                        -DFEATURE_quickcontrols2_imagine:BOOL=OFF
                        -DFEATURE_quickcontrols2_universal:BOOL=OFF
                        -DFEATURE_quickcontrols2_fluentwinui3:BOOL=OFF
                        -DFEATURE_quickcontrols2_macos:BOOL=OFF
                        -DFEATURE_quickcontrols2_ios:BOOL=OFF
                        -DFEATURE_quickcontrols2_windows:BOOL=OFF
                        -DCMAKE_DISABLE_FIND_PACKAGE_LTTngUST:BOOL=ON
                     CONFIGURE_OPTIONS_RELEASE
                     CONFIGURE_OPTIONS_DEBUG
                    )
