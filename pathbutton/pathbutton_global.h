#pragma once

#include <QtGlobal>

#if defined(PATHBUTTON_LIBRARY)
#  define PATHBUTTONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATHBUTTONSHARED_EXPORT Q_DECL_IMPORT
#endif
