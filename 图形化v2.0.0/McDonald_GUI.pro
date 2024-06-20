QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FoodItem.cpp \
    customer.cpp \
    foodbrowser.cpp \
    global.cpp \
    custombuttonbase.cpp \
    hoverfillbutton.cpp \
    hoverfillbuttonbase.cpp \
    loginwindow.cpp \
    main.cpp \
    menubrowser.cpp \
    orderbrowser.cpp

HEADERS += \
    FoodItem.h \
    customer.h \
    foodbrowser.h \
    global.h \
    custombuttonbase.h \
    hoverfillbutton.h \
    hoverfillbuttonbase.h \
    loginwindow.h \
    menubrowser.h \
    orderbrowser.h

FORMS += \
    customer.ui \
    foodbrowser.ui \
    loginwindow.ui \
    menubrowser.ui \
    orderbrowser.ui

TRANSLATIONS += \
    McDonald_GUI_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc \

DISTFILES += \
    button_icon/套餐管理.svg \
    button_icon/套餐管理.svg \
    button_icon/用户管理.svg \
    button_icon/用户管理.svg \
    button_icon/订单管理.svg \
    button_icon/订单管理.svg \
    button_icon/食物管理.svg \
    button_icon/食物管理.svg
