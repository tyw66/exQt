###########################################
# tyw66's Qt exercise
###########################################
TEMPLATE = subdirs

CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


SUBDIRS += \
    abc \
    serialize \
#    action  \
#    action1  \
    event  \
    item  \
    language  \
#    model_item  \
    popdown  \
    tree\